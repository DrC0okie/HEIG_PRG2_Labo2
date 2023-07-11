cmake_minimum_required(VERSION 3.22)
project(taxes C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS="-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(taxes main.c vehicule.c vehicule.h taxe.c taxe.h parking.c parking.h affichage.c affichage.h statistiques.c statistiques.h)
