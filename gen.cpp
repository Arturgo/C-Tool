#include <iostream>
#include <vector>
using namespace std;

template<class D, class F>
vector<F> change_type_vector(vector<D> elems);
template<class T>
void cout_vector(vector<T> v, string separator = "\n");
vector<bool> crible_eratosthene(int borneSup);
template<class T>
vector<T> cumulatif(vector<T> elems);
int main() {
	cout_vector(cumulatif<int>(
		change_type_vector<bool, int>(crible_eratosthene(100))
	));
	return 0;
}

template<class D, class F>
vector<F> change_type_vector(vector<D> elems) {
	vector<F> res;

	for(D elem : elems) {
		res.push_back(elem);
	}

	return res;
}
template<class T>
void cout_vector(vector<T> v, string separator) {
	for(T elem : v) {
		cout << elem << separator;
	}	
}
vector<bool> crible_eratosthene(int borneSup) {
	vector<bool> estPremier(borneSup, true);
	if(borneSup > 0) estPremier[0] = false;
	if(borneSup > 1) estPremier[1] = false;

	for(int nombre = 2;nombre * nombre < borneSup;nombre++) {
		if(!estPremier[nombre])
			continue;
		for(int mult = nombre * nombre;mult < borneSup;mult += nombre) {
			estPremier[mult] = false;
		}
	}

	return estPremier;
}
template<class T>
vector<T> cumulatif(vector<T> elems) {
	vector<T> res;
	res.push_back(0);

	for(T elem : elems) {
		res.push_back(res.back() + elem);
	}

	return res;
}
