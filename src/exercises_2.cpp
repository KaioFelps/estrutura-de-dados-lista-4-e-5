#include "exercises_2.hpp"
#include <cassert>
#include <algorithm>

namespace ex2
{

int sum_even(const std::span<int>& vec, size_t last_idx)
{
    assert(last_idx < vec.size() && "Tentou acessar uma posição inválida na estrutura array-like.");

    auto value_to_sum = last_idx % 2 == 0 ? vec[last_idx] : 0;

    if (last_idx == 0) return value_to_sum;

    return value_to_sum + sum_even(vec, last_idx -1);
}

int sum_even(const std::span<int>& vec)
{
    return sum_even(vec, vec.size() - 1);
}

int product(const std::list<int>& lst, std::list<int>::iterator it)
{
    if (it == std::prev(lst.end())) return *it;
    if (*it == 0) return 0;
    return *it * product(lst, std::next(it));
}

int min(const std::span<const int>& vec, size_t idx, int smallest_num)
{
    if (idx >= vec.size()) return smallest_num;
    const size_t next_idx = idx + 1;
    return min(
        vec,
        next_idx,
        vec[idx] < smallest_num ? vec[idx] : smallest_num
    );
}

int min(const std::span<const int>& vec)
{
    assert(!vec.empty() && "`vec` deveria possuir ao menos um elemento para que haja um elemento mínimo.");
    return min(vec, 0, INT32_MAX);
}

int min(const std::list<int>& lst, std::list<int>::const_iterator it, int smallest_num)
{
    if (it == lst.end()) return smallest_num;
    return min(lst, std::next(it), *it < smallest_num ? *it : smallest_num);
}

int min(const std::list<int>& lst, const std::list<int>::const_iterator it)
{
    return min(lst, it, INT32_MAX);
}

int min(const std::list<int>& lst)
{
    return min(lst, lst.begin(), INT32_MAX);
}

bool find(const std::span<const int>& vec, const int& elem, size_t idx)
{
    if (idx >= vec.size()) return false;
    if (vec[idx] == elem) return true;
    return find(vec, elem, ++idx);
}

bool find(const std::span<const int>& vec, const int& elem)
{
    return find(vec, elem, 0);
}

size_t count(const std::span<const int>& vec, const int& elem, const size_t idx, const size_t _count)
{
    if (idx >= vec.size()) return _count;
    const size_t new_count = vec[idx] == elem ? _count + 1 : _count;

    return count(vec, elem, idx + 1, new_count);
}

size_t count(const std::span<const int>& vec, const int& elem)
{
    return count(vec, elem, 0, 0);
}

void reverse(std::span<int> vec, size_t first, size_t last)
{
    if (first >= last) return;
    std::swap(vec[first], vec[last]);
    return reverse(vec, first + 1, last - 1);
}

void reverse(std::list<int>& lst, std::list<int>::iterator first, std::list<int>::iterator last)
{
    if (std::prev(first) == last || first == lst.end() || last == lst.begin()) return;
    if (last == lst.end()) last = std::prev(last);

    std::iter_swap(first, last);

    return reverse(lst, std::next(first), std::prev(last));
}

bool palindrome(const std::string& str, const size_t first, const size_t last)
{
    if (first > last) return true;
    if (str[first] != str[last]) return false;
    return palindrome(str, first + 1, last - 1);
}

bool palindrome(const std::string& str)
{
    return palindrome(str, 0, str.length() - 1);
}

bool palindrome(const std::list<int>& lst, std::list<int>::const_iterator first, std::list<int>::const_iterator last)
{
    if (std::prev(first) == last || first == lst.end() || last == lst.begin()) return true;
    if (last == lst.end()) last = std::prev(last);

    if (*first != *last) return false;
    return palindrome(lst, std::next(first), std::prev(last));
}

bool palindrome(const std::list<int>& lst)
{
    return palindrome(lst, lst.begin(), std::prev(lst.end()));
}

}