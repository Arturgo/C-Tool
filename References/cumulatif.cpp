#std_require vector
template<class T>
vector<T> cumulatif(vector<T> elems);
#main
template<class T>
vector<T> cumulatif(vector<T> elems) {
	vector<T> res;
	res.push_back(0);

	for(T elem : elems) {
		res.push_back(res.back() + elem);
	}

	return res;
}