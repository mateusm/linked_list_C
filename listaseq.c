#include <stdio.h>
#include <stdlib.h>
#include "listaseq.h"


void criaLista(ListaSeq* l){
	l->tamanho = 0;
}

int insere(Dado* d, int ind, ListaSeq* l){
	int i;
	if(l->tamanho < NUM_ELEMENTOS && ind < NUM_ELEMENTOS) {
		if(ind >= 0 && ind < l->tamanho){
			for(i = l->tamanho; i > ind; i--){
				l -> lista[i] = l->lista[i-1];
			}
			l->lista[ind] = *d;
			l->tamanho++;
			return 1;
		}else{
			if(ind == l->tamanho){
				l->lista[ind] = *d;
				l->tamanho++;
				return 1;
			}else
				printf("Erro ao inserir!");
		}
		
	}else
		printf("Erro ao inserir !");
	return 0;
}


Dado* deleta(int ind, ListaSeq* l){
	int i;
	Dado aux;
	if(ind >= NUM_ELEMENTOS) exit(1);
	aux = l->lista[ind];
	if (ind >= 0 && ind <= l->tamanho){
		for(i = ind; i < l->tamanho-1;i++){
			l->lista[i] = l->lista[i+1];
		}
		l->tamanho--;
	}else printf("Erro ao deletar!");
	return aux;
}

Dado* pega_item(int ind, ListaSeq* l){
	return l->lista[ind];
}

int altera_item(Dado* d, int ind, ListaSeq* l){
	if(ind <= l->tamanho){
		l->lista[ind] = *d;
	}else printf("Erro ao alterar");
	return l->lista[ind];
}

void imprime(ListaSeq* l){
	int i;
	for(i = 0; i < l->tamanho;i++){
		printf("Valor no indice %i é %i\n", i, l->lista[i]);
	}
}

// Para os testes...
void menu(ListaSeq *l){

	int opcao;
	Dado *d;
	d = malloc(sizeof(Dado));
	int i;
	printf("\n\n\tMENU:\n\n");
	printf("1: Inserir dado\n\n");
	printf("2: Remover dado\n\n");
	printf("3: Pegar dado\n\n");
	printf("4: Alterar dado\n\n");
	printf("5: Imprimir Lista\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &opcao);
	switch (opcao){
		case 1:
			printf("Digite o valor: \n");
			scanf("%d", d);
			printf("Digite o indice: \n");
			scanf("%d", &i);
			insere(d, i, l);
			menu(l);
			break;
		case 2:
			printf("Digite o indice: \n");
			scanf("%d", &i);
			deleta( i, l);
			menu(l);
			break;
		case 3:
			printf("Digite o indice: \n");
			scanf("%d", &i);
			pega_item(i, l);
			menu(l);
			break;
		case 4:
			printf("Digite o valor: \n");
			scanf("%d", d);
			printf("Digite o indice: \n");
			scanf("%d", &i);
			altera_item(d, i, l);
			menu(l);
			break;
		case 5:
			imprime(l);
			menu(l);
			break;
	}
}

int main(){
	ListaSeq *l;
	l = malloc(sizeof(ListaSeq));
	menu(l);
	return 0;
}
