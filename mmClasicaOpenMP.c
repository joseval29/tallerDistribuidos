/*#######################################################################################
 #* Fecha:15-08-2025
 #* Autor:Jose Eduardo Valeriano Castiblanco 
 #* Tema: 
 #* 	- Programa Multiplicación de Matrices algoritmo clásico
 #* 	- Paralelismo con OpenMP
######################################################################################*/

#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>  
#include <time.h>     
#include <sys/time.h> 
#include <omp.h>      

// Variables globales para medir tiempo
struct timeval inicio, fin; 

// Funcion que guarda el tiempo de inicio
void InicioMuestra(){
    gettimeofday(&inicio, (void *)0);
}

// Funcion que guarda el tiempo de fin y calcula la diferencia
void FinMuestra(){
    gettimeofday(&fin, (void *)0);
    fin.tv_usec -= inicio.tv_usec;
    fin.tv_sec  -= inicio.tv_sec;
    double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec); 
    printf("%9.0f \n", tiempo); // imprime el tiempo en microsegundos
}

// Funcion para imprimir la matriz en pantalla
// Solo imprime si la dimension es menor que 9, para no saturar la salida
void impMatrix(double *matrix, int D){
    printf("\n");
    if(D < 9){
        for(int i=0; i<D*D; i++){
            if(i%D==0) printf("\n"); // salto de linea cada fila
            printf("%f ", matrix[i]);
        }
        printf("\n**-----------------------------**\n");
    }
}

// Inicializa dos matrices con numeros aleatorios entre 0 y 99
void iniMatrix(double *m1, double *m2, int D){
    for(int i=0; i<D*D; i++, m1++, m2++){
        *m1 = rand()%100;  
        *m2 = rand()%100;  
    }
}

// Multiplicacion clasica de matrices paralelizada con OpenMP
// mA y mB son las matrices de entrada, mC es la salida
void multiMatrix(double *mA, double *mB, double *mC, int D){
    double Suma, *pA, *pB;

    // Region paralela
    #pragma omp parallel
    {
        // Distribuye el bucle externo i entre los hilos
        #pragma omp for
        for(int i=0; i<D; i++){
            for(int j=0; j<D; j++){
                // pA apunta a la fila i de A
                pA = mA+i*D;    
                // pB apunta a la columna j de B
                pB = mB+j;    
                Suma = 0.0;
                // Recorre la fila i de A y la columna j de B
                for(int k=0; k<D; k++, pA++, pB+=D){
                    Suma += *pA * *pB;
                }
                // Almacena el resultado en C
                mC[i*D+j] = Suma;
            }
        }
    }
}

int main(int argc, char *argv[]){
    // Verifica que se pasen al menos 2 argumentos: tamano y numero de hilos
    if(argc < 3){
        printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
        exit(0);
    }

    // Dimension de la matriz y numero de hilos
    int N = atoi(argv[1]);
    int TH = atoi(argv[2]);

    // Reserva de memoria para tres matrices NxN
    double *matrixA  = (double *)calloc(N*N, sizeof(double));
    double *matrixB  = (double *)calloc(N*N, sizeof(double));
    double *matrixC  = (double *)calloc(N*N, sizeof(double));

    // Inicializa semilla aleatoria
    srand(time(NULL));

    // Define el numero de hilos de OpenMP
    omp_set_num_threads(TH);

    // Inicializa matrices A y B con numeros aleatorios
    iniMatrix(matrixA, matrixB, N);

    // Imprime A y B (solo si N < 9)
    impMatrix(matrixA, N);
    impMatrix(matrixB, N);

    // Toma tiempo, multiplica matrices y mide tiempo final
    InicioMuestra();
    multiMatrix(matrixA, matrixB, matrixC, N);
    FinMuestra();

    // Imprime matriz resultado (solo si N < 9)
    impMatrix(matrixC, N);

    // Libera memoria dinamica
    free(matrixA);
    free(matrixB);
    free(matrixC);
    
    return 0;
}