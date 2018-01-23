#std_require iostream vector
template<class T>
vector<T> cin_vector(int nbElems);
#main
template<class T>
vector<T> cin_vector(int nbElems) {
	vector<T> res;
	for(int iElem = 0;iElem < nbElems;iElem++) {
		T elem;
		cin >> elem;
		res.push_back(elem);
	}
	return res;
}
