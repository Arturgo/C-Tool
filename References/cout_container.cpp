#std_require vector iostream
template<class Container>
void cout_container(Container v, string separator = "\n");
#main
template<class Container>
void cout_container(Container v, string separator) {
	for(auto elem : v) {
		cout << elem << separator;
	}	
}
