# Trabalho de Complexidade de Algoritmos 2020-2
*Paulo Roberto Albuquerque & Menderson Costa*

---

### Execução
Faça:
```sh
$ make
```
E depois:
```sh
./build/apps/main
```


### Geração da chave pública e privada
1. Selecionar dois números primos aleatorios `p` e `q`
1. Calcular `n = p * q`
1. Calcular `ø(n) = (p - 1)*(q - 1)`
1. Achar um `e` tal que `gcd(e, ø(n)) = 1 ; 1 < e < ø(n)`
1. Calcular `d` tal que `e*d = 1 (mod ø(n))`

- A chave Pública será `(n, e)`
- A chave Privada será `(n, d)`

### Encriptação e Decriptação
Dada uma mensagem `m` e uma mensagem cifrada `c`

##### Encriptação
- Dada uma mensagem `m` usar <code>m<sup>e</sup> = c (mod n)</code> para calcular a mensagem cifrada `c`

##### Decriptação
- Dada uma mensagem cifrada `c` usar <code>c<sup>d</sup> = m (mod n)</code> para calcular a mensagem original

### Observações do Professor
- Nos graficos, não usar escala logarítmica.

### Links importantes
- Paper sobre implementação de RSA em C
  - https://www.academia.edu/40465824/RSA_Implementation_using_C_

- Documentação sobre a bibli de inteiros grandes *gmp*
  - https://gmplib.org/manual/Integer-Functions

- Implementação de RSA em C++
  - https://www.tutorialspoint.com/cplusplus-program-to-implement-the-rsa-algorithm

- Wiki sobre testes de primalidade
  - https://en.wikipedia.org/wiki/Primality_test

- Algoritimos do brute para testes de primalidade
  - https://github.com/BRUTEUdesc/AlmanaqueBrute/tree/master/Matem%C3%A1tica/Primos

- Exemplo RSA em Java
  - https://stackoverflow.com/questions/15920739/rsa-implementation-using-java

- Long long e biblioteca de inteiros customizados
  - https://stackoverflow.com/questions/6462439/whats-the-difference-between-long-long-and-long

- Algoritmo de euclides estendido
  - https://www.ime.usp.br/~coelho/mac0338-2004/aulas/mdc/index.html

- Calculadora rsa
  - https://www.cs.drexel.edu/~jpopyack/IntroCS/HW/RSAWorksheet.html

- RSA prático
  - https://www.cs.drexel.edu/~jpopyack/Courses/CSP/Fa17/notes/10.1_Cryptography/RSA_Express_EncryptDecrypt_v2.html