#include <iostream>
#include <string>
#include "exercises.hpp"

void print_txt(const char* text, const unsigned int times)
{
    if (times == 0) return;
    std::cout << text << "\n";
    print_txt(text, times - 1);
}

static void recursively_count(const int from, const int to)
{
    if (from > to) return;

    from == to
        ? std::cout << from << "\n"
        : std::cout << from << " ";

    recursively_count(from + 1, to);
}

void count(const unsigned int times)
{
   if (times == 0) return;
   recursively_count(0, 50);
   count(times - 1); 
}

void count_max(const int times, const int max)
{
    if (times == 0) return;
    recursively_count(0, max);
    count_max(times - 1, max);
}

////////////////////////////////////////////////////////////
/// print_vec
////////////////////////////////////////////////////////////
void print_vec(const std::vector<int>& vec, size_t idx)
{
    if (idx == 0) std::cout << "[ ";

    std::cout << vec[idx] << " ";

    if (idx >= vec.size() - 1)
    {
        std::cout << "]\n";
        return;
    }

    print_vec(vec, idx + 1);
}

void print_vec(const std::vector<int>& vec)
{
    print_vec(vec, 0);
}

////////////////////////////////////////////////////////////
/// print_even
////////////////////////////////////////////////////////////
void print_even(const std::vector<int>& vec, size_t idx)
{
    if (idx == vec.size() - 1) std::cout << "[ ";

    const auto& element = vec[idx];
    auto is_even = element % 2 == 0;

    if (is_even) std::cout << element << " ";

    if (idx != 0) return print_even(vec, idx - 1);

    std::cout << "]\n";
}

void print_even(const std::vector<int>& vec)
{
    print_even(vec, vec.size() - 1);
}
