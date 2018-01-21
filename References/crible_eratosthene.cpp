#std_require vector
vector<bool> crible_eratosthene(int borneSup);
#main
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