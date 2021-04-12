#include "../include/tests.hpp"

void brute_time_csv(int init, int size, int rep, bool naive) {
  big_int d_brute;

  std::ofstream ws("brute.csv");

  ws << "REP,SIZE,AVG(ms)" << std::endl;
  for(int j = init; j <= size; j++) {
    double time = 0;

    std::cout << "\n**key_size=" << j << "**" << std::endl;
    for(int i = 0; i < rep; i++) {
      Key_pair keys = generate_keys(j, false);

      auto start = std::chrono::high_resolution_clock::now();

      if(naive)
        d_brute = brute_force_key(keys.pub_key.d_e, keys.pub_key.n, true);
      else
        d_brute = brute_force_key(keys.pub_key.d_e, keys.pub_key.n);

      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      time += duration.count();

      std::cout << '.' << std::flush;
      if(keys.priv_key.d_e != d_brute) {
        std::cout << "  D diferente";
      }
    }
    std::cout << std::endl;
    ws << rep << ',' << j << ',' << time / rep << std::endl;
  }

  ws.close();
}

void key_gen_csv(int init, int size, int rep) {
  std::ofstream ws("key_gen.csv");
  ws << "Repetitions,Key Size(Bits),AVG(ms)" << std::endl;

  for(int j = init; j <= size; j += 8) {
    double time = 0;

    std::cout << "\n**key_size=" << j << "**" << std::endl;

    for(int i = 0; i < rep; i++) {
      auto start = std::chrono::high_resolution_clock::now();

      Key_pair keys = generate_keys(j, false);
      keys.priv_key.d_e++;

      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      time += duration.count();
      std::cout << '.' << std::flush;
    }
    ws << rep << ',' << j << ',' << time / rep << std::endl;
  }

  ws.close();
}

void encryption_time_csv(int init, int size, int rep) {
  std::ofstream ws("encryption.csv");
  ws << "Repetitions,Key Size(Bits),AVG(ms)" << std::endl;

  for(int j = init; j <= size; j += 8) {
    double time = 0;

    std::cout << "\n**key_size=" << j << "**" << std::endl;

    for(int i = 0; i < rep; i++) {
      Key_pair keys = generate_keys(j, false);

      auto start = std::chrono::high_resolution_clock::now();

      encrypt_file("original.txt", "encriptado.txt", keys.pub_key);

      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      time += duration.count();
      std::cout << '.' << std::flush;
    }
    ws << rep << ',' << j << ',' << time / rep << std::endl;
  }

  ws.close();
}

void decryption_time_csv(int init, int size, int rep) {
  std::ofstream ws("decryption.csv");
  ws << "Repetitions,Key Size(Bits),AVG(ms)" << std::endl;

  for(int j = init; j <= size; j += 8) {
    double time = 0;

    std::cout << "\n**key_size=" << j << "**" << std::endl;

    for(int i = 0; i < rep; i++) {
      Key_pair keys = generate_keys(j, false);
      encrypt_file("original.txt", "encriptado.txt", keys.pub_key);

      auto start = std::chrono::high_resolution_clock::now();

      decrypt_file("encriptado.txt", "decriptado.txt", keys.priv_key);

      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
      time += duration.count();
      std::cout << '.' << std::flush;
    }
    ws << rep << ',' << j << ',' << time / rep << std::endl;
  }

  ws.close();
}
