#!/bin/bash
# Ce script test le temps que mon programme fait en moyenne pour lire dans un fichier lors l'un LOAD
# Commandes utilisées : time, grep, cut, echo.
# Il prend en premier paramètre le nombre de commande d'ajout qui doit être genéré dans le fichier qui sera lu par le programme
# le second correpond au nombre de tests.

if ! [[ $# -eq 2 ]]; then
	echo "Paramètres Invalides"
	exit 200
fi

NB_COMMANDES=$1
NB_TEST=$2

#execution de la commande
#compilation générateur de fichier
echo "Compilation générateur de fichier..."
g++ EcritTest2.cpp -o generateur

echo "Création du fichier en cours..."
./generateur ${NB_COMMANDES} > gros_test.temp

echo "Exécution des tests en cours..."
for I in `seq 1 ${NB_TEST}`; do
	echo "Test numéro $I..." 
	time ../geoEdit < load.txt; 
done 2> file.temp

# On recupere le usr et le sys time
grep -v real file.temp | cut -d"m" -f 2,3 | cut -d"s" -f1 > temps.temp

#on supprime les lignes vides meme si je crois que c'est pas nécéssaire
cat temps.temp | grep -v ^$ > temps2.temp

#echo "Compilation du programme calculant la moyenne..."
g++ moyenne.cpp -o moyenne

#echo "Cacul de la moyenne"
./moyenne temps2.temp


echo "Néttoyage du répertoire..."
rm *.temp moyenne generateur
exit 0;
