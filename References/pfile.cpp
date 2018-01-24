#std_require deque functional

template<class T, class Compare>
struct pfile {
	size_t debId, finId;
	deque<pair<T, size_t>> elems;
	Compare comp;
	
	pfile();
	void push_back(T elem);
	void pop_front();
	T top();
	size_t size();
};

#main
template<class T, class Compare>
pfile<T, Compare>::pfile() {
	debId = finId = 0;
	comp = Compare();
}

template<class T, class Compare>
void pfile<T, Compare>::push_back(T elem) {
	while(!elems.empty() && comp(elem, elems.back().first)) {
		elems.pop_back();
	}
	elems.push_back({elem, finId++});
}

template<class T, class Compare>
T pfile<T, Compare>::top() {
	return elems.front().first;
}

template<class T, class Compare>
size_t pfile<T, Compare>::size() {
	return finId - debId;
}

template<class T, class Compare>
void pfile<T, Compare>::pop_front() {
	if(elems.front().second == debId)
		elems.pop_front();
	debId++;
	finId = max(finId, debId);
}
