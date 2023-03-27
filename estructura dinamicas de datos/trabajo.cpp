#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

typedef struct Notas{
	float a, b, c, d;
	struct Notas* sgte;
}notas;

typedef struct aplazados{
	float a, b, c, d;
	struct aplazados* sgte;
}aplazados;

typedef struct aprobados{
	float a, b, c, d;
	struct aprobados* sgte;
} aprobados;


typedef notas *puntero0;
typedef aplazados *puntero1;
typedef aprobados *puntero2;

void agregar(puntero0 *cza, float uno, float dos, float tres);
void agregar_aplazados(puntero1 *cza_aplazados, float uno, float dos, float tres);
void maplazados (puntero1 cza_aplazados);
void agregar_aprobados(puntero2 *cza_aprobados, float uno, float dos, float tres);
void maprobados (puntero2 cza_aprobados);
void mnotas (puntero0 cza, int contador_aprobados, int contador_aplazados);

bool es_nota(float nota);

int main(){

    system("color F0");

	int exit=0, op=0, i, contador_aprobados=0, contador_aplazados=0;
	float uno,dos,tres;
	puntero0 cza;
	puntero1 cza_aplazados;
	puntero2 cza_aprobados;
	cza=NULL;
	cza_aprobados= NULL;
	cza_aplazados= NULL;

	do{
		system("cls");

		printf("\n1.Agregar notas\n2.opciones de notas\n0.Salir\n\n   Seleccione una opcion: ");
		scanf("%d", &op);

		switch(op){
			case 1:{
            system ("cls");
				for(i=0; i<3; i++){
					if(i==0){
						printf("-Ingrese la nota %d del estudiante: ", i+1); scanf("%f", &uno);
					}
					if(i==1){
						printf("\n-Ingrese la nota %d del estudiante: ", i+1); scanf("%f", &dos);
					}
					if(i==2){
						printf("\n-Ingrese la nota %d del estudiante: ", i+1); scanf("%f", &tres);
					}
				}

				printf("\npresione [enter] para regresar");
			if (es_nota(uno) && es_nota(dos) && es_nota(tres)) {

				agregar(&cza, uno,dos,tres);



				if((uno+dos+tres)/3 < 9.5){

					agregar_aplazados (&cza_aplazados, uno, dos, tres);
					contador_aplazados++;
				}else{

					agregar_aprobados (&cza_aprobados, uno, dos, tres);
					contador_aprobados++;
				}
        getch();
      } else {

        printf("\nERROR nota negativa o mayor de 20  vuelva a intentar");
        getch();

      }

				break;
			}
			case 2:{

				if(cza!=NULL){
					do{
						system("cls");

						printf("-Mostrar notas.\n");
						printf("\n1.Mostrar notas\n");
						printf("2.Mostrar aprobadas\n");
						printf("3.Mostrar aplazadas\n");
						printf("0.Atras\n");

						printf("\ningresse la opcion que desea selecionar: "); scanf("%d", &op);

						switch(op){
							case 1:{
								mnotas(cza, contador_aprobados, contador_aplazados);
								getch();
								break;
							}
							case 2:{
								maprobados (cza_aprobados);
								getch();
								break;
							}
							case 3:{
								maplazados (cza_aplazados);
								getch();
								break;
							}
							case 0: {
								exit=1;
								break;
							}
							default:{
								printf("\nno tenemos esa opcion, intentelo de nuevo\n");
								getch();
								break;
							}
						}
					}while(exit!=1);
				}else{
					printf("\ningrese las notas, intente de nuevo.");
				}
				exit=0;
				break;

			}
			case 0:{

				exit=1;

				break;
			}
			default:{

				printf("\nno tenemos esa opcion, intentelo de nuevo\n");

				getch();
				break;
			}
		}
	}while(exit!=1);

	return 0;
}

void agregar(puntero0* cza, float uno, float dos, float tres){
	puntero0 nuevo;
	nuevo = (puntero0)malloc(sizeof(notas));
	nuevo->a = uno;
	nuevo->b = dos;
	nuevo->c = tres;
	nuevo->d = ((uno + dos + tres) / 3);
	nuevo->sgte = *cza;
	*cza=nuevo;
}

bool es_nota(float nota){
    return (nota >= 0 && nota <= 20);}

void agregar_aplazados(puntero1 *cza_aplazados, float uno, float dos, float tres){
	puntero1 nuevo;
	nuevo = (puntero1)malloc(sizeof(aplazados));
	nuevo->a = uno;
	nuevo->b = dos;
	nuevo->c = tres;
	nuevo->d = ((uno +dos + tres) / 3);
	nuevo->sgte = *cza_aplazados;
	*cza_aplazados=nuevo;
}

void agregar_aprobados(puntero2 *cza_aprobados, float uno, float dos, float tres){
	puntero2 nuevo;
	nuevo = (puntero2)malloc(sizeof(aprobados));
	nuevo->a = uno;
	nuevo->b = dos;
	nuevo->c = tres;
	nuevo->d = ((uno + dos + tres) / 3);
	nuevo->sgte= *cza_aprobados;
	*cza_aprobados=nuevo;
}

void mnotas (puntero0 cza, int contador_aplazados , int contador_aprobados){
	system("cls");

	printf("Notas: \n");

    printf("\nlistado de notas:\n");

	while(cza!=NULL){
		printf("\n| %.2f |", cza->a);
		printf(" %.2f |", cza->b);
		printf(" %.2f |", cza->c);
		printf(" = | %.2f | \n", cza->d);
		cza=cza->sgte;
	}
	printf("\nCantidad de Estudiantes Aplazados: %d\n", contador_aplazados);
	printf("Cantidad de Estudiantes Aprobados: %d\n", contador_aprobados);
	printf("\n\n presione [enter] para regresar al menu anterior");
}

void maplazados (puntero1 cza_aplazados){
	system("cls");

	printf("Notas Aplazadas: \n");
	if(cza_aplazados!=NULL){
		while(cza_aplazados!=NULL){
			printf("\n| %.2f |", cza_aplazados->a);
			printf(" %.2f |", cza_aplazados->b);
			printf(" %.2f |", cza_aplazados->c);
			printf(" = | %.2f | \n", cza_aplazados->d);
			cza_aplazados=cza_aplazados->sgte;

		}
		printf("\n\n presione [enter]");
	}else{
		printf("\nno hay estudiantes aplazados");
	}
}

void maprobados (puntero2 cza_aprobados){
	system("cls");

	printf("Notas Aprobadas: \n");
	if(cza_aprobados!=NULL){
		while(cza_aprobados!=NULL){
			printf("\n| %.2f |", cza_aprobados->a);
			printf(" %.2f |", cza_aprobados->b);
			printf(" %.2f |", cza_aprobados->c);
			printf(" = | %.2f | \n", cza_aprobados->d);
			cza_aprobados=cza_aprobados->sgte;
		}
		printf("\n\n presione [enter]");
	}else{
		printf("\nno hay estudiantes aprobados");
	}
}

