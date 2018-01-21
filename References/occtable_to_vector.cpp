#std_require vector
template<class T>
vector<int> occtable_to_vector(vector<T> elems);
#main
template<class T>
vector<int> occtable_to_vector(vector<T> elems) {
	vector<int> res;
	
	for(int val = 0;val < (int)elems.size();val++) {
		for(T fois = 0;fois < elems[val];fois++) {
			res.push_back(val);
		}
	}
	
	return res;
}
