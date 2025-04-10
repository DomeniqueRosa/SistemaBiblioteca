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
    if(consultarLivroPorISBN(b,isbn)){
        printf("Livro ja cadastrado!");
        return -1;
    }
    // Criar novo nó e preencher dados
    NoLivro* novo = malloc(sizeof(NoLivro));

    // Verificar se alocacao deu certo
    if(novo == NULL)return -1;

    //adc dados no livro
    strcpy(novo->livro.titulo,titulo);
    strcpy(novo->livro.autor, autor);
    strcpy(novo->livro.isbn, isbn);
    novo->livro.ano = ano;
    novo->livro.status = DISPONIVEL;
    strcpy(novo->livro.usuario, "");
    strcpy(novo->livro.dataEmprestimo, "");
    
    // Inserir no início da lista
    novo->proximo = b->primeiro;

    b->primeiro = novo;
    b->totalLivros++;

    return 0;
}

void listarTodosLivros(Biblioteca *b)
{

    // Percorrer a lista com um ponteiro e imprimir dados
    NoLivro* atual = b->primeiro;

    while (atual != NULL)
    {
        printf(
            "Titulo: %s\nAutor: %s\nISBN: %s\nAno: %d\nStatus:%s\n",
            atual->livro.titulo,
            atual->livro.autor,
            atual->livro.isbn,
            atual->livro.ano,
            atual->livro.status == DISPONIVEL ? "Disponivel" : "Emprestado"
            
        );
        atual = atual->proximo;
    }
    
}

int emprestarLivro(Biblioteca *b, char *isbn, char *usuario, char *data)
{
    NoLivro* atual = consultarLivroPorISBN(b, isbn);

    // Percorrer lista e alterar status se encontrar
    if(atual && atual->livro.status != EMPRESTADO){
        atual->livro.status = EMPRESTADO;
       strcpy(atual->livro.dataEmprestimo, data);
       strcpy(atual->livro.usuario, usuario);
       return 0;
    }

    return -1;
       
}

int devolverLivro(Biblioteca *b, char *isbn)
{

    NoLivro* atual = consultarLivroPorISBN(b, isbn);

    // Percorrer lista e alterar status se encontrar
    if(atual){
       atual->livro.status = DISPONIVEL;
       strcpy(atual->livro.dataEmprestimo, '\0');
       strcpy(atual->livro.usuario, '\0');
       return 0;
    }

    return -1; //erro

}

NoLivro *consultarLivroPorISBN(Biblioteca *b, char *isbn)
{

    // Buscar nó com ISBN correspondente
    NoLivro* atual = b->primeiro;

    while (atual != NULL)
    {
        if(strcmp(atual->livro.isbn, isbn) == 0){
            return atual;
        }
       
        atual = atual->proximo;
    }

    return NULL;
}

void destruirBiblioteca(Biblioteca *b)
{

    // Liberar todos os nós da lista com free
    if(b->primeiro == NULL)return;

    NoLivro* atual = b->primeiro;

    while (atual != NULL)
    {
        NoLivro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    b->primeiro = NULL;
    b->totalLivros = 0;
    


}