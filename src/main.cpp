#include <iostream>

#include "../include/encryption.hpp"
#include "../include/key_generator.hpp"

void test_encryption() {
  // std::string texto = "abcdefghijklmnopqrstuvwxyz";
  // std::string texto = "abcdef";
  // write_file("original.bin", texto);
  Key_pair keys = initialize_128(100, true);

  encrypt_file("original.txt", "encriptado.txt", keys.pub_key);
  decrypt_file("encriptado.txt", "decriptado.txt", keys.priv_key);

  // print_file("original.bin");
  // print_file("encriptado.bin");
  // print_file("decriptado.bin");
}

int main() {
  using namespace boost::multiprecision;

  test_encryption();
}
