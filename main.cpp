#std_require cstdio iostream
#require interval_compression interval_complement

const int MOD = 998244353;
interval_compression intervals[200*1000];

long long sommes[(1 << 19)];
pair<long long, long long> fonctions[(1 << 19)];

void push(int n, int np, int d, int f) {
  sommes[np] = (fonctions[n].first * sommes[np] + fonctions[n].second * (f - d)) % MOD;
  fonctions[np] = {(fonctions[n].first * fonctions[np].first) % MOD, (fonctions[n].first * fonctions[np].second + fonctions[n].second) % MOD};
}
void applique(int deb, int fin, pair<long long, long long> func, int n = 1, int d = 0, int f = (1 << 18)) {
  if(deb >= f || d >= fin)
    return;

  int m = (d + f) / 2;
  if(n < (1 << 18)) {
    push(n, 2*n, d, m);
    push(n, 2*n+1, m, f);
    fonctions[n] = {1, 0};
    sommes[n] = (sommes[2 * n] + sommes[2 * n + 1]) % MOD;
  }
  
  if(deb <= d && f <= fin) {
    fonctions[n] = func;
    sommes[n] = func.first * sommes[n] + func.second * (f - d);
    return;
  }

  applique(deb, fin, func, 2 * n, d, m);
  applique(deb, fin, func, 2 * n + 1, m, f);

  sommes[n] = (sommes[2 * n] + sommes[2 * n + 1]) % MOD;
}

int sommeEntre(int deb, int fin, int n = 1, int d = 0, int f = (1 << 18)) {
  if(deb >= f || d >= fin)
    return 0;

  int m = (d + f) / 2;
  if(n < (1 << 18)) {
    push(n, 2*n, d, m);
    push(n, 2*n+1, m, f);
    fonctions[n] = {1, 0};
    sommes[n] = (sommes[2*n] + sommes[2*n+1]) % MOD;
  }

  if(deb <= d && f <= fin) {
    return sommes[n];
  }

  int somme = sommeEntre(deb, fin, 2 * n, d, m) + sommeEntre(deb, fin, 2 * n + 1, m, f);
  return somme % MOD;
}

int main() {
  int nbSlots, nbReqs;
  scanf("%d%d", &nbSlots, &nbReqs);

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int type, deb, fin;
    scanf("%d%d%d", &type, &deb, &fin);

    if(type == 1) {
      int arg;
      scanf("%d", &arg);
      arg--;

      vector<pair<int, int>> arg_present = intervals[arg].get_intervals(deb - 1, fin);
      for(pair<int, int> present : arg_present) {
        applique(present.first, present.second, {2, 0});
      }

      vector<pair<int, int>> arg_absent = interval_complement(arg_present, deb - 1, fin);
      for(pair<int, int> absent : arg_absent) {
	applique(absent.first, absent.second, {1, 1});
      }
      
      intervals[arg].add_interval(deb - 1, fin);
    }
    else {
      printf("%d\n", sommeEntre(deb - 1, fin));
    }
  }
  return 0;
}
