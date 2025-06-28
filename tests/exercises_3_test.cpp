#include "catch2/catch_all.hpp"
#include "exercises_3.hpp"

#include <iostream>

TEST_CASE("Exponenciação (Potencia)")
{
    REQUIRE(1 == ex3::exponenciacao(100, 0));
    REQUIRE(125 == ex3::exponenciacao(5, 3));
    REQUIRE(4 == ex3::exponenciacao(2, 2));
    REQUIRE(8 == ex3::exponenciacao(2, 3));
    REQUIRE(2744 == ex3::exponenciacao(14, 3));
    REQUIRE(19683 == ex3::exponenciacao(3, 9));
    REQUIRE(35831808 == ex3::exponenciacao(12, 7));
    REQUIRE(429981696 == ex3::exponenciacao(12, 8));
}

TEST_CASE("Máximo Divisor Comum (MDC - Algoritmo de Euclides)")
{
    REQUIRE(6 == ex3::MDC(48, 18));
    REQUIRE(5 == ex3::MDC(10, 15));
    REQUIRE(9 == ex3::MDC(27, 36));
    REQUIRE(1 == ex3::MDC(17, 31));
}

TEST_CASE("Permutações de uma string")
{
    auto resultado = ex3::permutacoes("abc");
    std::vector<std::string> esperado = {"abc", "acb", "bac", "bca", "cab", "cba"};
    REQUIRE(std::is_permutation(resultado.begin(), resultado.end(), esperado.begin()));
}

TEST_CASE("Subconjuntos (Backtracking)") 
{
    SECTION("Tamanho 2")
    {
        std::vector<int> conjunto = {1, 2};
        std::vector<std::vector<int>> esperado = { {}, {1}, {2}, {1, 2} };

        auto subconjs = ex3::subconjuntos(conjunto);

        std::vector<std::vector<int>> resultado(subconjs.begin(), subconjs.end());

        REQUIRE(pow(2, conjunto.size()) == resultado.size());
        REQUIRE(std::is_permutation(resultado.begin(), resultado.end(), esperado.begin()));
    }

    SECTION("Tamanho 3")
    {
        std::vector<int> conjunto = {1, 2, 3};
        std::vector<std::vector<int>> esperado = { {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3} };

        auto subconjs = ex3::subconjuntos(conjunto);

        std::vector<std::vector<int>> resultado(subconjs.begin(), subconjs.end());

        REQUIRE(pow(2, conjunto.size()) == resultado.size());
        REQUIRE(std::is_permutation(resultado.begin(), resultado.end(), esperado.begin()));
    }
}

TEST_CASE("Busca Binária")
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};

    REQUIRE(std::optional(5) == ex3::busca_binaria(5, arr));
    REQUIRE(std::optional(1) == ex3::busca_binaria(1, arr));
    REQUIRE(std::optional(11) == ex3::busca_binaria(11, arr));
    REQUIRE_FALSE(ex3::busca_binaria(6, arr).has_value());
}

TEST_CASE("Soma dos Dígitos de um Número")
{
    REQUIRE(6 == ex3::somar_digitos(123));
    REQUIRE(0 == ex3::somar_digitos(0));
    REQUIRE(27 == ex3::somar_digitos(999));
}

TEST_CASE("Inversão de string")
{
    REQUIRE("cba" == ex3::inverter_string("abc"));
    REQUIRE("" == ex3::inverter_string(""));
    REQUIRE("a" == ex3::inverter_string("a"));
}

TEST_CASE("Combinações (n escolhe k)")
{
    REQUIRE(10 == ex3::nCk(5, 2));
    REQUIRE(1 == ex3::nCk(6, 0));
    REQUIRE(1 == ex3::nCk(6, 6));
    REQUIRE(6 == ex3::nCk(6, 1));
}

TEST_CASE("Palidrômo")
{
    REQUIRE(ex3::é_palindromo("arara"));
    REQUIRE(ex3::é_palindromo("abba"));
    REQUIRE(ex3::é_palindromo(""));
    REQUIRE(ex3::é_palindromo("a"));
    REQUIRE_FALSE(ex3::é_palindromo("casa"));
}
