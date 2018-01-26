#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
vector<T> cin_vector(int nbElems);
template<class Infos>
struct arc {
	int deb, fin;
	Infos infos;
	arc(int _deb, int _fin, Infos _infos);
	arc();
};
template<class Infos>
struct noeud {
	int id;
	Infos infos;
	noeud(int _id, Infos _infos);
	noeud();
};
template<class NoeudContainer, class ArcContainer>
struct graphe {
	NoeudContainer noeuds;
	ArcContainer arcs;
	graphe(NoeudContainer _noeuds, ArcContainer _arcs);
	graphe();
};

struct infos {
	int dist;
	infos(int _dist = 0) { dist = _dist; }
};

int nbNoeuds;
vector<int> couleurs;

typedef vector<noeud<bool>> vector_noeuds;
typedef vector<arc<infos>> vector_arcs;

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

template<class T>
vector<T> cin_vector(int nbElems) {
	vector<T> res;
	for(int iElem = 0;iElem < nbElems;iElem++) {
		T elem;
		cin >> elem;
		res.push_back(elem);
	}
	return res;
}
template<class Infos>
arc<Infos>::arc(int _deb, int _fin, Infos _infos) {
	deb = _deb;
	fin = _fin;
	infos = _infos;
}
template<class Infos>
arc<Infos>::arc() {}
template<class Infos>
noeud<Infos>::noeud(int _id, Infos _infos) {
	id = _id;
	infos = _infos;
}
template<class Infos>
noeud<Infos>::noeud() {}
template<class NoeudContainer, class ArcContainer>
graphe<NoeudContainer, ArcContainer>::graphe(NoeudContainer _noeuds, ArcContainer _arcs) {
	noeuds = _noeuds;
	arcs = _arcs;
}
template<class NoeudContainer, class ArcContainer>
graphe<NoeudContainer, ArcContainer>::graphe() {}
