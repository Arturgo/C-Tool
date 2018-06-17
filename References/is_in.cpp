#require intersects

template<typename Point, typename Polygon>
bool is_in(const Point &a, const Polygon &b, long long sizeS = 2000 * 1000 * 1000);

#main

template<typename Point, typename Polygon>
bool is_in(const Point &a, const Polygon &b, long long sizeS) {
  pair<Point, Point> segment = make_pair(a, a + Point(1, sizeS));

  int count = 0;

  for(int c = 0;c < (int)b.size();c++) {
    int n = (c + 1) % b.size();
    if(intersects(segment, make_pair(b[c], b[n]))) {
      count++;
    }
  }

  if(count % 2 == 0)
    return false;
  return true;
}
