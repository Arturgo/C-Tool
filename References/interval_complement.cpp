#std_require vector
#require infinity

vector<pair<int, int>> interval_complement(const vector<pair<int, int>>& intervals, int begin = -INF, int end = INF) {
  if(intervals.empty()) {
    return {make_pair(begin, end)};
  }

  vector<pair<int, int>> res;
  if(begin != intervals[0].first)
    res.push_back({begin, intervals[0].first});

  for(size_t iInter = 0;iInter < intervals.size() - 1;iInter++)
    res.push_back({intervals[iInter].second, intervals[iInter + 1].first});

  if(end != intervals.back().second)
    res.push_back({intervals.back().second, end});

  return res;
}
