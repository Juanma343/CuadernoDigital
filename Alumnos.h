#ifndef __ALUMNOS_H__
#define __ALUMNOS_H__

#define MAX_NOMBRE_ALUM 20
#define MAX_DIREC_ALUM 30
#define MAX_LOCAL_ALUM 30
#define MAX_CURSO_ALUM 30
#define MAX_GRUPO_ALUM 10

typedef struct alumnos
{
    int Id_alum;
    char Nombre_alum[MAX_NOMBRE_ALUM];
    char Direc_alum[MAX_DIREC_ALUM];
    char Local_alum[MAX_LOCAL_ALUM];
    char Curso[MAX_CURSO_ALUM];
    char Grupo[MAX_GRUPO_ALUM];
};


//Utilizar %[^-] para leer del fichero con fscanf para los caracteres
void CargarAlumnos(alumnos** alum, int* num_alumnos);
void GuardarAlumnos(alumnos* alum, int num_alumnos);
void ListarAlumnos(alumnos* alum, char grupo);
void MostrarFichaAlumno(alumnos alum);
void ModificarAlumno(alumnos alum, int* num_alumnos);

#endif