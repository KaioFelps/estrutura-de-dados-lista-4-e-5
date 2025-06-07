#include <list>
#include <string>
#include <span>

namespace ex2
{

/// Retorna a soma de todos os elementos de um vector de tamanho n
/// que estão em posições pares.
int sum_even(const std::span<int>& vec, size_t last_idx);
int sum_even(const std::span<int>& vec);

/// Retorna o produto de todos os elementos de uma list de início em it.
int product(const std::list<int>& lst, std::list<int>::iterator it);

/// Retorna o menor dos elementos de um vector de tamanho n.
int min(const std::span<const int>& vec);

/// Retorna o menor dos elementos de uma lista de início em it.
int min(const std::list<int>& lst, std::list<int>::iterator it);

/// Informa se um elemento está em um vector de tamanho n.
bool find(const std::span<const int>& vec, const int& elem);

/// Retorna a quantidade de ocorrência de um elemento em um vector de
/// tamanho n.
int count(const std::span<const int>& vec, const int& elem);

// `span` é como uma referência para um vetor ou um array (de c ou c++).
// como não copia dados, não há necessidade de passar por referência, ainda mais
// se o objetivo for modificar os elementos que acessíveis por meio do span.

/// Inverte os elementos em um vector, de início em first e final em last.
void reverse(std::span<int> vec, size_t first, size_t last);

/// Inverte os elementos em uma list, de início em first e final em last.
void reverse(std::list<int>& lst, std::list<int>::iterator first, std::list<int>::iterator last);

/// Verifica se uma string forma um palíndromo.
bool palindrome(const std::string& str, const size_t first, const size_t last);
bool palindrome(const std::string& str);

/// Verifica se os elementos de uma list foram um palíndromo.
bool palindrome(const std::list<int>& lst, std::list<int>::iterator first, const std::list<int>::iterator last);
bool palindrome(const std::list<int>& lst);

}
