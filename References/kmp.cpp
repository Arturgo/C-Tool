#std_require vector
template<class Iterator>
vector<int> kmp(Iterator begin, Iterator end);
#main
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
