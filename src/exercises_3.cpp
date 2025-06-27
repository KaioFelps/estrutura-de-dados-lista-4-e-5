#include "exercises_3.hpp"
#include <math.h>


#include <iostream>

static bool é_par(float num) { return fmod(num, 2) == 0.; }

static bool é_impar(float num) { return !é_par(num); }

namespace ex3
{

float exponenciacao(float a, float b)
{
    if (b == 0) return 1.;
    if (b == 1) return a;

    auto b_ = floor(b/2);
    auto a_ = exponenciacao(a, b_);

    auto third_part = é_impar(b) ? a : 1;

    return  a_ * a_ * third_part;
}

int MDC(int a, int b)
{
    auto a_ = b;
    auto b_ = a % b;

    return b_ <= 0
        ? a_
        : MDC(a_, b_);
}

static void permutar(
    std::string& permutacao,
    std::string& restantes,
    size_t indice,
    std::vector<std::string>& permutacoes
);

static void permutar_se_houver_proximo(
    std::string& permutacao,
    std::string& restantes,
    size_t indice,
    std::vector<std::string>& permutacoes
)
{
    if (++indice >= restantes.length()) return;
    permutar(permutacao, restantes, indice, permutacoes);
}

static void permutar(
    std::string& permutacao,
    std::string& restantes,
    size_t indice,
    std::vector<std::string>& permutacoes
)
{
    if (restantes.empty())
    {
        permutacoes.push_back(permutacao);
        return;
    }
    
    auto caractere = restantes[indice];
    restantes.erase(indice, 1);

    permutacao.push_back(caractere);

    permutar(permutacao, restantes, 0, permutacoes);

    restantes.insert(std::next(restantes.begin(), indice), caractere);
    permutacao.pop_back();

    permutar_se_houver_proximo(permutacao, restantes, indice, permutacoes);
}

std::vector<std::string> permutacoes(std::string palavra)
{
    auto permutacoes = std::vector<std::string>();
    auto permutacao = std::string();
    permutacao.reserve(palavra.size());

    permutar(permutacao, palavra, 0, permutacoes);

    return permutacoes;
}

static void subconjuntos(
    size_t indice,
    std::vector<int>& universo,
    std::vector<std::vector<int>>& subconjuntos_,
    std::vector<int>& conjunto
)
{
    if (indice == universo.size())
    {
        subconjuntos_.push_back(conjunto);
        return;
    }

    subconjuntos(indice + 1, universo, subconjuntos_, conjunto);

    conjunto.push_back(universo[indice]);
    subconjuntos(indice + 1, universo, subconjuntos_, conjunto);
    conjunto.pop_back();
}

std::vector<std::vector<int>> subconjuntos(std::vector<int> universo)
{
    auto resultado = std::vector<std::vector<int>>();
    resultado.reserve(pow(2, universo.size()));

    auto conjunto = std::vector<int>();
    subconjuntos(0, universo, resultado, conjunto);
    
    return resultado;
}

static std::optional<int> busca_binaria(
    const int& alvo,
    std::span<int> arr,
    size_t inicio,
    size_t fim
)
{
    auto meio = floor((inicio + fim) / 2);

    if (arr[meio] == alvo)
    {
        return arr[meio];
    }

    if (inicio >= fim)
    {
        return std::nullopt;
    }

    if (alvo < arr[meio])
    // então o alvo está à esquerda
    {
        return busca_binaria(alvo, arr, inicio, meio);
    }

    // caso contrário, o alvo está à direita
    return busca_binaria(alvo, arr, meio + 1, fim);
}

std::optional<int> busca_binaria(const int& alvo, std::span<int> arr)
{
    return busca_binaria(alvo, arr, 0, arr.size());
}

int somar_digitos(int numero)
{
    if (numero == 0) return 0;
    return numero % 10 + somar_digitos(numero / 10);
}

// std::string inverter_string(const std::string& str); 

// int nCk(int n, int k);

// bool é_palindromo(std::string texto);

}
