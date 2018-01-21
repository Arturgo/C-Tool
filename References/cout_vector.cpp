#std_require vector iostream
template<class T>
void cout_vector(vector<T> v, string separator = "\n");
#main
template<class T>
void cout_vector(vector<T> v, string separator) {
	for(T elem : v) {
		cout << elem << separator;
	}	
}
