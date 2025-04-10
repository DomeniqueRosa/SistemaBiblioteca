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
    // guarda em uma variavel tmp nova relocao de memoria
    Livro *temp = (Livro *) realloc(b->livros, novaCapacidade * sizeof(Livro));

    //verifica primeiro se deu certo antes de atualizar caso contrario mostra erro
    if(temp != NULL){
        b->livros = temp;
        b->capacidade = novaCapacidade;
    }else{
        printf("Erro ao realocar memoria.");
    }


}

// Cadastrar livro (com verificação de ISBN e redimensionamento automático)

int cadastrarLivro(Biblioteca *b, char *titulo, char *autor, int ano, char *isbn)
{

    // Completar: verificar se já existe o ISBN
    for (int i = 0; i < b->totalLivros; i++)
    {
        if(strcmp(b->livros[i].isbn,isbn) == 0){
            printf("Livro ja cadastrado");
            return -1;
        }
    }

    // Se capacidade esgotada, dobrar o tamanho
    if(b->totalLivros >= b->capacidade){
        redimensionarBiblioteca(b, b->capacidade * 2);
    }

    
     // Inserir novo livro no final do vetor
     strcpy(b->livros[b->totalLivros].titulo, titulo);
     strcpy(b->livros[b->totalLivros].autor, autor);
     b->livros[b->totalLivros].ano = ano;
     strcpy(b->livros[b->totalLivros].isbn, isbn);
     b->livros[b->totalLivros].status = DISPONIVEL;
     b->livros[b->totalLivros].usuario[0] = ' ';         
     b->livros[b->totalLivros].dataEmprestimo[0] = ' ';  
     b->totalLivros++;
     printf("Livro cadastrado\n");

     return 0;
}

// Listar todos os livros

void listarTodosLivros(Biblioteca *b)
{

    // Completar: percorrer de 0 até totalLivros e imprimir os dados
    for (int i = 0; i < b->totalLivros; i++)
    {
        printf("========Livro %d========\n", i+1);
        printf("Titulo: %s\nAutor: %s\nAno:%d\nISBN:%s\nStatus:%s\n",b->livros[i].titulo, b->livros[i].autor, b->livros[i].ano, b->livros[i].isbn, b->livros[i].status == DISPONIVEL ? "Disponivel" : "Emprestado");
    }
    
}

// Emprestar livro

int emprestarLivro(Biblioteca *b, char *isbn, char *usuario, char *data)
{

    // Completar: buscar pelo ISBN e alterar status
    for (int i = 0; i < b->totalLivros; i++)
    {
        if(strcmp(b->livros[i].isbn, isbn) == 0 && b->livros[i].status != EMPRESTADO){
            strcpy(b->livros[i].usuario,usuario);
            strcpy(b->livros[i].dataEmprestimo, data);
            b->livros[i].status = EMPRESTADO;
            return 0;
        }
    }
    return -1;
    
}

// Devolver livro

int devolverLivro(Biblioteca *b, char *isbn)
{

    // Completar: buscar pelo ISBN e alterar status
    for (int i = 0; i < b->totalLivros; i++)
    {
        if(strcmp(b->livros[i].isbn, isbn) == 0){      
            b->livros[i].status = DISPONIVEL;
            return 0;
        }
    }
    return -1;
}

// Buscar livro pelo ISBN

Livro *consultarLivroPorISBN(Biblioteca *b, char *isbn)
{

    // Completar: percorrer o vetor e comparar com strcmp
    for (int i = 0; i < b->totalLivros; i++)
    {
        if(strcmp(b->livros[i].isbn, isbn) == 0){
            return &b->livros[i];
        }
    }
    return NULL;
}

// Liberar memória

void destruirBiblioteca(Biblioteca *b)
{

    free(b->livros);

    b->livros = NULL;

    b->capacidade = 0;

    b->totalLivros = 0;
}