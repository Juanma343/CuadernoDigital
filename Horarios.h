#ifndef __HORARIOS_H__
#define __HORARIOS_H__

#define MAX_IDPROFESOR 3
#define MAX_IDMATERIA 4
typedef struct horario{
    char Id_profesor[3];
    int Dia_clase;
    int Hora_clase;
    char Id_materia[4];
    char Grupo[10];
} horarios;

#endif