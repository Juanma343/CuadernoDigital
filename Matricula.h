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

void CargarMatriculas(matriculas** matric, int* num_matric);
void GuardarMatriculas(matriculas* matric, int num_matric);
void ListarMateriasMatricula(matriculas* matric, char* id_alum, int num_matricula, materias* materia);
void ListaAlumnosMatricula(char** ids, char* id_materia, matriculas* matric, int num_matric, int* num_ids);
void ModificarMatricula(matriculas* matric, char* id_alum, char* id_antiguaMat, char* id_nuevaMat, int num_matric);
void EliminarMatricula(matriculas* matric, char* id_alum, char* id_mat, int* num_matric);
void CrearMatricula(matriculas* matric, char* id_alum, char* id_mat, int* num_matric);
//LISTA MATRICULA -> SELECCIONA ASIGNATURA A MODIFICAR ->
//LISTA TODAS ASIGNATURAS DISPONIBLES -> SELECCIONA NUEVA ASIGNATURA
#endif