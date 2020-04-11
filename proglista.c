/*
*********************************
* Programa testador do TAD Lista
*********************************
*/
#include <stdio.h>
#include "lista.h"

int main()
{
    // criando a lista vazia
	TipoLista* lista;
	lista = InicializaLista();

   // criando alguns alunos apenas para testar (mais adequado seria carregar de um arquivo)
    TipoItem* maria = InicializaTipoItem("maria", 123, "rua da maria");
    TipoItem* sofia = InicializaTipoItem("sofia", 2345, "rua da sofia");
    TipoItem* jose = InicializaTipoItem("jose", 4523, "rua do jose");
    TipoItem* joao = InicializaTipoItem("joao", 34, "rua do joao");
    TipoItem* catarina = InicializaTipoItem("catarina", 987, "rua da catarina");
    
    //Insere os alunos na lista
    Insere(maria, lista);
    Insere(sofia, lista);
    Insere(jose, lista);
    Insere(joao, lista);
    Insere(catarina, lista);
    
    //Imprime a lista com todos os alunos
    Imprime(lista);

    //Retira a maria da lista e imprime
    TipoItem* retirado = Retira(lista, 123);
    if (retirado != NULL)
    	Imprime(lista);
    else
    	printf ("Nao foi possivel retirar o aluno de matricula 123\n");

    //Retira o Joao da lista e imprime
    retirado = Retira(lista, 34);
    if (retirado != NULL)
    	Imprime(lista);
    else
    	printf ("Nao foi possivel retirar o aluno de matricula 34\n");


     //Tenta retirar com um n�mero de matr�cula inexistente
      retirado = Retira(lista, 555);
      if (retirado != NULL)
      	Imprime(lista);
      else
      	printf ("Nao foi possivel retirar o aluno de matricula 555\n");
     

      lista = Libera(lista);       
}
