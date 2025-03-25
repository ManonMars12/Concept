# Variables
CC = gcc
CFLAGS = -Wall -g

# Fichiers sources
SRC_LISTEINT = marslisteint.c
SRC_EXO1 = marsexo1.c

# Fichiers objets
OBJ_LISTEINT = marslisteint.o
OBJ_EXO1 = marsexo1.o

# Nom de l'exécutable
EXEC = marsexo1

# Nom du fichier binaire à supprimer lors du nettoyage
BIN_FILE = savelist.bin

# Cibles par défaut : compilation de l'exécutable
all: $(EXEC)

# Compilation de l'exécutable à partir des sources
$(EXEC): $(OBJ_LISTEINT) $(OBJ_EXO1)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ_LISTEINT) $(OBJ_EXO1)

# Compilation du fichier marslisteint.c
$(OBJ_LISTEINT): $(SRC_LISTEINT)
	$(CC) $(CFLAGS) -c $(SRC_LISTEINT)

# Compilation du fichier marsexo1.c
$(OBJ_EXO1): $(SRC_EXO1)
	$(CC) $(CFLAGS) -c $(SRC_EXO1)

# Nettoyage des fichiers générés
clean:
	rm -f $(BIN_FILE) $(EXEC) $(OBJ_LISTEINT) $(OBJ_EXO1)

