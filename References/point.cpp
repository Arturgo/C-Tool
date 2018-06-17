#std_require cmath

template<typename Type>
class point {
public:
  Type x, y;
  point(Type _x = 0, Type _y = 0);
};

template<typename Type>
point<Type> operator + (const point<Type> &a, const point<Type> &b);

template<typename Type>
point<Type> operator - (const point<Type> &a, const point<Type> &b);

template<typename Type>
point<Type> operator * (const Type &a, const point<Type> &b);

template<typename Type>
Type operator * (const point<Type> &a, const point<Type> &b);

template<typename Type>
Type operator ^ (const point<Type> &a, const point<Type> &b);

template<typename Type>
long double operator ! (const point<Type> &a);

#main

template<typename Type>
point<Type> operator + (const point<Type> &a, const point<Type> &b) {
  return point<Type>(a.x + b.x, a.y + b.y);
}

template<typename Type>
point<Type> operator - (const point<Type> &a, const point<Type> &b) {
  return point<Type>(a.x - b.x, a.y - b.y);
}

template<typename Type>
point<Type> operator * (const Type &a, const point<Type> &b) {
  return point<Type>(a * b.x, a * b.y);
}

template<typename Type>
Type operator * (const point<Type> &a, const point<Type> &b) {
  return a.x * b.x + a.y * b.y;
}

template<typename Type>
Type operator ^ (const point<Type> &a, const point<Type> &b) {
  return a.x * b.y - a.y * b.x;
}

template<typename Type>
long double operator ! (const point<Type> &a) {
  return sqrt(a * a);
}

template<typename Type>
point<Type>::point(Type _x, Type _y) {
  x = _x;
  y = _y;
}

