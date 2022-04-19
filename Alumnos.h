#ifndef __ALUMNOS_H__
#define __ALUMNOS_H__

#include <stdio.h>
#include <stdlib.h>

#include "Matricula.h"
#include "Materias.h"

#define MAX_ID_ALUM 6
#define MAX_NOMBRE_ALUM 20
#define MAX_DIREC_ALUM 30
#define MAX_LOCAL_ALUM 30
#define MAX_CURSO_ALUM 30
#define MAX_GRUPO_ALUM 10

typedef struct alumno
{
    char Id_alum[MAX_ID_ALUM];    
    char Nombre_alum[MAX_NOMBRE_ALUM];
    char Direc_alum[MAX_DIREC_ALUM];
    char Local_alum[MAX_LOCAL_ALUM];
    char Curso[MAX_CURSO_ALUM];
    char Grupo[MAX_GRUPO_ALUM];
}alumnos;


//Utilizar %[^-] para leer del fichero con fscanf para los caracteres
//MANEJO DEL FICHERO

//pre: recibe un puntero a un puntero de alumnos y un entero para almacenar
// la cantidad de alumnos del sistema
//pos: devuelve el puntero inicializado con los alumnos del fichero y 
// el numero de alumnos
void CargarAlumnos(alumnos** alum, int* num_alumnos);

//pre: recibe un puntero de alumnos inicializado y el numero de alumnos
//pos: guarda en el fichero "alumnos.txt" los datos del puntero
void GuardarAlumnos(alumnos* alum, int* num_alumnos);

//FUNCIONES DE ALUMNO

//pre: recibe un puntero de alumnos y el numero de alumnos del sistema
//pos: muestra por pantalla todos los alumnos del sistema
void ListarAlumnos(alumnos* alum, int* num_alumnos);

//pre: recibe un puntero de alumnos, un string del grupo para listar 
// y el numero de alumnos
//pos: muestra por pantalla los alumnos pertenecientes al grupo dado
void ListarAlumnosDeGrupo(alumnos* alum, matriculas* matric, char* grupo, char* id_materia, int* num_alumnos, int num_matric);
//pre: recibe un puntero de alumnos, un id de alumno del sistema
// y el numero de alumnos
//pos: muestra por pantalla los datos de ese alumno en concreto
void MostrarFichaAlumno(alumnos* alum, char* id_alum, int* num_alumnos);

//pre: recibe un puntero de alumnos, un id del alumno del sistema
// y el numero de alumnos
//pos: permite modificar uno de los alumnos segun su id 
void ModificarAlumno(alumnos** alum, char* id_alum, int* num_alumnos);

//pre: recibe un puntero de alumnos y el numero de alumnos del sistema
//pos: añade un alumno nuevo al puntero e incrementa en 1 el numero de alumnos
void AltaAlumno(alumnos** alum, int* num_alumnos);

//pre: recibe un puntero de alumnos , el id del alumno
// y el numero de alumnos del sistema
//pos: elimina un alumno del puntero y decrementa el numero de alumnos en 1
void BajaAlumno(alumnos** alum, int id_alum, int* num_alumnos);

#endif