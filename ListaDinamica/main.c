#include <stdio.h>

#include "biblioteca_dinamica.h"

int main()
{

    Biblioteca b;

    inicializarBiblioteca(&b);

    cadastrarLivro(&b, "A Metamorfose", "Kafka", 1915, "1111111111111");

    cadastrarLivro(&b, "O Pequeno Príncipe", "Saint-Exupéry", 1943, "2222222222222");

    listarTodosLivros(&b);

    emprestarLivro(&b, "1111111111111", "Ana", "04/04/2025");

    listarTodosLivros(&b);

    destruirBiblioteca(&b);

    return 0;
}