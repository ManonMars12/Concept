# Variables
CC = gcc
CFLAGS = -Wall -g
OBJ = ex2.o
EXEC = ex_2

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilation de ex2.o à partir de ex_2.c
ex2.o: ex_2.c struct.h
	$(CC) $(CFLAGS) -c ex_2.c -o ex2.o

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)
