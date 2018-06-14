#std_require vector iostream
#require cartesian_sum range max_value filter is_palindromic

int main() {
  vector<int> three_digits = range<vector<int>>(100, 1000);
  vector<int> product = cartesian_sum(three_digits, three_digits, multiplies<int>());
  vector<int> palindromes = filter(product, is_palindromic_number<int>());
  cout << max_value(palindromes) << endl;
  return 0;
}
