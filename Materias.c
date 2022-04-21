#include "Materias.h"

void entradas(char* ci){
    if ((strlen(ci) > 0) && (ci[strlen(ci) - 1] != '\0'))
    {
        ci[strlen(ci) - 1] = '\0';
    }
}

void CargarMaterias(materias** mat, int* num_materias){
    int n = 0;
    materias temp;
    FILE* file;
    file = fopen("materias.txt", "r");

    if (file == NULL){
        printf("No se ha podido abrir el fichero 'matriculas.txt'.");
        exit(1);
    }
    
    *mat = NULL;
    (*num_materias) = 0;

    while(!feof(file))
    {
        (*num_materias)++;
        *mat = (materias*) realloc(*mat, (*num_materias) * sizeof(materias));
        fscanf(file, "%[^-]-%[^-]-%[^\n]\n", temp.Id_materia, temp.Nombre_materia, temp.Abrev_materia);
        strcpy((*mat)[n].Id_materia, temp.Id_materia);
        strcpy((*mat)[n].Nombre_materia, temp.Nombre_materia);
        strcpy((*mat)[n].Abrev_materia, temp.Abrev_materia);
        n++;
    }

    fclose(file);
}

void GuardarMaterias(materias* mat, int* num_materias){
    int n = 0;
    FILE* file;
    file = fopen("materias.txt", "w");

    while (n < (*num_materias))
    {
        fprintf(file, "%s-%s-%s\n", mat[n].Id_materia, mat[n].Nombre_materia, mat[n].Abrev_materia);
        n++;
    }

    fclose(file); 
    free(mat);
}

void ListarMaterias(materias* mat, int* num_materias){
    int n = 0;

    while (n < *num_materias)
    {
        printf("%s-%s-%s\n", mat[n].Id_materia, mat[n].Nombre_materia, mat[n].Abrev_materia);
        n++;
    }
}

void AltaMaterias(materias** mat, int* num_materias){
    char* ci;
    ci = (char *) malloc(100*sizeof(char));
    (*num_materias)++;
    *mat = (materias*) realloc(*mat, (*num_materias) * sizeof(materias));

    strcpy((*mat)[(*num_materias) - 1].Id_materia, (char*)(*num_materias - 1));
    printf("Introduce el Nombre de la nueva materia: ");
    fflush(stdin);
    fgets(ci, MAX_NOMBRE_MATERIA, stdin);
    entradas(ci);
    strcpy((*mat)[(*num_materias) - 1].Nombre_materia, ci);
    printf("Introduce la Abreviatura de la nueva matreia: ");
    fflush(stdin);
    fgets(ci, MAX_ABREV_MATERIA, stdin);
    entradas(ci);
    strcpy((*mat)[(*num_materias) - 1].Abrev_materia, ci);
}

void BajaMaterias(materias** mat, char* id_mat, int* num_materias){
    int n = 0, comp = 0;
    for (n = 0; n < (*num_materias); n++)
    {
        if (id_mat == (*mat)[n].Id_materia){
            (*mat)[n] = (*mat)[(*num_materias) - 1];
            (*num_materias)--;
        }
    }
    *mat = (materias*) realloc(*mat, (*num_materias) * sizeof(materias));
}

void ModificarMateria(materias** mat, char* id_mat, int* num_materias){
    char* ci;
    ci = (char *) malloc(100*sizeof(char));

    printf("Introduce el nuevo Nombre de la materia: ");
    fflush(stdin);
    fgets(ci, MAX_NOMBRE_MATERIA, stdin);
    entradas(ci);
    strcpy((*mat)[atoi(id_mat)].Nombre_materia, ci);
    printf("Introduce la nueva Abreviatura de la materia: ");
    fflush(stdin);
    fgets(ci, MAX_ABREV_MATERIA, stdin);
    entradas(ci);
    strcpy((*mat)[atoi(id_mat)].Abrev_materia, ci);
}