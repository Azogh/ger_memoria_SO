# Ger-ncia-de-mem-ria---SO
Trabalho de Sistemas Operacionais - Carecão

first-fit: inicia a procura a partir da primeira página de memória (parte baixa) e vai
varrendo a memória até encontrar a primeira lacuna suficientemente grande para armazenar
o processo.
2. best-fit: varre toda a memória e escolhe a página mais ajustada ao tamanho do processo.
3. worst-fit: varre toda a memória e escolhe a página menos ajustada ao tamanho do
processo.
4. next-fit: segue a mesma idéia do first-fit, mas somente a primeira busca é iniciada na parte
baixa da memória (primeira página), as outras iniciam onde terminou a última. Usa-se uma
lista circular para permitir que, eventualmente, toda a memória seja percorrida. 

 https://prepinsta.com/operating-systems/page-replacement-algorithms/worst-fit/worst-fit-in-c/





#include 

struct Nodo {

	int info;
	struct Nodo *prox;

};

struct ListaSimplesEnc {

	struct Nodo *prim;

};

void criarLista (struct ListaSimplesEnc *pList) {

	pList -> prim = NULL;

}

void mostrarLista (struct ListaSimplesEnc *pList){

	struct Nodo *p;

	for (p = pList -> prim; p != NULL; p = p->prox) {

		printf("%d\t", p->info);

	}

	printf("\n");

}

void inserirIni (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc (sizeof (struct Nodo));
	novo -> info = v;
	novo -> prox = pList -> prim;
	pList -> prim = novo;
}

void removerIni (struct ListaSimplesEnc *pList){

	struct Nodo *pAux = pList -> prim;
	pList -> prim = pList -> prim -> prox;
	free(pAux);

}

void inserirOrd (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc (sizeof (struct Nodo));
	novo -> info = v;
	
	struct Nodo *pAtu, *pAnt;

	pAnt = NULL;
	pAtu = pList -> prim;

	while ( pAtu != NULL && pAtu->info < v){

		pAnt = pAtu;
		pAtu = pAtu -> prox;

	}

	novo -> prox = pAtu -> prox;
	pAnt -> prox = novo;
}

int estaVazia(struct ListaSimplesEnc *pList) {

	return (pList->prim == NULL);

}

void main () {
	struct ListaSimplesEnc minhaLista;
	int valor, op;

	criarLista(&minhaLista);

	while( 1 ){

		printf( "1 - Inserir elemento no inicio\n" );
		printf( "2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n" );
		printf( "3 - Remover elemento no inicio\n" );
		printf( "4 - Remover elemento\n" );
		printf( "5 - Mostrar lista\n" );
		printf( "6 - Sair\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );

		switch( op ){

			case 1: // inserir elemento no inicio
		
				printf( "Valor? " );
				scanf( "%d", &valor );
				inserirIni(&minhaLista, valor);
				break;
			case 2: // inserir elemento ordenado
				printf( "Valor? " );
				scanf( "%d", &valor );
				inserirOrd(&minhaLista, valor);
				break;
			case 3: // remover o primeiro
				break;
			case 4: // remover determinado elemento
				break;
			case 5: //  mostrar lista
				if (estaVazia(&minhaLista)) {
					printf("Lista vazia");
				}
				else {
					mostrarLista(&minhaLista);
				}
				break;
			case 6: // abandonar o programa
				exit(0);
		}

	}
}
