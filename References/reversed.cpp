#std_require algorithm

template<typename Container>
Container reversed(Container container);

#main

template<typename Container>
Container reversed(Container container) {
  reverse(container.begin(), container.end());
  return container;
}
