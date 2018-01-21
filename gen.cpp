#include <iostream>
#include <vector>
using namespace std;

template<class T>
void cout_vector(vector<T> v, string separator = "\n");
vector<bool> crible_eratosthene(int borneSup);
template<class T>
vector<int> occtable_to_vector(vector<T> elems);
template<class T>
T pgcd(T a, T b);

int main() {
	cout_vector(occtable_to_vector(crible_eratosthene(100)));
	return 0;
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
vector<int> occtable_to_vector(vector<T> elems) {
	vector<int> res;
	
	for(int val = 0;val < (int)elems.size();val++) {
		for(T fois = 0;fois < elems[val];fois++) {
			res.push_back(val);
		}
	}
	
	return res;
}
template<class T>
T pgcd(T a, T b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}
