cmake_minimum_required(VERSION 2.8.4)
project(TP4)

#Options de compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#Macro prépocesseur
#add_definitions(-DMAP)

set(SOURCE_FILES
    src/Cercle.cpp
    src/Cercle.h
    src/Forme.cpp
    src/Forme.h
    src/geoEdit.cpp
    src/Point.cpp
    src/Point.h
    src/Polyligne.h
    src/Polyligne.cpp
    src/Rectangle.h
    src/Rectangle.cpp
    src/Commande.cpp
    src/Commande.h
    src/Modele.cpp
    src/Modele.h
    src/Ligne.cpp
    src/Ligne.h
    src/Selection.cpp
    src/Selection.h
    src/CmdSimple.h
    src/CmdSimple.cpp
    src/CmdLoad.cpp
    src/CmdLoad.h
    src/CmdSave.cpp
    src/CmdSave.h
    src/CmdAjout.h
    src/CmdAjout.cpp
    src/CmdClear.cpp
    src/CmdClear.h
    src/CmdDelete.cpp
    src/CmdDelete.h
    src/CmdMove.cpp
    src/CmdMove.h
    )

add_executable(TP4 ${SOURCE_FILES})