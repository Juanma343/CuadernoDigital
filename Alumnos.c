#include "Alumnos.h"

void entrada(char* ci){
    if ((strlen(ci) > 0) && (ci[strlen(ci) - 1] != '\0'))
    {
        ci[strlen(ci) - 1] = '\0';
    }
}

void CargarAlumnos(alumnos** alum, int* num_alumnos){
    int n = 0;
    alumnos temp;
    FILE* file;
    file = fopen("alumnos.txt", "r");

    if (file == NULL){
        printf("El archivo 'alumnos.txt' no ha podido abrirse con exito.");
        exit(1);
    }

    *alum = NULL;
    (*num_alumnos) = 0;
    
    
    while (!feof(file))
    {
        (*num_alumnos)++;
        *alum = (alumnos*) realloc(*alum, (*num_alumnos) * sizeof(alumnos));
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", temp.Id_alum, temp.Nombre_alum, temp.Direc_alum, temp.Local_alum, temp.Curso, temp.Grupo);
        strcpy((*alum)[n].Id_alum, temp.Id_alum);
        strcpy((*alum)[n].Nombre_alum, temp.Nombre_alum);
        strcpy((*alum)[n].Direc_alum, temp.Direc_alum);
        strcpy((*alum)[n].Local_alum, temp.Local_alum);
        strcpy((*alum)[n].Curso, temp.Curso);
        strcpy((*alum)[n].Grupo, temp.Grupo); 
    }

    fclose(file);   
}

void GuardarAlumnos(alumnos* alum, int* num_alumnos){
    int n = 0;
    FILE* file;
    file = fopen("alumnos.txt", "w");

    while (n < (*num_alumnos))
    {
        fprintf(file, "%s-%s-%s-%s-%s-%s\n", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        n++;
    }

    fclose(file);    
}

void ListarAlumnos(alumnos* alum, int* num_alumnos){
    int n = 0;
    while (n < *num_alumnos)
    {
        printf("%s-%s-%s-%s-%s-%s\n", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        n++;
    }
}

void ListarAlumnosDeGrupo(alumnos* alum, matriculas* matric, char* grupo, char* id_materia, int* num_alumnos, int num_matric){
    int n = 0, num_ids = 0, i = 0;
    char* ids_alum;
    ListaAlumnosMatricula(&ids_alum, id_materia, matric, num_matric, &num_ids);
    while (n < (*num_alumnos))
    {
        i = 0;
        while (i < num_ids)
        {
            if (strcmp(alum[n].Id_alum, ids_alum[i]) && strcmp(alum[n].Grupo, grupo)){
                printf("%s-%s-%s-%s-%s-%s", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
            }
            i++;
        }
        n++;
    }
    free(ids_alum);
}

void MostrarFichaAlumno(alumnos* alum, char* id_alum, int* num_alumnos){
    int n = 0;

    while (n < (*num_alumnos))
    {
        if (strcmp(alum[n].Id_alum, id_alum)){
            printf("%s-%s-%s-%s-%s-%s", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        }
        n++;
    }
}

void ModificarAlumno(alumnos** alum, char* id_alum, int* num_alumnos){
    int n = 0;
    char* ci;
    ci = (char *) malloc(100*sizeof(char));

    while (n < *num_alumnos)
    {
        if (strcmp((*alum)[n].Id_alum, id_alum)){
            printf("Introduce el nuevo nombre del alumno: ");
            fflush(stdin);
            fgets(ci, MAX_NOMBRE_ALUM, stdin);
            entrada(ci);
            strcpy((*alum)[n].Nombre_alum, ci);
            printf("Introduce la nueva direccion del alumno: ");
            fflush(stdin);
            fgets(ci, MAX_DIREC_ALUM, stdin);
            entrada(ci);
            strcpy((*alum)[n].Direc_alum, ci);
            printf("Introduce la nueva localidad del alumno: ");
            fflush(stdin);
            fgets(ci, MAX_LOCAL_ALUM, stdin);
            entrada(ci);
            strcpy((*alum)[n].Local_alum, ci);
            printf("Introduce el nuevo curso del alumno: ");
            fflush(stdin);
            fgets(ci, MAX_CURSO_ALUM, stdin);
            entrada(ci);
            strcpy((*alum)[n].Curso, ci);
            printf("Introduce el nuevo grupo del alumno: ");
            fflush(stdin);
            fgets(ci, MAX_GRUPO_ALUM, stdin);
            strcpy((*alum)[n].Grupo, ci);

            break;
        }
        n++;
    }   
}

void AltaAlumno(alumnos** alum, int* num_alumnos){
    char* ci;
    ci = (char *) malloc(100*sizeof(char));

    (*num_alumnos)++;
    *alum = (alumnos*) realloc(*alum, (*num_alumnos) * sizeof(alumnos)); 

    printf("Introduce el ID del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_ID_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Id_alum, ci);
    printf("Introduce el nombre del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_NOMBRE_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Nombre_alum, ci);
    printf("Introduce la direccion del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_DIREC_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Direc_alum, ci);
    printf("Introduce la localidad del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_LOCAL_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Local_alum, ci);
    printf("Introduce el curso del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_CURSO_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Curso, ci);
    printf("Introduce el grupo del alumno: ");
    fflush(stdin);
    fgets(ci, MAX_GRUPO_ALUM, stdin);
    entrada(ci);
    strcpy((*alum)[(*num_alumnos) - 1].Grupo, ci);
}

void BajaAlumno(alumnos** alum, int id_alum, int* num_alumnos){
    int i;
    for (i = 0; i < (*num_alumnos); i++)
    {
        if (id_alum == (*alum)[i].Id_alum){
            (*alum)[i] = (*alum)[(*num_alumnos) - 1];
            (*num_alumnos)--;
        }
    }
    (*alum) = (alumnos*)realloc(*alum, (*num_alumnos) * sizeof(alumnos));
}