#ifndef TESTS_HPP
#define TESTS_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include <fstream>
#include <iostream>

#include "brute_force.hpp"
#include "encryption.hpp"
#include "key_generator.hpp"

void brute_time_csv(int init, int size, int rep, bool naive);

void key_gen_csv(int init, int size, int rep);

void encryption_time_csv(int init, int size, int rep);

void decryption_time_csv(int init, int size, int rep);

#endif