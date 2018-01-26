template<class Infos>
struct noeud {
	int id;
	Infos infos;
	noeud(int _id, Infos _infos);
	noeud();
};
#main
template<class Infos>
noeud<Infos>::noeud(int _id, Infos _infos) {
	id = _id;
	infos = _infos;
}
template<class Infos>
noeud<Infos>::noeud() {}
