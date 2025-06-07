#include <vector>
#include <list>
#include <forward_list>
#include <stack>

namespace ex1
{

/// Imprime `times` vezes a string `text`
void print_txt(const char* text, const unsigned int times);

/// Imprime uma contagem de 0 à 50, `times` vezes.
void count(const unsigned int times);

/// Imprime uma contagem de 0 à `max`, `times` vezes.
void count_max(const int times, const int max);

/// Imprime todos os elementos de uma Lista Sequencial (vector).
void print_vec(const std::vector<int>& vec, size_t idx);
void print_vec(const std::vector<int>& vec);

/// Imprime todos os elementos pares de uma Lista Sequencial
/// (vector), em ordem inversa.
void print_even(const std::vector<int>& vec, size_t idx);
void print_even(const std::vector<int>& vec);

/// Iimprime todos os elementos de uma Lista Duplamente Encadeada
/// (list).
void print_list(const std::list<int> &lst, const std::list<int>::const_iterator &it);
void print_list(const std::list<int> &lst);

/// Imprime todos os elementos de uma Lista Simplesmente
/// Encadeada (forward_list), em ordem inversa.
void print_rev(const std::forward_list<int> &lst, const std::forward_list<int>::const_iterator &it);
void print_rev(const std::forward_list<int> &lst);
 
/// Remove todos os elementos, um a um, de um vector.
void remove_all(std::vector<int> &vec);

/// Imprime todos os elementos de uma Pilha (stack).
void print_stack(std::stack<int> &stk);
/// Imprime todos os elementos de uma Pilha (stack) como um array JSON.
void print_stack_as_json(std::stack<int> &stk);

/// Desempilha todos os elementos da stack1 e os empilha, em ordem
/// inversa, na stack2.
void push_to(std::stack<int> &stk1, std::stack<int> &stk2);

/// Copia o conteúdo de vec1 para vec2.
void copy(const std::vector<int> &vec1, size_t idx, std::vector<int> &vec2);
void copy(const std::vector<int> &vec1, std::vector<int> &vec2);

/// Copia o conteúdo de list1 para list2.
void copy(const std::list<int> &list1, const std::list<int>::const_iterator &it, std::list<int> &list2);
void copy(const std::list<int> &list1, std::list<int> &list2);

}
