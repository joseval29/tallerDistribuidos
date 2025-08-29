#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: J. Corredor
#     Fecha: Febrero 2024
#     Materia: Sistemas Operativos
#     Tema: Taller de EvaluaciÃ³n de Rendimiento
#     Fichero: script automatizaciÃ³n ejecuciÃ³n por lotes 
#****************************************************************/

# Obtiene el directorio actual de trabajo y lo guarda en $Path
$Path = `pwd`;
chomp($Path);   # Elimina el salto de linea final de la cadena devuelta por pwd

# Nombre del ejecutable a probar
$Nombre_Ejecutable = "mmClasicaOpenMP";

# Lista de tamanos de matriz a probar
@Size_Matriz = ("5000","10000","15000","20000");

# Lista de numeros de hilos a usar en cada prueba
@Num_Hilos = (1,2,4,8,16,20);

# Numero de repeticiones que se ejecutara cada prueba
$Repeticiones = 30;

# Bucle externo: recorre cada tamano de matriz
foreach $size (@Size_Matriz){
    # Bucle interno: recorre cada numero de hilos
    foreach $hilo (@Num_Hilos) {

        # Construye el nombre del archivo de salida para esta combinacion
        # Ejemplo: ./mmClasicaOpenMP-5000-Hilos-4.dat
        $file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";

        # Repite la ejecucion $Repeticiones veces
        for ($i=0; $i<$Repeticiones; $i++) {
            # Ejecuta el programa con argumentos (tamano, hilos) y redirige salida a $file
            system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");

            # Imprime en pantalla el comando ejecutado (informacion de avance)
            printf("$Path/$Nombre_Ejecutable $size $hilo \n");
        }

        # Cierra el archivo (aunque aqui $file es solo un nombre, no un descriptor abierto)
        close($file);

        # Incrementa un contador (pero la variable $p nunca fue inicializada ni usada despues)
        $p=$p+1;
    }
}
