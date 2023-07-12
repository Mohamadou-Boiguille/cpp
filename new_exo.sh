#!/bin/bash

read -p "Copier-coller : " input

# Extraction des informations
dossier=$(echo "$input" | awk -F " : " '{print $2}' | tr -d '[:space:]')
fichiers=$(echo "$input" | awk -F " : " '{print $4}' | tr -d '[:space:]')
fonctions_interdites=$(echo "$input" | awk -F " : " '{print $6}')

# Chemin absolu du dossier courant
dossier_courant=$(pwd)

# Création du dossier de rendu
mkdir -p "$dossier_courant/$dossier"
cd "$dossier_courant/$dossier"

# Création des fichiers
for fichier in ${fichiers//,/ }
do
    if [[ "$fichier" == *.hpp ]]; then
        touch "$fichier"
    else
        touch "$fichier.hpp"
    fi
done

# Création du Makefile
cat > Makefile << EOF
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
TARGET = main
SRCS = main.cpp

all: \$(TARGET)

\$(TARGET): \$(SRCS)
	\$(CC) \$(CFLAGS) -o \$@ \$^

clean:
	rm -f \$(TARGET)

.PHONY: all clean
EOF

echo "Dossier '$dossier' créé avec succès."
echo "Fichiers créés : $fichiers"
echo "Fonctions interdites : $fonctions_interdites"
