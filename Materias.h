#ifndef __MATERIAS_H__
#define __MATERIAS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matricula.h"

#define MAX_ID_MATERIA 4
#define MAX_NOMBRE_MATERIA 50
#define MAX_ABREV_MATERIA 3

typedef struct materia
{
    char Id_materia[MAX_ID_MATERIA];
    char Nombre_materia[MAX_NOMBRE_MATERIA];
    char Abrev_materia[MAX_ABREV_MATERIA];
}materias;

//MANEJO DE FICHERO
//pre: Vector dinámico de materias vacio y un puntero a entero con el numero de materias
//post: Vuelca en el vector dinámico el contenido del fichero "materias.txt"
// y guarda el número de materias en su variable
void CargarMaterias(materias** mat, int* num_materias);

//pre: Vector dinámico de materias con valores y el número de materias del vector
//post: Guarda en el fichero "materias.txt" el contenido del vector dinámico
void GuardarMaterias(materias* mat, int num_materias);

//FUNCIONES DE MATERIA
//pre: Vector dinámico de materias con valores y el número de materias del vector
//post: Imprime por pantalla todas las materias del vector de una en una
void ListarMaterias(materias* mat, int num_materias);

//pre: Vector dinámico de materias con valores y el puntero del número de materias
//post: Añade al vector una nueva materia e incrementa en 1 el número de materias
void AltaMaterias(materias* mat, int* num_materias);

//pre: Vector dinámico de materias con valores, una cadena de caracteres 
// con el id de la materia a eliminar y el puntero de número de materias
//post: Elimina del vector la materia pasada por parámetro y decrementa
//en 1 el número de materias
void BajaMaterias(materias* mat, char* id_mat, int* num_materias);

//pre: Vector dinámico de materias con valores, una cadena de caracteres
// con el id de la materia a modificar y el número de materias
//post: Modifica del vector la materia pasada por parámetro
void ModificarMateria(materias* mat, char* id_mat, int num_materias);

#endif