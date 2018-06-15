long long safe_mod(long long a, long long mod);

#main

long long safe_mod(long long a, long long mod) {
  return ((a % mod) + mod) % mod;
}
