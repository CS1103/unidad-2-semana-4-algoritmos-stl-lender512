#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;


void ejercicio146() {
	vector<string> a;
	string input;
	while (1) {
		cin >> input;
		if (input == "#") { break; }
		a.push_back(input);
	}

	for (auto sr : a) {
		if (next_permutation(sr.begin(), sr.end())) {
			cout << sr << endl;
		}
		else {
			cout << "No Successor \n";
		}
	}
}

void ejercicio299() {
	int n;
	cin >> n;
	int l;
	vector<vector<int>> trains (n);
	for (int i = 0; i < n; i++) {
		cin >> l;
		trains[i].resize(l);
		for (int j = 0; j < l; j++) {
			cin >> trains[i][j];
		}
	}
	int c= 0;
	for (auto train : trains) {
		bool swap = false;
		while (!swap) {
			swap = true;
			for (int i = 0; i < train.size() - 1; i++) {
				if (train[i] > train[i + 1]) {
					swap = false;
					auto temp = train[i + 1];
					train[i + 1] = train[i];
					train[i] = temp;
					c++;
				}
			}
		}
		cout << c <<" swaps needed \n";
		c = 0;
	} 
}

template<typename T>
void ordenar(vector<int> indices, vector<T> n) {
	bool swap = false;
	while (!swap) {
		swap = true;
		for (int i = 0; i < indices.size() - 1; i++) {
			if (indices[i] > indices[i + 1]) {
				swap = false;
				auto temp1 = indices[i + 1];
				indices[i + 1] = indices[i];
				indices[i] = temp1;
				auto temp2 = n[i + 1];
				n[i + 1] = n[i];
				n[i] = temp2;
			}
		}
	}
}

void ejercicio482() {
	int n;
	cin >> n;

	string str1;
	string str2;

	vector<vector<int>> indices(n);
	vector<vector<string>> numeros(n);

	for (int i = 0; i < n; i++) {
		cin.ignore();
		getline(cin, str1);
		getline(cin, str2);
		string str = "";
		for (auto c: str1) {
			if (c != ' ') {
				str += c;
			}
			else if (c == ' ') {
				indices[i].push_back(stoi(str));
				str = "";
			}
		}
		indices[i].push_back(stoi(str));
		string temp = "";
		for (auto c : str2) {
			if (c != ' ') {
				temp += c;
			}
			else if (c == ' '){
				numeros[i].push_back(temp);
				temp = "" ;
			}
		}
		numeros[i].push_back(temp);
		ordenar(indices[i], numeros[i]);
		vector<string>::iterator it = numeros[i].end();
		while (it != numeros[i].begin()) {
			it--;
			cout << *it << endl;
		}
	}
}

int score(string s) {
	int score = 0;
	while (prev_permutation(s.begin(), s.end())) {
		score++;
	}
	return score;
}

void ejercicio612() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl;
		int size;
		int cols;
		cin >> size;
		cin >> cols;
		vector<string> vec(cols);
		for (int j = 0; j < cols; j++) {
			cin >> vec[j];
		}
		bool swap = false;
		while (!swap) {
			swap = true;
			for (int i = 0; i < vec.size() - 1; i++) {
				if (score(vec[i]) >= score(vec[i + 1])) {
					swap = false;
					auto temp = vec[i + 1];
					vec[i + 1] = vec[i];
					vec[i] = temp;
				}
			}
		}
		cout << "------------\n";
		for (auto s : vec) cout << s << endl;
	}
	/* info para test case:
	1

	10 6
	AACATGAAGG
	TTTTGGCCAA
	TTTGGCCAAA
	GATCAGATTT
	CCCGGGGGGA
	ATCGATGCAT

	output:
	CCCGGGGGGA
	AACATGAAGG
	GATCAGATTT
	ATCGATGCAT
	TTTTGGCCAA
	TTTGGCCAAA
	*/
}

int main() {
	ejercicio612();
}
