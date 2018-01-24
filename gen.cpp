#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template<class Iterator>
vector<int> kmp(Iterator begin, Iterator end);

int main() {
	string test = "ababacba";
	vector<int> k = kmp(test.begin(), test.end());
	
	for(int v : k) {
		cout << v << " ";
		cout << endl;
	}
	return 0;
}

template<class Iterator>
vector<int> kmp(Iterator begin, Iterator end) {
	vector<int> bord;
	bord.push_back(-1);
	
	for(Iterator it = begin;it != end;it++) {
		int cur = bord.back();
		while(cur != -1 && *it != *(begin + cur)) {
			cur = bord[cur];
		}
		bord.push_back(cur + 1);
	}
	
	return bord;
}
