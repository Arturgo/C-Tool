#std_require iostream
#require crible_eratosthene cout_vector occtable_to_vector pgcd

int main() {
	cout_vector(occtable_to_vector(crible_eratosthene(100)));
	return 0;
}