# Compilador
GCC = gcc

# Flags de compilacion basicos
CFLAGS = -Wall -Wextra -std=c11 -lm

# Flags para OpenMP (optimizacion + soporte multiproceso)
FOPENMP = -fopenmp -O3

# Flags para POSIX threads (no se usan aqui pero los dejamos por referencia)
POSIX = -lpthread

# Fuente principal (puedes cambiarlo si el archivo se llama distinto)
SRC = mmClasicaOpenMP.c

# Programas a compilar
PROGRAMAS = mmClasicaOpenMP

# Regla por defecto: compilar todos los programas
ALL: $(PROGRAMAS)

# Regla para compilar mmClasicaOpenMP
mmClasicaOpenMP: $(SRC)
	$(GCC) $(CFLAGS) $(FOPENMP) $< -o $@

# Limpieza: elimina ejecutables y temporales
clean:
	$(RM) $(PROGRAMAS) *.o