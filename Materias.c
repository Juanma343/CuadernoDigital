#include "Materias.h"

void CargarMaterias(materias** mat, int* num_materias){
    int n = 0;
    materias temp;
    FILE* file = fopen("materias.txt", "r");

    if (file == NULL){
        printf("No se ha podido abrir el fichero 'matriculas.txt'.");
        exit(1);
    }
    
    fscanf(file, "%[^-]%[^-]%[^-]\n", temp.Id_materia, temp.Nombre_materia, temp.Abrev_materia);
    if (temp.Id_materia != NULL){
        *num_materias++;
        *mat = (materias*) malloc((*num_materias) * sizeof(materias));
    }

    while(!feof(file))
    {
        strcpy((*mat)[*num_materias - 1].Id_materia, temp.Id_materia);
        strcpy((*mat)[*num_materias - 1].Nombre_materia, temp.Nombre_materia);
        strcpy((*mat)[*num_materias - 1].Abrev_materia, temp.Abrev_materia);
        fscanf(file, "%[^-]%[^-]%[^-]\n", temp.Id_materia, temp.Nombre_materia, temp.Abrev_materia);
        *num_materias++;
        mat = (materias*) realloc(*mat, *num_materias * sizeof(materias));
    }

    fclose(file);
    free(file);
}

void GuardarMaterias(materias* mat, int num_materias){
    int n = 0;
    FILE* file = fopen("materias.txt", "w");

    while (n < num_materias)
    {
        fprintf(file, "%s-%s-%s\n", mat[n].Id_materia, mat[n].Nombre_materia, mat[n].Abrev_materia);
        n++;
    }

    fclose(file);
    free(mat);    
    
}

void ListarMaterias(materias* mat, int num_materias){
    int n = 0;

    while (n < num_materias)
    {
        printf("%s-%s-%s", mat[n].Id_materia, mat[n].Nombre_materia, mat[n].Abrev_materia);
    }
}

void AltaMaterias(materias* mat, int* num_materias){
    mat = (materias*) realloc(mat, ++*num_materias * sizeof(materias));
    strcpy(mat[*num_materias].Id_materia, (char*)*num_materias);
    printf("Introduce el Nombre de la nueva materia: ");
    fflush(stdin);
    scanf("%s", mat[*num_materias].Nombre_materia);
    printf("Introduce la Abreviatura de la nueva matreia: ");
    fflush(stdin);
    scanf("%s", mat[*num_materias].Abrev_materia);
}

void BajaMaterias(materias* mat, char* id_mat, int* num_materias){
    int n = 0, comp = 0;
    while (n < *num_materias)
    {
        if (strcmp(mat[n].Id_materia, id_mat)){
            comp = 1;
        }
        if (comp == 1){
            strcpy(mat[n].Id_materia, mat[n + 1].Id_materia);
            strcpy(mat[n].Nombre_materia, mat[n + 1].Nombre_materia);
            strcpy(mat[n].Abrev_materia, mat[n + 1].Abrev_materia);
        }
    }

    mat = (materias*) realloc(mat, --*num_materias * sizeof(materias));
}

void ModificarMateria(materias* mat, int id_mat, int num_materias){
    printf("Introduce el nuevo Nombre de la materia: ");
    fflush(stdin);
    scanf("%s", mat[id_mat - 1].Nombre_materia);
    printf("Introduce la nueva Abreviatura de la materia: ");
    fflush(stdin);
    scanf("%s", mat[id_mat - 1].Abrev_materia);
}
