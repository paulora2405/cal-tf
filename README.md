# RSA Implementation
*Trabalho de Complexidade de Algoritmos 2020-2*

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

### Testes
O arquivo _tests.hpp_ possui funções para testar a média de tempo de execução para a quebra da chave privada, para a geração das chaves, bem como encriptação e decriptação.
As funcões possuem documentação para entender como devem ser executadas.
