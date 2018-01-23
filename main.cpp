#std_require iostream algorithm
#require cin_vector max_egal donne_ids cout_vector

struct Objet {
	int temps, disp, valeur, id;
	Objet(int _temps = 0, int _disp = 0, int _valeur = 0) {
		temps = _temps;
		disp = _disp;
		valeur = _valeur;
	}
};

istream& operator>>(istream& is, Objet& obj) {
    is >> obj.temps >> obj.disp >> obj.valeur;
    return is;
}

bool compDisp(const Objet &a, const Objet &b) {
	return a.disp < b.disp;
}

int maxValeur[101][2001];

int main() {
	int nbObjets;
	cin >> nbObjets;
	
	vector<Objet> objets = cin_vector<Objet>(nbObjets);
	donne_ids(objets);
	
	sort(objets.begin(), objets.end(), compDisp);
	
	for(int iObjet = nbObjets - 1;iObjet >= 0;iObjet--) {
		for(int iTemps = 0;iTemps <= 2000;iTemps++) {
			max_egal(maxValeur[iObjet][iTemps],
				maxValeur[iObjet + 1][iTemps]);
			if(iTemps + objets[iObjet].temps < objets[iObjet].disp)
				max_egal(maxValeur[iObjet][iTemps],
					maxValeur[iObjet + 1][iTemps + objets[iObjet].temps] + objets[iObjet].valeur);
		}
	}
	
	cout << maxValeur[0][0] << endl;
	
	vector<int> sol;
	
	int temps = 0;
	for(int iObjet = 0;iObjet < nbObjets;iObjet++) {
		if(temps + objets[iObjet].temps < objets[iObjet].disp) {
			if(maxValeur[iObjet + 1][temps + objets[iObjet].temps] + objets[iObjet].valeur > maxValeur[iObjet + 1][temps]) {
				sol.push_back(objets[iObjet].id + 1);
				temps += objets[iObjet].temps;
			}
		}
	}
	
	cout << sol.size() << endl;
	cout_vector(sol, " ");
	cout << endl;
	return 0;
}
