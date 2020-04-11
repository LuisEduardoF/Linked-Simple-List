#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa??o do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
struct tipoitem{
  char  *nome, *endereco;
  int matricula;
};
int exist_item(TipoItem* x){
	return x != NULL;
}
void freeAluno(TipoItem* x){
	free(x->nome);
	free(x->endereco);
}
typedef struct cell{
	TipoItem aluno;
	struct cell *prox;
}Celula;


struct tipolista{
	Celula *fst, *end;
};
int exist_list(TipoLista* x){
	return x != NULL;
}
/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos fst e end apontam para NULL
*/
TipoLista* InicializaLista(){
   TipoLista* x = malloc(sizeof(TipoLista));
   x->fst = NULL;
   x->end = NULL;
   return x;
}

/*Insere um aluno na primeira posi??o da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista n?o s?o nulos
* pos-condicao: lista cont?m o aluno inserido na primeira posi??o
*/
void Insere(TipoItem *x, TipoLista * lista) {
	Celula* novo = malloc(sizeof(Celula));
	if(!exist_list(lista)){
		printf("Lista não existe. Abortando...\n");
		exit(1);
	}
	if(!exist_item(x)){
		printf("Item não existe. Abortando...\n");
		exit(1);
	}
	if (lista -> end == NULL){
		lista -> fst = novo;
		lista -> end = novo;
	}
	else {
		lista->end->prox = novo;
		lista->end = lista->end->prox;
	}
	lista->end->aluno = *x;
	free(x);
	lista->end->prox = NULL;
}
/*Retira um aluno de matr?cula mat da lista de alunos
* inputs: a lista e a matr?cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n?o se encontrar na lista
* pre-condicao: lista n?o ? nula
* pos-condicao: lista n?o cont?m o aluno de matr?cula mat
*/
TipoItem* Retira (TipoLista* lista, int mat){
	if(!exist_list(lista)){
		printf("Lista não existe. Abortando...\n");
		exit(1);
	}
	Celula* ant = NULL;
	void* aux;
	Celula* p = lista->fst;
	
	while (p != NULL && p->aluno.matricula != mat) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL){
		return NULL;
	}
	if (p == lista->fst && p == lista->end) {
		lista->fst = lista->end = NULL;
	}
	if (p == lista->end) {
		lista->end = ant;
		ant->prox = NULL;
	}
	if (p == lista->fst){
		lista->fst = p->prox;
	}
	else{
		ant->prox = p->prox;
	}
	aux = &p->aluno;
	freeAluno(&p->aluno);
	free(p);
	return aux;
}


/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista n?o ? nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoLista* lista){
	if(!exist_list(lista)){
		printf("Lista não existe. Abortando...\n");
		exit(1);
	}
	Celula* p = lista->fst;
	
	for(p = p; p != NULL; p = p->prox){
		printf("%d ) Nome: %s |Endere�o: %s|\n", p->aluno.matricula, p->aluno.nome, p->aluno.endereco);
	}
	printf("\n\n");
}

/*Libera toda a mem?ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: lista vazia (NULL)
* pre-condicao: lista n?o ? nula
* pos-condicao: mem?ria alocada ? liberada
*/
TipoLista* Libera (TipoLista* lista){
	if(!exist_list(lista)){
		printf("Lista não existe. Abortando...\n");
		exit(1);
	}
	Celula* p = lista->fst, *aux = NULL;
	for(p = p; p != NULL; p = aux){
		aux = p->prox;
		freeAluno(&p->aluno);
		free(p);
	}
	free(lista);
	return lista;
}


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
	TipoItem* aux = malloc(sizeof(TipoItem));
	aux->nome = strdup(nome);
	aux->endereco = strdup(endereco);
	aux->matricula = matricula;
	return aux;
}

