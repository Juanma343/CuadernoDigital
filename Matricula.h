#ifndef __MATRICULA_H__
#define __MATRICULA_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct matricula
{
    int Id_materia;
    int Id_alum;
}matriculas;

void CargarMatriculas(matriculas** matric, int* num_matric);
void GuardarMatriculas(matriculas* matric, int num_matric);
void ListaAlumnosMatricula(char** ids, int id_materia, matriculas* matric, int num_matric, int* num_ids);
void ModificarMatricula(matriculas* matric, int id_alum, int id_antiguaMat, int id_nuevaMat, int num_matric);
void EliminarMatricula(matriculas* matric, int id_alum, int id_mat, int* num_matric);
void CrearMatricula(matriculas* matric, int id_alum, int id_mat, int* num_matric);
//LISTA MATRICULA -> SELECCIONA ASIGNATURA A MODIFICAR ->
//LISTA TODAS ASIGNATURAS DISPONIBLES -> SELECCIONA NUEVA ASIGNATURA
#endif