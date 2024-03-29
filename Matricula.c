#include "Matricula.h"

void CargarMatriculas(matriculas** matric, int* num_matric){
    int n = 0;
    matriculas temp;
    FILE* file;
    file = fopen("matriculas.txt", "r");

    if (file == NULL){
        printf("El archivo 'alumnos.txt' no ha podido abrirse con exito.");
        exit(1);
    }

    *matric = NULL;
    (*num_matric) = 0;
    
    while (n < (*num_matric))
    {
        (*num_matric)++;
        *matric = (matriculas*) realloc(*matric, (*num_matric) * sizeof(matriculas));
        fscanf("%[^-]-%[^\n]\n", temp.Id_alum, temp.Id_materia);
        strcpy((*matric)[n].Id_alum, temp.Id_alum);
        strcpy((*matric)[n].Id_materia, temp.Id_materia);

        n++; 
    }

    fclose(file);
}

void GuardarMatriculas(matriculas* matric, int* num_matric){
    int n = 0;
    FILE* file;
    file = fopen("matriculas.txt", "w");

    while (n < (*num_matric))
    {
        fprintf(file, "%s-%s\n", matric[n].Id_alum, matric[n].Id_materia);
        n++;
    }

    fclose(file);
    free(matric); 
}

void ListaAlumnosMatricula(char** ids, char* id_materia, matriculas* matric, int* num_matric, int* num_ids){
    int n = 0;

    while (n < (*num_matric))
    {
        if (strcmp(matric[n].Id_materia, id_materia)){
            (*num_ids)++;
        }
        n++;
    }
    *ids = (char*) malloc((*num_ids) * sizeof(char));

    n = 0;
    int i = 0;
    while (n < (*num_matric))
    {
        if (strcmp(matric[n].Id_materia, id_materia)){
            strcpy((*ids)[i], matric[n].Id_alum);
            i++;
        }
        n++;
    }
}

void ListarMateriasMatricula(matriculas* matric, char* id_alum, int* num_matriculas, materias* materia){
    int n = 0;
    while (n < (*num_matriculas))
    {
        if (strcmp(matric[n].Id_alum, id_alum)){
            printf("%s", materia[atoi(matric[n].Id_materia)].Nombre_materia);
        }
        n++;
    }
}

void ModificarMatricula(matriculas** matric, char* id_alum, char* id_antiguaMat, char* id_nuevaMat, int* num_matric){
    int n = 0;

    while (n < (*num_matric))
    {
        if (strcmp((*matric)[n].Id_alum, id_alum) && strcmp((*matric)[n].Id_materia, id_antiguaMat)){
            strcpy((*matric)[n].Id_materia, id_nuevaMat);
        }
        n++;
    }
}

void EliminarMatricula(matriculas** matric, char* id_alum, char* id_mat, int* num_matric){
    int n = 0;

    while (n < (*num_matric))
    {
        if (strcmp((*matric)[n].Id_alum, id_alum) && strcmp((*matric)[n].Id_materia, id_mat)){
            (*matric)[n] = (*matric)[(*num_matric) - 1];
            (*num_matric)--;
        }
        n++;
    }

    *matric = (matriculas*) realloc(*matric, (*num_matric) * sizeof(matriculas));
}

void CrearMatricula(matriculas** matric, char* id_alum, char* id_mat, int* num_matric){
    (*num_matric)++;
    *matric = (matriculas*) realloc(*matric, (*num_matric) * sizeof(matriculas*));
    strcpy((*matric)[*num_matric - 1].Id_alum, id_alum);
    strcpy((*matric)[*num_matric - 1].Id_materia, id_mat);
}