#std_require iostream algorithm vector functional
#require kmp

int main() {
	string test = "ababacba";
	vector<int> k = kmp(test);
	
	for(int v : k) {
		cout << v << " ";
		cout << endl;
	}
	return 0;
}
