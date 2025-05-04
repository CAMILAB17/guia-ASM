#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "Estructuras.h"

int main() {
	// ----- Test para cantidad_total_de_elementos -----
	nodo_t* nodo3 = malloc(sizeof(nodo_t));
	nodo3->longitud = 10;
	nodo3->next = NULL;

	nodo_t* nodo2 = malloc(sizeof(nodo_t));
	nodo2->longitud = 20;
	nodo2->next = nodo3;

	nodo_t* nodo1 = malloc(sizeof(nodo_t));
	nodo1->longitud = 30;
	nodo1->next = nodo2;

	lista_t lista;
	lista.head = nodo1;

	uint32_t resultado = cantidad_total_de_elementos(&lista);
	printf("Resultado: %u\n", resultado);
	assert(resultado == 60); // 30 + 20 + 10

	free(nodo1);
	free(nodo2);
	free(nodo3);
	
	// ----- Test para cantidad_total_de_elementos_packed -----
	packed_nodo_t* pnodo3 = malloc(sizeof(packed_nodo_t));
	pnodo3->longitud = 5;
	pnodo3->next = NULL;

	packed_nodo_t* pnodo2 = malloc(sizeof(packed_nodo_t));
	pnodo2->longitud = 15;
	pnodo2->next = pnodo3;

	packed_nodo_t* pnodo1 = malloc(sizeof(packed_nodo_t));
	pnodo1->longitud = 25;
	pnodo1->next = pnodo2;

	packed_lista_t plista;
	plista.head = pnodo1;

	uint32_t presultado = cantidad_total_de_elementos_packed(&plista);
	printf("Resultado (packed): %u\n", presultado);
	assert(presultado == 45); // 25 + 15 + 5

	free(pnodo1);
	free(pnodo2);
	free(pnodo3);

	return 0;
}
