template<class T>
void max_egal(T& a, const T& b);
#main
template<class T>
void max_egal(T& a, const T& b) {
	if(a < b) {
		a = b;
	}
}
