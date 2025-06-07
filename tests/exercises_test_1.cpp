#include <catch2/catch_all.hpp>
#include "exercises_1.hpp"
#include <sstream>
#include <iostream>

// Helper para capturar a saída do cout
static std::string capture_output(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    func();

    std::cout.rdbuf(old);
    return buffer.str();
}

TEST_CASE("print_txt imprime texto N vezes", "[print_txt]")
{
    auto output = capture_output([]()
    {
        ex1::print_txt("Hello", 3);
    });

    REQUIRE(output == "Hello\nHello\nHello\n");
}

TEST_CASE("count imprime contagem de 0 a 50, N vezes", "[count]")
{
    auto output = capture_output([]()
    {
        ex1::count(2);
    });

    std::stringstream expected;
    for (int t = 0; t < 2; ++t)
    {
        for (int i = 0; i <= 50; ++i)
        {
            expected << i;
            if (i != 50) expected << " ";
        }
        expected << "\n";
    }

    REQUIRE(expected.str() == output);
}

TEST_CASE("count_max imprime contagem de 0 a max, N vezes", "[count_max]")
{
    auto output = capture_output([]() {
        ex1::count_max(2, 5);
    });

    std::stringstream expected;
    for (int t = 0; t < 2; ++t)
    {
        for (int i = 0; i <= 5; ++i)
        {
            expected << i;
            if (i != 5) expected << " ";
        }
        expected << "\n";
    }

    REQUIRE(expected.str() == output);
}

TEST_CASE("print_vec imprime todos os elementos do vetor", "[print_vec]")
{
    std::vector<int> vec = {1, 2, 3};

    auto output = capture_output([&]()
    {
        ex1::print_vec(vec);
    });

    REQUIRE("[ 1 2 3 ]\n" == output);
}

TEST_CASE("print_even imprime pares em ordem inversa", "[print_even]")
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    auto output = capture_output([&]()
    {
        ex1::print_even(vec);
    });

    REQUIRE("[ 6 4 2 ]\n" == output);
}

TEST_CASE("print_list imprime todos os elementos de uma lista duplamente encadeada")
{
    std::list<int> list = {1, 2, 3, 4, 5, 6, 7, 8};

    auto output = capture_output([&]()
    {
        ex1::print_list(list);
    });

    REQUIRE("[ 1 2 3 4 5 6 7 8 ]\n" == output);
}

TEST_CASE("print_rev imprime os elementos de uma lista encadeada simples em ordem inversa")
{
    std::forward_list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto output = capture_output([&]()
    {
        ex1::print_rev(list);
    });

    REQUIRE("[ 10 9 8 7 6 5 4 3 2 1 ]\n" == output);
}

TEST_CASE("remove_all remove todos os elementos do vetor")
{
    std::vector<int> vec = {1, 4, 53, 23, 5, 7, 32, 23, 5049, 39};
    REQUIRE(!vec.empty());

    ex1::remove_all(vec);

    REQUIRE(vec.empty());
}

TEST_CASE("print_stack imprime todos os elementos de uma pilha sem modificá-la permanentemente")
{
    auto stk = std::stack<int>({1, 2, 3, 4, 10, 20, 30, 40});
    auto stack_size = stk.size();

    auto output = capture_output([&]()
    {
        ex1::print_stack_as_json(stk);
    });

    REQUIRE(stack_size == stk.size());
    REQUIRE("[ 40, 30, 20, 10, 4, 3, 2, 1 ]\n" == output);
}

TEST_CASE("push_to desempilha todos os elementos da primeira stack e coloca, inversamente, na segunda")
{
    auto stk1 = std::stack<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    auto stk2 = std::stack<int>();

    ex1::push_to(stk1, stk2);

    REQUIRE(stk1.empty());
    REQUIRE_FALSE(stk2.empty());

    auto stringified_stk2 = capture_output([&]() { ex1::print_stack_as_json(stk2); });
    REQUIRE("[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]\n" == stringified_stk2);
}

TEST_CASE("copy copia um vetor para o outro")
{
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec2;

    ex1::copy(vec1, vec2);

    REQUIRE(vec1 == vec2);
}

TEST_CASE("copy copia uma lista duplamente encadeada para outra")
{
    std::list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> list2;

    ex1::copy(list1, list2);

    REQUIRE(list1 == list2);
}
