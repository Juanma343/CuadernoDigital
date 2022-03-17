#ifndef __MATERIAS_H__
#define __MATERIAS_H__

#include <stdio.h>
#include <stdlib.h>
#include "Matricula.h"

#define MAX_NOMBRE_MATERIA 50
#define MAX_ABREV_MATERIA 3

typedef struct materia
{
    int Id_materia;
    char Nombre_materia[MAX_NOMBRE_MATERIA];
    char Abrev_materia[MAX_ABREV_MATERIA];
}materias;

//MANEJO DE FICHERO
void CargarMaterias(materias** mat, int* num_materias);
void GuardarMaterias(materias* mat, int num_materias);

//FUNCIONES DE MATERIA
void ListarMaterias(materias* mat, int num_materias);
void AltaMaterias(materias* mat, int* num_materias);
void BajaMaterias(materias* mat, int id_mat, int* num_materias);
void ModificarMateria(materias* mat, int id_mat, int num_materias);

#endif