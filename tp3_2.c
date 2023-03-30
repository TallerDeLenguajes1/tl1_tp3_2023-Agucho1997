#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.
*/
#define M 5
#define N 12
void promedio(int matriz[M][N]);
void buscar(int matriz[M][N]);
int main() {
        int matriz[M][N];
    srand(time(NULL));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 40001 + 10000;
        }
    }

    for (int i = 0; i < M; i++) {
        printf("|");
        for (int j = 0; j < N; j++) {
            printf("%d \t", matriz[i][j]);
        }
        printf("|\n");
    }

    promedio(matriz);
    buscar(matriz);
    return 0;
}

void promedio(int matriz[M][N]) {
    int promedio[M];
    for (int i = 0; i < M; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma = suma + matriz[i][j];
        }
        promedio[i] = suma / 12;
    }

    printf("Promedio por anio: \n");

    for (int i = 0; i < M; i++) {
        printf("anio %d: $%d\n", i + 2018, promedio[i]);
    }
}
void buscar(int matriz[M][N]) {
    int mayor, menor;
    int anio_mayor, anio_menor;
    int mes_mayor, mes_menor;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0) {
                mayor = matriz[i][j];
                menor = matriz[i][j];
            } else {
                if (mayor < matriz[i][j]) {
                    mayor = matriz[i][j];
                    anio_mayor = i + 2018;
                    mes_mayor = j + 1;
                }
                if (menor > matriz[i][j]) {
                    menor = matriz[i][j];
                    anio_menor = i + 2018;
                    mes_menor = j + 1;
                }
            }
        }
    }

    printf("La mayor ganacia es: $%d\n", mayor);
    printf("Se dio el mes %d del anio: %d\n", mes_mayor, anio_mayor);
    printf("\n\n");
    printf("La menor ganacia es: $%d\n", menor);
    printf("Se dio el mes %d del anio: %d\n", mes_menor, anio_menor);
}