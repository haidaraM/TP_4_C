# Makefile à completer pour vos besoins
# Ce makefile n'est pas adapté à tout type d'organisation
# Configurer par defaut pour le C++. Pour le C, remplacer g++ par gcc et cpp par c
EXE 		= geoEdit

# Compilateur et editeur de lien
COMP		= @g++
LINK		= @g++

# Options de compilation et editions de liens
CPPFLAGS	= -Wall -ansi -ggdb -std=c++11
EDLFLAGS	=

#Dossiers
SRC_DIR		= src
OBJ_DIR		= obj

#Fichiers
INTERFACES_FILES			= Cercle.h Forme.h Point.h						# Mettre les .h ici 
INT 		= $(addprefix $(SRC_DIR)/, $(INTERFACES_FILES))					# construit le chemin des sources 
OBJ			= $(addprefix $(OBJ_DIR)/, $(INTERFACES_FILES:.h=.o))			# Génération du nom des fichiers obj
MAIN_OBJ 	= $(OBJ_DIR)/geoEdit.o 											# .o du fichier ou se trouve le MAIN_OBJ

#Autres commandes et message
ECHO		= @echo
RM			= @rm
MESSAGE		= "Compilation réussie" 


$(EXE): $(OBJ) $(MAIN_OBJ)
	$(LINK) -o $(EXE) $^ $(EDLFLAGS)
	$(ECHO) $(MESSAGE)

#Mettre les dependances particulieres ici
$(MAIN_OBJ): $(INT)

#Generation des fichiers obj
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(ECHO) "Compilation de $< (generation de $@)"
	$(COMP) -o $@ -c $< $(CPPFLAGS)  

.PHONY: clean

clean:
	$(RM) -fv $(OBJ_DIR)/*.o $(EXE)

