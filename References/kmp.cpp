#std_require vector
template<class Container>
vector<int> kmp(Container container);
#main
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
