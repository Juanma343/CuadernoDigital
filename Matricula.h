#ifndef __MATRICULA_H__
#define __MATRICULA_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct matricula
{
    int Id_materia;
    int Id_alum;
};

void CargarMatriculas(matricula** matric, int* num_matric);
void GuardarMatriculas(matricula* matric, int num_matric);
void ModificarMatricula(matricula* matric, int id_alum, int id_antiguaMat, int id_nuevaMat, int num_matric);
void EliminarMatricula(matricula* matric, int id_alum, int id_mat, int* num_matric);
void CrearMatricula(matricula* matric, int id_alum, int id_mat, int* num_matric);
//LISTA MATRICULA -> SELECCIONA ASIGNATURA A MODIFICAR ->
//LISTA TODAS ASIGNATURAS DISPONIBLES -> SELECCIONA NUEVA ASIGNATURA
#endif