#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template<class Container>
vector<int> kmp(Container container);

int main() {
	string test = "ababacba";
	vector<int> k = kmp(test);
	
	for(int v : k) {
		cout << v << " ";
		cout << endl;
	}
	return 0;
}

template<class Container>
vector<int> kmp(Container container) {
	vector<int> bord;
	bord.push_back(-1);
	
	for(int pos = 0;pos < (int)container.size();pos++) {
		int cur = bord.back();
		while(cur != -1 && container[pos] != container[cur]) {
			cur = bord[cur];
		}
		bord.push_back(cur + 1);
	}
	
	return bord;
}
