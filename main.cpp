#std_require iostream algorithm vector functional
#require cin_vector arc noeud graphe

struct infos {
	int dist;
	infos(int _dist = 0) { dist = _dist; }
};

typedef vector<noeud<bool>> vector_noeuds;
typedef vector<arc<infos>> vector_arcs;

int nbNoeuds;
vector<int> couleurs;

int main() {
	cin >> nbNoeuds;
	
	couleurs = cin_vector<int>(nbNoeuds);
	
	vector_noeuds noeuds;
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		noeuds.push_back(noeud<bool>(iNoeud, false));
	}
	
	vector_arcs arcs;
	for(int iArc = 0;iArc < nbNoeuds - 1;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		arcs.push_back(arc<infos>(deb - 1, fin - 1, infos(
			couleurs[deb - 1] != couleurs[fin - 1]
		)));
	}
	
	graphe<vector_noeuds, vector_arcs> peinture(noeuds, arcs);
	
	
	return 0;
}
