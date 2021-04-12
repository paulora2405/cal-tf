#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

#include "../include/brute_force.hpp"
#include "../include/encryption.hpp"
#include "../include/key_generator.hpp"

int main() {
  Key_pair keys = generate_keys(256, true);
  encrypt_file("original.txt", "encriptado.txt", keys.pub_key);
  decrypt_file("encriptado.txt", "decriptado.txt", keys.priv_key);
}
