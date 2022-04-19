#ifndef __MATRICULA_H__
#define __MATRICULA_H__

#include <stdio.h>
#include <stdlib.h>

#include "Materias.h"

#define MAX_ID_MATERIA 4
#define MAX_ID_ALUM 6

typedef struct matricula
{
    char Id_materia[MAX_ID_MATERIA];
    char Id_alum[MAX_ID_ALUM];
}matriculas;


//MANEJO DE FICHEROS
//pre: Puntero a vector dinámico vacío y puntero entero de número de matriculas
//post: Vuelca en el vector dinámico el contenido del fichero "matriculas.txt"
// y guarda el número de matrículas en la variable pasada por parámetro
void CargarMatriculas(matriculas** matric, int* num_matric);

//pre: Vector dinámico de matrículas con valores y el número de matrículas
//post: Guarda en el fichero "matriculas.txt" el vector dinámico de matrículas
void GuardarMatriculas(matriculas* matric, int num_matric);

//pre: Vector dinámico de matrículas, cadena de caracteres de id del alumno,
// número de matriculas y Vector dinámico de materias
//post: Imprime por pantalla la lista de materias en las que está
// matriculado un alumno en concreto
void ListarMateriasMatricula(matriculas* matric, char* id_alum, int num_matricula, materias* materia);

//pre: Puntero a vector dinámico de caracteres vacío, cadena de caracteres
// con el id de la materia, vector dinámico de matrículas, 
// número de matriculas y puntero entero del número de ids
//post: Guarda en el vector dinámico ids los ids de los alumnos que están
// matriculados en una determinada materia y guarda el número de ids
void ListaAlumnosMatricula(char** ids, char* id_materia, matriculas* matric, int num_matric, int* num_ids);

//pre: Vector dinámico de matrículas, cadena de caracteres de id de alumno
// cadena de caracteres con un id de materia, cadena de caracteres con otro
// id de materia y número de matrículas
//post: Modifica una materia de la lista de matrículas de un alumno en concreto
void ModificarMatricula(matriculas* matric, char* id_alum, char* id_antiguaMat, char* id_nuevaMat, int num_matric);

//pre: Vector dinámico de matrículas, cadena de caracteres de id del alumno
// cadena de caracteres de id de materia, puntero a número de matrículas
//post: Elimina del vector dinámico una matrícula de un alumno en concreto
// y decrementa en 1 el valor del número de matrículas
void EliminarMatricula(matriculas* matric, char* id_alum, char* id_mat, int* num_matric);

//pre: Vector dinámico de matrículas, cadena de caracteres de id del alumno,
// cadena de caracteres con el id de la materia y puntero a número de matrículas
//post: Añade al vector dinámico una nueva matrícula e incrementa en 1 
// el número de matrículas
void CrearMatricula(matriculas* matric, char* id_alum, char* id_mat, int* num_matric);
//LISTA MATRICULA -> SELECCIONA ASIGNATURA A MODIFICAR ->
//LISTA TODAS ASIGNATURAS DISPONIBLES -> SELECCIONA NUEVA ASIGNATURA
#endif