template<class T>
T pgcd(T a, T b);
#main
template<class T>
T pgcd(T a, T b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}
