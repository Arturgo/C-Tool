#std_require vector iostream algorithm string
#require is_palindromic subsequence

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);

  size_t maxSize = 0;
  for(size_t begin = 0;begin < s.size();begin++) {
    for(size_t end = begin + 1;end <= s.size();end++) {
      if(!is_palindromic_sequence(subsequence(s, begin, end))) {
	maxSize = max(maxSize, end - begin);
      }
    }
  }

  cout << maxSize << endl;
  
  return 0;
}
