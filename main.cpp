#std_require vector iostream algorithm string
#require read_container print_container apply add signature

int main() {
  ios_base::sync_with_stdio(false);
  auto permutation = read_container<vector<int>>();
  permutation = apply<vector<int>>(permutation, add<int>(-1));

  int sign = signature(permutation);
  if(permutation.size() % 2 == 0) {
    if(sign == 1)
      cout << "Petr" << endl;
    else
      cout << "Um_nik" << endl;
  }
  else {
    if(sign == 1)
      cout << "Um_nik" << endl;
    else
      cout << "Petr" << endl;
  }
  
  return 0;
}
