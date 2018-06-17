#require sign

template<typename Segment>
bool intersects(const Segment &a, const Segment &b);

#main

template<typename Segment>
bool intersects(const Segment &a, const Segment &b) {
  return sign((a.second - a.first) ^ (b.first - a.first)) != sign((a.second - a.first) ^ (b.second - a.first)) && sign((b.second - b.first) ^ (a.first - b.first)) != sign((b.second - b.first) ^ (a.second - b.first));
}
