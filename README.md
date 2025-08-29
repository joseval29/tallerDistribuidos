1. Objetivo
El objetivo es multiplicar matrices cuadradas grandes usando el algoritmo clasico y aplicar paralelismo con OpenMP para mejorar el rendimiento. Luego, se mide el tiempo de ejecucion para distintas dimensiones de matriz y distintos numeros de hilos, se guardan los resultados y se calculan estadisticas como media y desviacion estandar.
2. Codigo en C (mmClasicaOpenMP.c)
- Implementa la multiplicacion clasica de matrices C = A x B.
- Las matrices se almacenan en arreglos 1D (row-major).
- Funciones principales:
   * iniMatrix → inicializa matrices con numeros aleatorios.
   * multiMatrix → hace la multiplicacion triple bucle, paralelizada con OpenMP.
   * InicioMuestra y FinMuestra → miden tiempo en microsegundos.
- Argumentos del programa:
   * N → tamano de la matriz.
   * TH → numero de hilos.
- Imprime tiempos de ejecucion y matrices pequeñas (N < 9).
3. Makefile
- Facilita la compilacion y ejecucion.
- Usa gcc -fopenmp -O3 para compilar con soporte OpenMP y optimizacion.
- Targets:
   * make → compila el programa.
   * make run → ejemplo de ejecucion.
   * make bench → bateria de pruebas.
   * make clean → limpia ejecutables y resultados.
4. Script de lanzamiento (lanzador.pl)
- Automatiza pruebas con varios tamanos de matriz y hilos.
- Parametros:
   * Tamanos: 5000, 10000, 15000, 20000.
   * Hilos: 1, 2, 4, 8, 16, 20.
   * Repeticiones: 30.
- Guarda resultados en archivos .dat.
- Cada archivo contiene 30 tiempos.
5. Resultados (.dat → Excel/CSV)
- A partir de los .dat se calcularon:
   * Media (tiempo promedio).
   * Desviacion estandar.
- Se genero un Excel/CSV con columnas:
   Tamaño_matriz | Hilos | N_datos | Media | Desviacion_Estandar | Archivo.
- Permite graficar Tiempo vs Hilos, Speedup y Eficiencia.
6. Plan de pruebas
- Se pide medir 12 tamanos menores a 14K y con hilos {1, 4, 8, 16, 20}.
- Repeticiones: 30 por combinacion.
- Con esto se obtiene base estadistica solida.
Resumen
1. Codigo C → multiplica matrices NxN con OpenMP.
2. Makefile → compila y ejecuta pruebas.
3. Script Perl → automatiza ejecuciones y genera .dat.
4. Archivos .dat → contienen tiempos de ejecucion.
5. Excel/CSV → resume resultados con media y desviacion estandar.
6. Analisis → se calculan speedup, eficiencia y escalabilidad.
