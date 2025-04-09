#include "biblioteca_encadeada.h"

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

void inicializarBiblioteca(Biblioteca *b)
{

    b->primeiro = NULL;

    b->totalLivros = 0;
}

int cadastrarLivro(Biblioteca *b, char *titulo, char *autor, int ano, char *isbn)
{

    // Verificar se ISBN já existe

    // Criar novo nó e preencher dados

    // Inserir no início da lista
}

void listarTodosLivros(Biblioteca *b)
{

    // Percorrer a lista com um ponteiro e imprimir dados
}

int emprestarLivro(Biblioteca *b, char *isbn, char *usuario, char *data)
{

    // Percorrer lista e alterar status se encontrar
}

int devolverLivro(Biblioteca *b, char *isbn)
{

    // Percorrer lista e alterar status
}

NoLivro *consultarLivroPorISBN(Biblioteca *b, char *isbn)
{

    // Buscar nó com ISBN correspondente
}

void destruirBiblioteca(Biblioteca *b)
{

    // Liberar todos os nós da lista com free
}