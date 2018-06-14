#std_require vector iostream
#require prime_table table_to_container

int main() {
  vector<bool> table = prime_table<vector<bool>>(4000000);
  vector<int> primes = table_to_container<vector<int>>(table);
  cout << primes[10000]  << endl;
  return 0;
}
