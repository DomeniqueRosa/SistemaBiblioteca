#include "biblioteca_dinamica.h"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define INICIAL 10

void inicializarBiblioteca(Biblioteca *b)
{

    b->livros = (Livro *)malloc(INICIAL * sizeof(Livro));

    b->capacidade = INICIAL;

    b->totalLivros = 0;
}

// Esta função realoca o vetor de livros com nova capacidade

void redimensionarBiblioteca(Biblioteca *b, int novaCapacidade)
{

    // Completar: usar realloc para redimensionar e atualizar b->capacidade
}

// Cadastrar livro (com verificação de ISBN e redimensionamento automático)

int cadastrarLivro(Biblioteca *b, char *titulo, char *autor, int ano, char *isbn)
{

    // Completar: verificar se já existe o ISBN

    // Se capacidade esgotada, dobrar o tamanho

    // Inserir novo livro no final
}

// Listar todos os livros

void listarTodosLivros(Biblioteca *b)
{

    // Completar: percorrer de 0 até totalLivros e imprimir os dados
}

// Emprestar livro

int emprestarLivro(Biblioteca *b, char *isbn, char *usuario, char *data)
{

    // Completar: buscar pelo ISBN e alterar status
}

// Devolver livro

int devolverLivro(Biblioteca *b, char *isbn)
{

    // Completar: buscar pelo ISBN e alterar status
}

// Buscar livro pelo ISBN

Livro *consultarLivroPorISBN(Biblioteca *b, char *isbn)
{

    // Completar: percorrer o vetor e comparar com strcmp
}

// Liberar memória

void destruirBiblioteca(Biblioteca *b)
{

    free(b->livros);

    b->livros = NULL;

    b->capacidade = 0;

    b->totalLivros = 0;
}