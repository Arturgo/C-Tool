#std_require iostream
#require change_type_vector cumulatif crible_eratosthene cout_vector
int main() {
	cout_vector(cumulatif<int>(
		change_type_vector<bool, int>(crible_eratosthene(100))
	));
	return 0;
}