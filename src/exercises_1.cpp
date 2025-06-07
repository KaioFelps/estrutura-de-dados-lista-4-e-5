#include <iostream>
#include <string>
#include "exercises_1.hpp"

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

////////////////////////////////////////////////////////////
/// print_even
////////////////////////////////////////////////////////////
void print_list(const std::list<int> &lst, const std::list<int>::const_iterator &it)
{
    if (it == lst.begin()) std::cout << "[ ";

    std::cout << *it << " ";

    if (it == std::prev(lst.end()))
    {
        std::cout << "]\n";
        return;
    }

    const auto next_it = std::next(it);
    print_list(lst, next_it);
}

void print_list(const std::list<int> &lst)
{
    if (!lst.empty()) return print_list(lst, lst.begin());
    std::cout << "[ ]\n";
}

////////////////////////////////////////////////////////////
/// print_rev
////////////////////////////////////////////////////////////
void print_rev(const std::forward_list<int> &lst, const std::forward_list<int>::const_iterator &it)
{
    if (it == lst.begin())
    {
        std::cout << "[ ";
        print_rev(lst, std::next(it));
        std::cout << *it << " ]\n";
        return;
    }

    if (it == lst.end()) return;

    print_rev(lst, std::next(it));
    std::cout << *it << " ";
}

void print_rev(const std::forward_list<int> &lst)
{
    if (!lst.empty()) return print_rev(lst, lst.begin());
    std::cout << "[ ] \n";
}

////////////////////////////////////////////////////////////

void remove_all(std::vector<int> &vec)
{
    if (vec.empty()) return;

    vec.pop_back();
    remove_all(vec);
}

void print_stack(std::stack<int> &stk)
{
    if (stk.empty()) return;

    auto stack_el = stk.top();

    stk.pop();

    stk.empty()
        ? std::cout << stack_el
        : std::cout << stack_el << ", ";

    print_stack(stk);

    stk.push(stack_el);
}

void print_stack_as_json(std::stack<int> &stk)
{
    std::cout << "[ ";
    print_stack(stk);
    std::cout << " ]\n";
}

void push_to(std::stack<int> &stk1, std::stack<int> &stk2)
{
    if (stk1.empty()) return;

    stk2.push(stk1.top());
    stk1.pop();

    push_to(stk1, stk2);
}

////////////////////////////////////////////////////////////
/// copy for vectors
////////////////////////////////////////////////////////////
void copy(const std::vector<int> &vec1, size_t idx, std::vector<int> &vec2)
{
    if (idx >= vec1.size()) return;

    vec2.push_back(vec1[idx]);
    copy(vec1, idx + 1, vec2);
}

void copy(const std::vector<int> &vec1, std::vector<int> &vec2)
{
    copy(vec1, 0, vec2);
}

////////////////////////////////////////////////////////////
/// copy for vectors
////////////////////////////////////////////////////////////
void copy(const std::list<int> &list1, const std::list<int>::const_iterator &it, std::list<int> &list2)
{
    if (it == list1.end()) return;

    list2.push_back(*it);
    copy(list1, std::next(it), list2);
}

void copy(const std::list<int> &list1, std::list<int> &list2)
{
    copy(list1, list1.begin(), list2);
}
