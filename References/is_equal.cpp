template<typename Param>
class is_equal {
private:
  Param value;
public:
  is_equal(Param _value);
  bool operator ()(const Param& a);
};

#main

template<typename Param>
is_equal<Param>::is_equal(Param _value) {
  value = _value;
}

template<typename Param>
bool is_equal<Param>::operator ()(const Param &a) {
  return a == value;
}
