#std_require vector
template<class D, class F>
vector<F> change_type_vector(vector<D> elems);
#main
template<class D, class F>
vector<F> change_type_vector(vector<D> elems) {
	vector<F> res;

	for(D elem : elems) {
		res.push_back(elem);
	}

	return res;
}