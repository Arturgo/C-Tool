#std_require map vector
#require infinity

class interval_compression {
private:
  map<int, int> events;
public:
  interval_compression();
  void add_interval(int begin, int end);
  vector<pair<int, int>> get_intervals(int begin = -INF, int end = INF);
};

#main

interval_compression::interval_compression() {
}

void interval_compression::add_interval(int begin, int end) {
  auto it = events.lower_bound(begin);

  while(it != events.end() && it->first <= end) {
    events.erase(it);
    it = events.lower_bound(begin);
  }

  auto b = events.lower_bound(begin);

  bool shouldBegin = true;
  if(b != events.begin()) {
    b--;
    if(b->second == 1)
      shouldBegin = false;
  }

  if(shouldBegin)
    events[begin] = 1;

  auto f = events.lower_bound(end);
  bool shouldEnd = true;
  if(f != events.end()) {
    if(f->second == -1)
      shouldEnd = false;
  }

  if(shouldEnd)
    events[end] = -1;
}

vector<pair<int, int>> interval_compression::get_intervals(int begin, int end) {
  pair<int, int> cur;
  
  vector<pair<int, int>> res;

  auto begin_it = events.lower_bound(begin);
  
  if(begin_it == events.end())
    return res;

  while(begin_it->second == -1)
    begin_it--;

  auto end_it = events.upper_bound(end);
  if(end_it != events.end())
    end_it++;
  
  auto it = begin_it;
  while(it != end_it) {
    if(it->second == 1) {
      cur.first = max(begin, it->first);
    }
    else {
      cur.second = min(end, it->first);
      if(cur.first != cur.second)
	res.push_back(cur);
    }

    it++;
  }

  return res;
}
  
