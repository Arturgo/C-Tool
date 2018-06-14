#std_require vector iostream
#require sum print filter range fibonacci key_set prime_decomposition value_set max_value

int main() {
  cout << max_value(key_set<vector<int>>(prime_decomposition<vector<pair<long long, int>>>(600851475143ll))) << endl;
  return 0;
}
