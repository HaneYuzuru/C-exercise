#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct word{
	char data[100];
	int number;
};												//for sort

void function1(char* filename);
bool Operator(char[]);
void function2(char* filename);
void sort(word wl[], int count, int(*comp)(const word& lhs, const word& rhs));
void sort(word s[], int start, int end);
int Partition(word s[], int p, int q, int(*comp)(const word& lhs, const word& rhs));
void swap(word* a, word* b);
int compWord(const word& lhs, const word& rhs);

int main(int argc, char *argv[]){
	if (argc != 2){
		cout << "Bad input!" << endl;
		exit(1);
	}					                         //if argc is not 2, exit

	function1(argv[1]);
	function2("131250064_1.txt");

	return 1;
}

//read the data from test.txt file and uncode the file
void function1(char* filename){
	ifstream fin(filename);
	ofstream fout("131250064_1.txt");
	if (!fin){
		cout << "Open the file is failed!" << endl;
		exit(1);								//file is failed to be opened
	}
	char str[100];								//a temp space to store the read word
	char lastnext = NULL;
	char next = NULL;
	while (true){
		if (fin.eof()){
			break;								//if file is end, then break the loop;
		}
		fin >> str;
		next = NULL;
		fin.get(next);							//get the separator
		bool result = Operator(str);
		if (fout){
			//if the word fits the rule and its length after being decoded is not zero
			if (result && strlen(str)){
				if (next == '\n' || next == ' ' || next == '\0'){
					if (lastnext != NULL && lastnext != '\n'){
						fout << lastnext << str;
					}
					else{
						fout << str;
					}
					lastnext = next;
				}
				else{
					fin.putback(next);
				}
			}
			else{
				if (lastnext == '\n'){
					lastnext = NULL;
				}
			}
			if (next == '\n'){
				fout << '\n';
				fin.get(next);
				//see if this is an empty line
				if (next == '\n'){
					fout << '\n';
				}
				else{
					fin.putback(next);
				}
				lastnext = '\n';
			}
		}
	}
	fin.close();
}

//To check if the char[] is proper to the rule
bool Operator(char str[]){
	bool proper = true;
	for (int i = 0; str[i] != '\0'; i++){
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != '-' && str[i] != '+' && str[i] != '*' && str[i] != ' '){
			proper = false;						//it's not proper
			return proper;
		}
	}
	for (int j = 0; str[j] != '\0'; j++){
		if (str[j] == '*'){
			str[j] = 's';
		}
		else if (str[j] == '+'){
			for (int s = j; str[s] != '\0'; s++){
				str[s] = str[s + 1];
			}
		}
		else if (str[j] == '-'){
			str[j] = '\0';
			for (int k = 0; str[k] != '\0'; k++){
				char tobemi = str[k];
				for (int s = j + 1; str[s] != '\0'; s++){
					char tomi = str[s];
					if (str[k] == str[s]){
						for (int l = k; str[l] != '\0'; l++){
							str[l] = str[l + 1];
						}
						k--;							//since the alphabet is removed ,k reduce one
					}
				}
			}
		}
		else if (str[j] >= 'A' && str[j] <= 'Z'){
			str[j] = str[j] - ('A' - 'a');
		}
	}
	return proper;
}

//read data from 131250064_1.txt and write the word by frequency
void function2(char* filename){
	ifstream fin2(filename);
	ofstream fout2("131250064_2.txt");
	char str[100];
	word wordlist[100];
	int count = 0;
	if (!fin2){
		cout << "Open the file is failed!" << endl;
		exit(1);								//file is failed to be opened
	}
	while (true){
		if (fin2.eof()){
			break;
		}										//if file is end then break the loop.Note that since the last word is read will be '\0',we use "count-1" in the sort function after
		bool find = false;

		fin2 >> str;
		for (int i = 0; i != count; i++){
			if (!strcmp(str, wordlist[i].data)){//find the same word in the wordlist
				find = true;
				wordlist[i].number++;			//only plus the respected number of the word
				break;
			}
		}
		if (!find){								//if the word does not exist in the wordlist,then add the word into the wordlist and set the number of the word to 1
			word newWord;
			int c = 0;
			for (; str[c] != '\0'; c++){
				*(newWord.data + c) = str[c];
			}
			*(newWord.data + c) = str[c];
			newWord.number = 1;
			wordlist[count] = newWord;
			count++;
		}
	}
	count--;
	sort(wordlist, count, compWord);			//use the bubble sort
	//sort(wordlist, 0, count - 1);				//use the quicksort

	//print the result to the file
	for (int s = 0; s != count - 1; s++){
		fout2 << wordlist[s].data << ' ' << wordlist[s].number << endl;
	}
	fout2 << wordlist[count - 1].data << ' ' << wordlist[count - 1].number;			// the last output should not print a newline
	fout2.close();
}

//bubble sort
void sort(word wl[], int count, int(*comp)(const word& lhs, const word& rhs)){
	bool changed = false;						
	for (int i = 1; i != count-1; i++){
		changed = false;
		for (int j = 0; j != count - i; j++){
			if (comp(wl[j], wl[j+1]) < 0){
				changed = true;
				word tempWord = wl[j];
				wl[j] = wl[j + 1];
				wl[j + 1] = tempWord;
			}
		}
		if (!changed){
			break;					//if in one circle no element is moved then the given sequence has already been sorted
		}
	}
}

//quicksort
void sort(word s[], int start, int end){
	if (start < end){
		int r = Partition(s, start, end, compWord);
		sort(s, start, r - 1);
		sort(s, r + 1, end);
	}
}

//Partition in the quick sort
int Partition(word s[], int p, int q, int(*comp)(const word& lhs, const word& rhs)){		//sort between s[p] and s[q]
	word x = s[p];			//pivot s[p]
	int i = p;
	for (int j = p + 1; j != q + 1; j++){
		if (comp(s[j], x) > 0){
			i = i + 1;
			swap(s[i], s[j]);
		}
	}
	swap(s[i], s[p]);
	return i;
}

//swap two words
void swap(word* a, word* b){
	word temp = *a;
	a = b;
	*b = temp;
}

//compare two words according to number then their data
int compWord(const word& lhs, const word& rhs){
	if (lhs.number != rhs.number){
		return lhs.number - rhs.number;
	}
	else{
		return strcmp(rhs.data, lhs.data);
	}
}