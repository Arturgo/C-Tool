template<class NoeudContainer, class ArcContainer>
struct graphe {
	NoeudContainer noeuds;
	ArcContainer arcs;
	graphe(NoeudContainer _noeuds, ArcContainer _arcs);
	graphe();
};
#main
template<class NoeudContainer, class ArcContainer>
graphe<NoeudContainer, ArcContainer>::graphe(NoeudContainer _noeuds, ArcContainer _arcs) {
	noeuds = _noeuds;
	arcs = _arcs;
}
template<class NoeudContainer, class ArcContainer>
graphe<NoeudContainer, ArcContainer>::graphe() {}
