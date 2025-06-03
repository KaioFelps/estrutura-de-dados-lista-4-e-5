#include <catch2/catch_all.hpp>
#include "exercises.hpp"
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

TEST_CASE("print_txt imprime texto N vezes", "[print_txt]") {
    auto output = capture_output([]() {
        print_txt("Hello", 3);
    });

    REQUIRE(output == "Hello\nHello\nHello\n");
}

TEST_CASE("count imprime contagem de 0 a 50, N vezes", "[count]") {
    auto output = capture_output([]() {
        count(2);
    });

    std::stringstream expected;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i <= 50; ++i) {
            expected << i;
            if (i != 50) expected << " ";
        }
        expected << "\n";
    }

    REQUIRE(expected.str() == output);
}

TEST_CASE("count_max imprime contagem de 0 a max, N vezes", "[count_max]") {
    auto output = capture_output([]() {
        count_max(2, 5);
    });

    std::stringstream expected;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i <= 5; ++i) {
            expected << i;
            if (i != 5) expected << " ";
        }
        expected << "\n";
    }

    REQUIRE(expected.str() == output);
}

TEST_CASE("print_vec imprime todos os elementos do vetor", "[print_vec]") {
    std::vector<int> vec = {1, 2, 3};

    auto output = capture_output([&]() {
        print_vec(vec);
    });

    REQUIRE("[ 1 2 3 ]\n" == output);
}

TEST_CASE("print_even imprime pares em ordem inversa", "[print_even]") {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    auto output = capture_output([&]() {
        print_even(vec);
    });

    REQUIRE("[ 6 4 2 ]\n" == output);
}
