#include "../include/encryption.hpp"

unsigned log_b(big_int n) {
  unsigned b{0};
  while(n) {
    n >>= 1;
    b++;
  }
  return b;
}

big_int text_to_numeric(const std::string &str) {
  big_int num{0};
  unsigned e{0};
  for(char c : str) {
    num += c * (big_int(1)) << (e++ * 8);
  }
  return num;
}

std::string numeric_to_text(big_int num) {
  std::string str;
  while(num) {
    str += (char)(num & 255);
    num >>= 8;
  }
  return str;
}

std::string hash_numeric(big_int num) {
  std::string str;
  while(num) {
    str += '0' + (char)(num & 31);
    num >>= 5;
  }
  return str;
}

big_int unhash_text(const std::string &str) {
  big_int num{0};
  unsigned e{0};
  for(auto c : str) {
    num += (c - '0') * (big_int(1)) << (e++ * 5);
  }
  return num;
}

void encrypt_file(std::string src_path, std::string dst_path, Key pub_key) {
  std::ifstream src(src_path);
  if(!src.is_open()) {
    std::cerr << "Arquivo não pode ser aberto com sucesso" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::ofstream dst(dst_path);
  if(!dst.is_open()) {
    std::cerr << "Arquivo não pode ser aberto com sucesso" << std::endl;
    exit(EXIT_FAILURE);
  }

  const unsigned BLOCK_SIZE = (log_b(pub_key.n) / 8) - 1;
  unsigned bytes_read;
  big_int m;
  char *buffer = new char[BLOCK_SIZE];

  while((bytes_read = src.readsome(buffer, BLOCK_SIZE)) == BLOCK_SIZE) {
    m = text_to_numeric(buffer);
    m = mod_pow(m, pub_key.d_e, pub_key.n);
    dst << hash_numeric(m) << std::endl;
  }
  if(bytes_read) {
    char *last_buffer = new char[bytes_read];
    std::strncpy(last_buffer, buffer, bytes_read);
    m = text_to_numeric(last_buffer);
    m = mod_pow(m, pub_key.d_e, pub_key.n);
    dst << hash_numeric(m) << std::endl;
    delete[] last_buffer;
  }
  delete[] buffer;
}

void decrypt_file(std::string src_path, std::string dst_path, Key priv_key) {
  std::ifstream src(src_path);
  if(!src.is_open()) {
    std::cerr << "Arquivo não pode ser aberto com sucesso" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::ofstream dst(dst_path);
  if(!dst.is_open()) {
    std::cerr << "Arquivo não pode ser aberto com sucesso" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string v;
  big_int m;

  while(src >> v) {
    m = unhash_text(v);
    m = mod_pow(m, priv_key.d_e, priv_key.n);
    dst << numeric_to_text(m);
  }
}
