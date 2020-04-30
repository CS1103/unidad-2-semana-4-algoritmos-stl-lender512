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
		vector<int>::iterator it;
		do {
			std::prev_permutation(train.begin(), train.end());
			it = is_sorted_until(train.begin(), train.end());
			c++;
		} while (it != train.end());
		cout << "Optimal train swapping takes " << c << " swaps. \n";
		c = 0;
	} 
}
		

void ejercico482() {

}

int main() {
	ejercicio299();
}
