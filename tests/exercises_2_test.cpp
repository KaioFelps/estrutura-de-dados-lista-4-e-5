#include "exercises_2.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("`sum` deve somar todos os valores em posições pares de um vetor de inteiros")
{
    auto vec = std::vector<int>({1, 45, 6, 0, 184, 583, 804, 100, -394});
    REQUIRE(334 == ex2::sum(vec));
}

TEST_CASE("`product` deveria retornar o produto de todos os elementos de uma lista a partir de um ponto")
{
    auto list = std::list {1, 5, 0, 30, 20, 40, 58, 80, 19000};
    auto list_iterator = list.begin();

    // posiciona o início da iteração no elemento 30
    std::advance(list_iterator, 2);

    REQUIRE(2115840000000 == ex2::product(list, list_iterator));
}

TEST_CASE("`min` deveria encontrar o menor elemento de um array-like")
{
    REQUIRE(-500 == ex2::min(std::vector<int>({-100, 0, 10, 50, 400, 1800, 9483, -499, -500, 399, -20, 0})));
}

TEST_CASE("`min` deveria encontrar o menor elemento em uma lista a partir de um dado elemento")
{
    auto list = std::list {-500, 0, 500, -200, 490, 900, -305};
    REQUIRE(-500 == ex2::min(list, list.begin()));
    REQUIRE(-305 == ex2::min(list, std::next(list.begin())));
}

TEST_CASE("`find` deveria informar se um elemento existe em um array-like")
{
    int arr[] = {400, 2904, -394298, 482, 204831, 401894, 37983};

    REQUIRE_FALSE(ex2::find(arr, 0));
    REQUIRE(ex2::find(arr, 2904));
}

TEST_CASE("`count` deveria contar a ocorrência de um elemento em um array-like")
{
    int arr[] = {4900, 5498, 290, 984, 290, 1940, 4900, 10, 290, 25};

    REQUIRE(1 == ex2::count(arr, 10));
    REQUIRE(2 == ex2::count(arr, 4900));
    REQUIRE(3 == ex2::count(arr, 290));
}

TEST_CASE("`reverse` deveria inverter um segmento de um array-like")
{
    int arr[] ={1, 2, 3, 7, 6, 5, 4, 8, 9, 10};
    ex2::reverse(arr, (size_t) 3, (size_t) 6);
    
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    REQUIRE(std::equal(std::span(expected).begin(), std::span(expected).end(), std::span(arr).begin()));
}

TEST_CASE("`reverse` deveria inverter uma lista no segmento específicado")
{
    auto list = std::list<int> {1, 2, 3, 7, 6, 5, 4, 8, 9, 10};
    auto expected = std::list<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ex2::reverse(list, std::next(list.begin(), 3), std::next(list.begin(), 6));
    REQUIRE(std::equal(expected.begin(), expected.end(), list.begin()));
}

TEST_CASE("`palindrome` deveria verificar se uma string é um palíndromo")
{
    REQUIRE(ex2::palindrome("arara"));
    REQUIRE(ex2::palindrome("ararra"));
    REQUIRE_FALSE(ex2::palindrome("carro"));
}

TEST_CASE("`palindrome` deveria verificar se os elementos de uma lista formam um palíndromo")
{
    auto palindrome_list = std::list<int> {1, 2, 3, 4, 5, 4, 3, 2, 1};
    auto palindrome_list_2 = std::list<int> {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    auto non_palindrome_list = std::list<int> {1, 2, 3, 4, 5, 5, 3, 2, 1};
    auto non_palindrome_list_2 = std::list<int> {1, 2, 3, 4, 5, 3, 2, 1};

    REQUIRE(ex2::palindrome(palindrome_list));
    REQUIRE(ex2::palindrome(palindrome_list_2));
    REQUIRE_FALSE(ex2::palindrome(non_palindrome_list));
    REQUIRE_FALSE(ex2::palindrome(non_palindrome_list_2));
}
