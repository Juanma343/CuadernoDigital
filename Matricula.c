#include "Matricula.h"

void ListaAlumnosMatricula(char** ids, int id_materia, matriculas* matric, int num_matric, int* num_ids){
    int n = 0;

    while (n < num_matric)
    {
        if (matric[n].Id_materia == id_materia){
            (*num_ids)++;
        }
    }
    *ids = (char*) malloc((*num_ids) * sizeof(char));

    n = 0;
    while (n < num_matric)
    {
        if (matric[n].Id_materia == id_materia){
            strcpy(*ids[n], matric[n].Id_alum);
        }
    }
}