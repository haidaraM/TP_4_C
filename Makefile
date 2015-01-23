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
INTERFACES_FILES		= Cercle.h Forme.h Point.h Rectangle.h Polyligne.h Modele.h Commande.h					# Mettre les .h ici
INT 		            = $(addprefix $(SRC_DIR)/, $(INTERFACES_FILES))					# construit le chemin des sources
OBJ			            = $(addprefix $(OBJ_DIR)/, $(INTERFACES_FILES:.h=.o))			# Génération du nom des fichiers obj
MAIN_OBJ             	= $(OBJ_DIR)/geoEdit.o 											# .o du fichier ou se trouve le main

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
	$(ECHO) "Nettoyage..."
	$(RM) -fv $(OBJ_DIR)/*.o $(EXE)

backup: clean
	$(ECHO) "Creation d'un dossier propre pour rendu et archivage des répertoires src, doc, Tests et Makefile..."
	$(ECHO) "Creation de l'arborescence des répertoires..."
	@mkdir -p B3425
	$(ECHO) "Copie des repertoires..."
	@cp -r $(SRC_DIR)/ $(OBJ_DIR)/ Makefile doc/ Tests/ B3425
	$(ECHO) "Generation de l'archive B3425.tar..."
	$(ECHO) "	=> Compréssion des fichiers..."
	@tar -cf "B3425.tar" B3425
	$(ECHO) "	=> Archive crée"
	$(ECHO)	"Backup terminé"

	