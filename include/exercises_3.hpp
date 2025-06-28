#pragma once

#include <span>
#include <string>
#include <vector>
#include <optional>

namespace ex3
{

/// 1. Exponenciação (Potência)
/// ◦ Calcular ab de forma eficiente.
/// ◦ Solução Recursiva: Usar divisão e conquista (a^b = a^(b/2) x a^(b/2).
float exponenciacao(float a, float b);

/// 2. Máximo Divisor Comum (MDC - Algoritmo de Euclides)
/// ◦ Encontrar o MDC entre dois números.
/// ◦ Solução Recursiva: mdc(a, b) = mdc(b, a % b).
int MDC(int a, int b);

/// 3. Permutações de uma String
/// ◦ Gerar todas as permutações possíveis de caracteres em uma string.
/// ◦ Solução Recursiva: Trocar caracteres e chamar recursivamente para substrings.
std::vector<std::string> permutacoes(std::string palavra);

/// 4. Subconjuntos (Backtracking)
/// ◦ Gerar todos os subconjuntos de um conjunto.
/// ◦ Solução Recursiva: Incluir ou não cada elemento em um subconjunto.
std::vector<std::vector<int>> subconjuntos(std::vector<int> conjunto);

/// 5. Busca Binária
/// ◦ Encontrar um elemento em um array ordenado.
/// ◦ Solução Recursiva: Dividir o array ao meio e chamar a busca no subarray relevante.
std::optional<int> busca_binaria(const int& alvo, std::span<int> arr);

/// 6. Problema das N-Rainhas
/// ◦ Posicionar N rainhas em um tabuleiro de xadrez sem que se ataquem.
/// ◦ Solução Recursiva: Posicionar rainhas linha por linha e verificar conflitos.

/// 7. Soma dos Dígitos de um Número
/// ◦ Calcular a soma dos dígitos de um número inteiro.
/// ◦ Solução Recursiva: soma_digitos(n) = n % 10 + soma_digitos(n / 10).
int somar_digitos(int numero);

/// 8. Inversão de uma String
/// ◦ Inverter os caracteres de uma string.
/// ◦ Solução Recursiva: Trocar o primeiro e o último caractere e chamar a função para a substring
/// interna.
std::string inverter_string(const std::string& str); 

/// 9. Combinações (n escolhe k)
/// ◦ Calcular o número de combinações de n elementos tomados k a k.
/// ◦ Solução Recursiva: Usar a relação C(n, k) = C(n−1, k) + C(n−1, k−1).
int nCk(int n, int k);

/// 10. Palidrômo
/// ◦ Verificar se uma string é um palíndromo.
/// ◦ Solução Recursiva: Comparar o primeiro e o último caractere e chamar a função para a substring
/// interna.
bool é_palindromo(std::string texto);

}
