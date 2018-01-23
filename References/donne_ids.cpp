#std_require vector
template<class T>
void donne_ids(vector<T>& elems);
#main
template<class T>
void donne_ids(vector<T>& elems) {
	for(int iElem = 0;iElem < (int)elems.size();iElem++) {
		elems[iElem].id = iElem;
	}
}
