template<class Infos>
struct arc {
	int deb, fin;
	Infos infos;
	arc(int _deb, int _fin, Infos _infos);
	arc();
};
#main
template<class Infos>
arc<Infos>::arc(int _deb, int _fin, Infos _infos) {
	deb = _deb;
	fin = _fin;
	infos = _infos;
}
template<class Infos>
arc<Infos>::arc() {}
