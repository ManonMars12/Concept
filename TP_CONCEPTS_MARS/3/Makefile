# Variables
CC = gcc
CFLAGS = -Wall -g
OBJ = ex_3.o
EXEC = ex_3

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilation de ex_3.o à partir de ex_3.c
ex_3.o: ex_3.c struct_horaires.h
	$(CC) $(CFLAGS) -c ex_3.c -o ex_3.o

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)
