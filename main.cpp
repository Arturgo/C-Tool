#std_require iostream
#require modular_inverse

int main() {
  long long a, mod;
  cin >> a >> mod;
  cout << modular_inverse(a, mod) << endl;
  return 0;
}
