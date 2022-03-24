#include "Alumnos.h"

void CargarAlumnos(alumnos** alum, int* num_alumnos){
    int n = 0;
    alumnos temp;
    FILE* file = fopen("alumnos.txt", "r");

    if (file == NULL){
        printf("El archivo 'alumnos.txt' no ha podido abrirse con exito.");
        exit(1);
    }

    while (!feof(file))
    {
        fscanf(file, "%[^\n]\n");
        (*num_alumnos)++;
    }
    rewind(file);
    *alum = (alumnos*) malloc((*num_alumnos) * sizeof(alumnos));
    
    while (n < *num_alumnos)
    {
        fscanf(file, "%[^-]%[^-]%[^-]%[^-]%[^-]%[^-]\n", temp.Id_alum, temp.Nombre_alum, temp.Direc_alum, temp.Local_alum, temp.Curso, temp.Grupo);
        strcpy((*alum)[n].Id_alum, temp.Id_alum);
        strcpy((*alum)[n].Nombre_alum, temp.Nombre_alum);
        strcpy((*alum)[n].Direc_alum, temp.Direc_alum);
        strcpy((*alum)[n].Local_alum, temp.Local_alum);
        strcpy((*alum)[n].Curso, temp.Curso);
        strcpy((*alum)[n].Grupo, temp.Grupo);

        n++; 
    }

    fclose(file);
    free(file);    
}

void GuardarAlumnos(alumnos* alum, int num_alumnos){
    int n = 0;
    FILE* file = fopen("alumnos.txt", "w");

    while (n < num_alumnos)
    {
        fprintf(file, "%s-%s-%s-%s-%s-%s\n", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        n++;
    }

    fclose(file);
    free(alum);    
}

void ListarAlumnos(alumnos* alum, int num_alumnos){
    int n = 0;
    while (n < num_alumnos)
    {
        printf("%s-%s-%s-%s-%s-%s\n", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        n++;
    }
}

void ListarAlumnosDeGrupo(alumnos* alum, matriculas* matric, char* grupo, int id_materia, int num_alumnos, int num_matric){
    int n = 0, num_ids = 0, i = 0;
    char* ids_alum;
    ListaAlumnosMatricula(*ids_alum, id_materia, matric, num_matric, &num_ids);
    while (n < num_alumnos)
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

void MostrarFichaAlumno(alumnos* alum, char* id_alum, int num_alumnos){
    int n = 0;

    while (n < num_alumnos)
    {
        if (strcmp(alum[n].Id_alum, id_alum)){
            printf("%s-%s-%s-%s-%s-%s", alum[n].Id_alum, alum[n].Nombre_alum, alum[n].Direc_alum, alum[n].Local_alum, alum[n].Curso, alum[n].Grupo);
        }
        n++;
    }
}

void ModificarAlumno(alumnos* alum, char* id_alum, int num_alumnos){
    int n = 0;

    while (n < num_alumnos)
    {
        if (strcmp(alum[n].Id_alum, id_alum)){
            printf("Introduce el nuevo nombre del alumno: ");
            fflush(stdin);
            scanf("%s", alum[n].Nombre_alum);
            printf("Introduce la nueva direccion del alumno: ");
            fflush(stdin);
            scanf("%s", alum[n].Direc_alum);
            printf("Introduce la nueva localidad del alumno: ");
            fflush(stdin);
            scanf("%s", alum[n].Local_alum);
            printf("Introduce el nuevo curso del alumno: ");
            fflush(stdin);
            scanf("%s", alum[n].Curso);
            printf("Introduce el nuevo grupo del alumno: ");
            fflush(stdin);
            scanf("%s", alum[n].Grupo);

            break;
        }
        n++;
    }   
}

void AltaAlumno(alumnos* alum, int* num_alumnos){
    *num_alumnos++;
    alum = (alumnos*) realloc(alum, *num_alumnos * sizeof(alumnos)); 

    printf("Introduce el ID del alumno: ");
    fflush(stdin);
    scanf("%s", alum[*num_alumnos - 1].Id_alum);
    printf("Introduce la nueva direccion del alumno: ");
    fflush(stdin);
    scanf("%s", alum[*num_alumnos - 1].Direc_alum);
    printf("Introduce la nueva localidad del alumno: ");
    fflush(stdin);
    scanf("%s", alum[*num_alumnos - 1].Local_alum);
    printf("Introduce el nuevo curso del alumno: ");
    fflush(stdin);
    scanf("%s", alum[*num_alumnos - 1].Curso);
    printf("Introduce el nuevo grupo del alumno: ");
    fflush(stdin);
    scanf("%s", alum[*num_alumnos - 1].Grupo);
}