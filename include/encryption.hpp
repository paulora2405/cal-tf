#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "big_int_type.hpp"
#include "key_generator.hpp"
#include "mod_exponentiation.hpp"

unsigned log_b(big_int n);

big_int text_to_numeric(const std::string &str);

std::string numeric_to_text(big_int num);

std::string hash_numeric(big_int num);

big_int unhash_text(const std::string &str);

/*
 * Data manipulation algorithm.
 */
void data_manipulation(std::string src_path, std::string dst_path, Key key);

/*
 * Encrypts a source file to a destination file.
 */
void encrypt_file(std::string src_path, std::string dst_path, Key pub_key);

/*
 * Decrypts a source file to a destination file.
 */
void decrypt_file(std::string src_path, std::string dst_path, Key priv_key);

#endif