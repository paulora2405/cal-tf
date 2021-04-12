#include "../include/brute_force.hpp"

big_int sub_abs(const big_int &x, const big_int &y) {
  return (x > y) * (x - y) + !(x > y) * (y - x);
}

big_int naive_factorization(const big_int &n) {
  big_int i, n_sq = boost::multiprecision::sqrt(n);

  for(i = 2; i < n_sq; i++) {
    if(n % i == 0) return i;
  }
  return n;
}

big_int pollard_algorithm(const big_int &n) {
  big_int d = 1, i = 0, k = 2, x = 3, y = 3;

  while(++i) {
    x = (x * x) % n;
    x += n - 1;
    x = x % n;
    d = gcd_iter(sub_abs(x, y), n);

    if(d != 1 && d != n) return d;
    if(i == k) {
      y = x;
      k <<= 1;
    }
  }
  return n;
}

big_int brute_force_key(const big_int &e, const big_int &n, bool naive) {
  big_int p, q, tot, d, y;

  if(naive)
    p = naive_factorization(n);
  else
    p = pollard_algorithm(n);

  q = n / p;
  tot = (p - 1) * (q - 1);
  euclides_extended(e, tot, d, y);
  d = (d % tot + tot) % tot;

  return d;
}
