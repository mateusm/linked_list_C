#ifndef PRATICA04_H
#define PRATICA04_H
#define NUM_ELEMENTOS 100
typedef int Dado;
	typedef struct lista {
	Dado lista[NUM_ELEMENTOS];
	int tamanho;
} ListaSeq;
	void criaLista(ListaSeq*);
	int insere(Dado*, int, ListaSeq*);
	Dado* deleta(int, ListaSeq*);
	Dado* pega_item(int, ListaSeq*);
	int altera_item(Dado*, int, ListaSeq*);
	// Para fins de debug - implementar impressao da lista
	void imprime(ListaSeq*);
	#endif
	/* PRATICA04_H */
