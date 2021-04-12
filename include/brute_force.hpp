#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP

#include <boost/multiprecision/cpp_int.hpp>

#include "big_int_type.hpp"
#include "euclidean.hpp"
#include "mod_exponentiation.hpp"

big_int sub_abs(const big_int &x, const big_int &y);

big_int naive_factorization(const big_int &n);

big_int pollard_algorithm(const big_int &n);

big_int brute_force_key(const big_int &e, const big_int &n, bool naive = false);

#endif
