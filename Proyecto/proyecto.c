/*
 * proyecto.c
 *
 *  Created on: 08/05/2015
 *      Author: is698050
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 250
char frase_raiz[SIZE] =
		{
				"Había una vez un niño al que le gustaba mucho jugar con sus juguetes y siempre quería regresar pronto de la escuela para jugar. Hasta que un día..." };
char frase_uno[SIZE] =
		{
				"El gato salto al agua y no lo podía creer, de nuevo tenía que correr a sacarlo. Cuando entre al baño entonces..." };
char frase_dos[SIZE] =
		{
				"¡La niña avento lodo a mi cara!, ahora estaba todo sucio: mi playera, mis pantalones y mis zapatos, mi madre se enojará pero entonces le dire que..." };
char frase_tres[SIZE] =
		{
				"El gato se comió al pez, pero aún así el gato estaba triste. Miro como la pecera estaba vacía y una lagrima corrió por su mejilla, lo único peor que podía pasar en ese momento era que..." };
char frase_cuatro[SIZE] =
		{
				"La princesa hizo el aceo, limpiaba y limpiaba todos los días pero nunca termina, pero siempre hay alguien que termina ensuciandolo todo de nuevo... pero de pronto..." };
char frase_cinco[SIZE] =
		{
				"El bombero se puso un tutu y ¡corrió a la calle a cumplir su sueño!, al fin era libre de ser quien era realmente y nadie podía pararlo. Aunque eso cambio cuando..." };
char frase_seis[SIZE] =
		{
				"El antro estaba bien lleno. Mis amigos y yo no sabiamos si entrar o quedarnos afuera. Mi amiga estaba medio borracha cuando se le acerca un tipo y le dice algo, al parecer..." };
char frase_siete[SIZE] =
		{
				"El vaquero es rapero y está a punto de grabar su nuevo disco, mi jefe quiere contratarlo pero no puede contratar vaqueros. De pronto toda la familia del vaquero estaba en el estudio para reclamarle a mi jefe que..." };
char frase_ocho[SIZE] =
		{
				"El lobo tenía miedo, pero también tenía hambre. Una tierna oveja estaba pastando cerca de su territorio, no podía evitarlo, corrío hacia ella y cuando le hiba a soltar la mordida escucho decir que..." };
char frase_nueve[SIZE] =
		{
				"Olía como a animal muerto, aunque llevaba días sin ducharse, sabía que el olor no podía provenir de él. Cuando tomó la bolsa de basura, de pronto se dio cuenta de que..." };
char frase_diez[SIZE] =
		{
				"La gente le aplaudia y grababa, se dio cuenta de que todo era un show de televisión, no podía creerlo. Cuando tuvo la oportunidad saludo a sus padres, pero despúes el conductor dijo que..." };
char frase_once[SIZE] =
		{
				"Se rompió el jarrón favorito de su tía, si alguien decía que había sido él, estaría muerto. Escucho a alguien bajar de las escaleras rapidamente hasta que..." };
char frase_doce[SIZE] =
		{
				"Mi amigo corrió a empujarlo, su caída parecía infinita, pobre de Juan, de seguro nos hiba a acusar con la maestra. Estabamos saliendo del salón cuando de pronto..." };
char frase_trece[SIZE] =
		{
				"¡La princesa beso al sapo!, sabía asqueroso y nada había sucedido, lo bueno es que nadie había visto lo que sucedió, hasta que..." };
char frase_catorce[SIZE] =
		{
				"El viaje familiar había comenzado y yo estaba llegando tarde, de seguro hiba a resivir reclamos de todos cuando llegara o peor aún cargarían todo a su tarjeta. Lo único bueno era que..." };
char frase_quince[SIZE] =
		{
				"Corrimos tomados de la mano hacia el horizonte. Lo mire a los ojos, nada podía salir mal en ese momento. Él me miro de pronto y me mordió la mano entonces..." };

int numeros[14] = { 1, 2, 8, 11, 4, 5, 9, 12, 7, 10, 3, 14, 6, 13, 15 };

typedef struct opcion {
	char texto[SIZE];
	struct opcion *izq, *der;
} OPCION;

OPCION * crearOpcion(char *frase) {
	OPCION * nuevaOpcion = (OPCION *) malloc(sizeof(OPCION));
	strcpy(nuevaOpcion->texto, frase);

	nuevaOpcion->der = NULL;
	nuevaOpcion->izq = NULL;

	return nuevaOpcion;

}

void imprimirArbol(OPCION *raiz) {

	int op = 0;

	if (raiz == NULL) {

		printf("Aun no hay historia cargada. \n");

	} else {

		if (raiz->der != NULL && raiz->izq != NULL) {

			printf("\n%s\n\n", raiz->texto);
			printf("1. %s\n\n", raiz->izq->texto);
			printf("2. %s\n\n", raiz->der->texto);
			scanf("%d", &op);

			if (op == 1) {

				imprimirArbol(raiz->izq);

			}

			else {

				imprimirArbol(raiz->der);

			}

		} else {

			printf("Llegó el FIN\n");
			printf("\n");
			printf("¡¡Gracias por participar!!\n\n");

			printf("Volverá al menú principal\n\n");

		}

	}
}

void inicializarArreglo(int numeros[]) {

	int i;

	for (i = 0; i < 13; i++) {

		numeros[i] = 0;

	}

}

void llenarArreglo(int numeros[]) {

	int i;
	int numero;
	int j;
	int flag = 0;

	for (i = 0; i < 15; i++) {

		numero = 1+ rand() % (15-1);

		if (numero <= 15) {

			for (j = 0; j < 15; j++) {

				if (numeros[j] == numero) {

					flag = 1;
					numero++;

				}



				}
			if (flag != 1 && numeros[i] == 0) {

								numeros[i] = numero;
			}
		}
	}

	for (i = 0; i < 14; i++) {

		printf("%d, ", numeros[i]);

	}

}

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);

	int op;

	int i;

	int cual_frase;

	OPCION * raiz = (OPCION *) malloc(sizeof(OPCION));
	strcpy(raiz->texto, frase_raiz);

	raiz->der = NULL;
	raiz->izq = NULL;

	OPCION * raiz1;
	OPCION * raiz2;
	OPCION * raiz3;
	OPCION * raiz4;
	OPCION * raiz5;
	OPCION * raiz6;
	OPCION * raiz7;
	OPCION * raiz8;
	OPCION * raiz9;
	OPCION * raiz10;
	OPCION * raiz11;
	OPCION * raiz12;
	OPCION * raiz13;
	OPCION * raiz14;

	//inicializarArreglo(numeros);
	//llenarArreglo(numeros);


	for (i = 0; i < 15; i++) {

		cual_frase = numeros[i];

		switch (cual_frase) {

		case 1:

			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_uno);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_uno);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_uno);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_uno);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_uno);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_uno);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_uno);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_uno);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_uno);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_uno);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_uno);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_uno);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_uno);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_uno);

				raiz6->izq = raiz14;

				break;
			}
			break;

		case 2:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_dos);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_dos);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_dos);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_dos);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_dos);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_dos);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_dos);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_dos);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_dos);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_dos);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_dos);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_dos);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_dos);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_dos);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 3:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_tres);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_tres);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_tres);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_tres);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_tres);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_tres);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_tres);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_tres);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_tres);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_tres);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_tres);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_tres);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_tres);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_tres);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 4:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_cuatro);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_cuatro);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_cuatro);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_cuatro);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_cuatro);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_cuatro);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_cuatro);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_cuatro);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_cuatro);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_cuatro);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_cuatro);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_cuatro);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_cuatro);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_cuatro);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 5:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_cinco);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_cinco);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_cinco);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_cinco);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_cinco);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_cinco);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_cinco);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_cinco);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_cinco);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_cinco);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_cinco);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_cinco);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_cinco);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_cinco);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 6:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_seis);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_seis);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_seis);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_seis);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_seis);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_seis);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_seis);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_seis);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_seis);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_seis);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_seis);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_seis);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_seis);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_seis);

				raiz6->izq = raiz14;

				break;
			}
			break;

		case 7:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_siete);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_siete);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_siete);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_siete);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_siete);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_siete);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_siete);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_siete);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_siete);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_siete);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_siete);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_siete);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_siete);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_siete);

				raiz6->izq = raiz14;

				break;
			}

			break;

		case 8:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_ocho);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_ocho);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_ocho);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_ocho);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_ocho);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_ocho);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_ocho);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_ocho);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_ocho);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_ocho);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_ocho);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_ocho);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_ocho);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_ocho);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 9:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_nueve);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_nueve);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_nueve);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_nueve);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_nueve);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_nueve);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_nueve);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_nueve);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_nueve);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_nueve);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_nueve);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_nueve);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_nueve);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_diez);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 10:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_diez);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_diez);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_diez);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_diez);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_diez);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_diez);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_diez);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_diez);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_diez);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_diez);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_diez);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_diez);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_diez);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_diez);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 11:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_once);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_once);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_once);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_once);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_once);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_once);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_once);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_once);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_once);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_once);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_once);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_once);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_once);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_once);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 12:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_doce);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_doce);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_doce);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_doce);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_doce);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_doce);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_doce);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_doce);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_doce);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_doce);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_doce);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_doce);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_doce);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_doce);

				raiz6->izq = raiz14;

				break;
			}
			break;
		case 13:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_trece);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_trece);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_trece);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_trece);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_trece);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_trece);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_trece);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_trece);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_trece);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_trece);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_trece);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_trece);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_trece);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_trece);

				raiz6->izq = raiz14;

				break;
			}
			break;

		case 14:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_catorce);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_catorce);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_catorce);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_catorce);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_catorce);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_catorce);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_catorce);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_catorce);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_catorce);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_catorce);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_catorce);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_catorce);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_catorce);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_catorce);

				raiz6->izq = raiz14;

				break;
			}
			break;

		case 15:
			switch (i) {

			case 0:
				raiz1 = crearOpcion(frase_quince);

				raiz->der = raiz1;

				break;

			case 1:
				raiz2 = crearOpcion(frase_quince);

				raiz->izq = raiz2;

				break;
			case 2:
				raiz3 = crearOpcion(frase_quince);

				raiz1->der = raiz3;

				break;
			case 3:
				raiz4 = crearOpcion(frase_quince);

				raiz1->izq = raiz4;

				break;
			case 4:
				raiz5 = crearOpcion(frase_quince);

				raiz2->der = raiz5;

				break;
			case 5:
				raiz6 = crearOpcion(frase_quince);

				raiz2->izq = raiz6;

				break;
			case 6:
				raiz7 = crearOpcion(frase_quince);

				raiz3->der = raiz7;

				break;
			case 7:
				raiz8 = crearOpcion(frase_quince);

				raiz3->izq = raiz8;

				break;
			case 8:
				raiz9 = crearOpcion(frase_quince);

				raiz4->der = raiz9;

				break;
			case 9:
				raiz10 = crearOpcion(frase_quince);

				raiz4->izq = raiz10;

				break;
			case 10:
				raiz11 = crearOpcion(frase_quince);

				raiz5->der = raiz11;

				break;
			case 11:
				raiz12 = crearOpcion(frase_quince);

				raiz5->izq = raiz12;

				break;
			case 12:
				raiz13 = crearOpcion(frase_quince);

				raiz6->der = raiz13;

				break;
			case 13:
				raiz14 = crearOpcion(frase_quince);

				raiz6->izq = raiz14;

				break;
			}
			break;

		}

	}

	while (op != 2) {

		printf(
				"-----------------------------------¡Bienvenido!-----------------------------------\n\n");
		printf(
				"Esto es un historia en la que puedes tomar decisiones, tú creas la historia.\n\n");
		printf("¿Desea comenzar?\n");
		printf("1) Sí.\n");
		printf("2) No, salir.\n");
		scanf("%d", &op);
		printf(
				"-----------------------------------------------------------------------------------\n\n");
		if (op != 2) {
			printf(
					"\n\nEsto es una historia aleatoria, escoge las opciones que creas más indicadas. \n\n");

			imprimirArbol(raiz);

		} else {

			printf("Gracias por participar :D. \n\n");
		}

	}

	return 0;
}

