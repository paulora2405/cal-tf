#ifndef TESTS_HPP
#define TESTS_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include <fstream>
#include <iostream>

#include "brute_force.hpp"
#include "encryption.hpp"
#include "key_generator.hpp"

/*
 * Exporta para um csv o tempo medio da
 * quebra da chave privada por meio de fatoração.
 * @param[in] init Quantidade de bits inicial.
 * @param[in] size Quantidade de bits final.
 * @param[in] rep Quantidade de repetições para calcular a média.
 * @param[in] naive Booleano que decide se o algoritmo será o naive ou pollard.
 */
void brute_time_csv(int init, int size, int rep, bool naive);

/*
 *Exporta para um csv o tempo media para gerar as chaves publica e privada
 * @param[in] init Quantidade de bits inicial.
 * @param[in] size Quantidade de bits final.
 * @param[in] rep Quantidade de repetições para calcular a média.
 */
void key_gen_csv(int init, int size, int rep);

/*
 *Exporta para um csv o tempo media para encriptar os dados
 * @param[in] init Quantidade de bits inicial.
 * @param[in] size Quantidade de bits final.
 * @param[in] rep Quantidade de repetições para calcular a média.
 */
void encryption_time_csv(int init, int size, int rep);

/*
 *Exporta para um csv o tempo media para descriptar os dados
 * @param[in] init Quantidade de bits inicial.
 * @param[in] size Quantidade de bits final.
 * @param[in] rep Quantidade de repetições para calcular a média.
 */
void decryption_time_csv(int init, int size, int rep);

#endif