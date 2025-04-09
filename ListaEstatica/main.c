#include <stdio.h>

#include "biblioteca_estatica.h"

int main()
{

    Biblioteca b;

    inicializarBiblioteca(&b);

    cadastrarLivro(&b, "Dom Quixote", "Cervantes", 1605, "1234567890123");

    cadastrarLivro(&b, "1984", "George Orwell", 1949, "9876543210123");

    listarTodosLivros(&b);

    emprestarLivro(&b, "9876543210123", "Maria", "01/04/2025");

    listarTodosLivros(&b);

    return 0;
}