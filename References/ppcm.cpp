#require pgcd
template<class T> 
T ppcm(T a, T b);
#main
template<class T>
T ppcm(T a, T b) {
	return a / pgcd(a, b) * b;
}