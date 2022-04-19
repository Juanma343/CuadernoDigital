#include "LoginUsuario.h"
#include "Alumnos.h"
#include "Materias.h"
#include "Matricula.h"

int main(){
    alumnos* alumno;
    usuario* usuario;
    matriculas* matricula;
    materias* materias;
    int num_alumnos, num_usuarios, num_matriculas, num_materias, tipo;
    int op;
    char* idalum;
    cargarUsuarios(&usuario, &num_usuarios);
    CargarAlumnos(&alumno, &num_alumnos);
    CargarMaterias(&materias, &num_materias);
    CargarMatriculas(&matricula, &num_matriculas);

    tipo = menuPrincipal(usuario, &num_usuarios);
    do{
        if (tipo == 1){
            op = 0;
            printf("GRUPO 1ºHCSA MATERIA HAR\n");
            printf("===========================\n\n");
            printf("1. Lista de alumnos.\n");
            printf("2. Cambiar de grupo.");
            printf("3. Salir del programa.");
            scanf("%i", &op);
            if (op == 0){
                int sel;
                do{
                    sel = 0;
                    ListarAlumnosDeGrupo(alumno, matricula, "1ºHCSA", "1", &num_alumnos, num_matriculas);
                    printf("\nSeleccione un alumno: ");
                    fflush(stdin);
                    scanf("%s", idalum);
                    printf("\n\n ALUMNO: %s", alumno[atoi(idalum)].Nombre_alum);
                    printf("\n=============================================================\n\n");
                    printf("1. Ficha del alumno.\n");
                    printf("2. Calificaciones del alumno.\n");
                    printf("3. Volver.\n\n");
                    fflush(stdin);
                    scanf("%i", &sel);
                    if (sel == 1){
                        MostrarFichaAlumno(alumno, idalum, &num_alumnos);
                        printf("Desea modificar el alumno?: ");
                        char modAlum;
                        fflush(stdin);
                        scanf("%c", &modAlum);
                        if (modAlum == 's' || modAlum == 'S'){
                            ModificarAlumno(&alumno, idalum, &num_alumnos);
                        }
                    }else if (sel == 2){
                        printf("\nNo esta implementado porque no hay modulo Calificaciones.\n");
                    }
                }while (sel != 3);
            }else if(op == 2){
                printf("\nNo esta implementado porque no hay modulo Horarios.");
            }else{
                op = -1;
            }
        }else if (tipo == 1){
            op = 0;
            int sel = 0, id;
            printf("1. Usuarios.\n");
            printf("2. Alumnos.\n");
            printf("3. Materias.\n");
            printf("4. Horarios\n");
            printf("5. Salir del programa.\n");
            fflush(stdin);
            scanf("%i", &op);
            if (op == 1){
                sel = 0;
                gestionarUsuario(&usuario, &num_usuarios);
            }else if (op == 2){
                sel = 0;
                char c;
                printf("1. Dar de alta un alumno.\n");
                printf("2. Dar de baja un alumno.\n");
                printf("3. Modificar un alumno.\n");
                printf("4. Listar alumnos.\n");
                fflush(stdin);
                scanf("%i", &sel);
                if (sel == 1){
                    AltaAlumno(&alumno, &num_alumnos);
                }else if (sel == 2){
                    id = 0;
                    printf("\nIntroduce el ID del alumno a dar de baja: ");
                    scanf("%i", &id);
                    BajaAlumno(&alumno, id, &num_alumnos);
                }else if (sel == 3){
                    id = 0;
                    printf("\nIntroduce el ID del alumno a modificar: ");
                    scanf("%i", &id);
                    ModificarAlumno(&alumno, (char*)(id), &num_alumnos);
                }else if (sel == 4){
                    id = 0;
                    ListarAlumnos(alumno, &num_alumnos);
                }
                printf("\nDesea actuar sobre un alumno concreto?: ");
                fflush(stdin);
                scanf("%c", &c);
                if (c == 's' || c == 'S'){
                    int aux;
                    printf("\nIntroduce el ID del alumno: ");
                    scanf("%i", &id);
                    printf("\n\n1. Lista materias de la matricula.");
                    printf("\n2. Cambios de asignatura.");
                    printf("\n3. Eliminar una matricula.");
                    printf("\n4. Crear nueva matricula.\n");
                    fflush(stdin);
                    scanf("%i", &aux);
                    if (aux == 1){
                        ListarMateriasMatricula(matricula, (char*)id, num_matriculas, materias);
                    }else if (aux == 2){
                        char* aMat;
                        char* nMat;
                        ListarMateriasMatricula(matricula, (char*)id, num_matriculas, materias);
                        printf("\nIntroduce el ID de la materia a modificar de su matricula: ");
                        scanf("%s", aMat);
                        printf("\nIntroduce el ID de la nueva materia a cursar: ");
                        scanf("%s", nMat);
                        ModificarMatricula(matricula, (char*)id, aMat, nMat, num_matriculas);
                    }else if (aux == 3){
                        char* mat;
                        ListarMateriasMatricula(matricula, (char*)id, num_matriculas, materias);
                        printf("\nIntroduce el ID de la materia a eliminar de su matricula: ");
                        scanf("%s", mat);
                        EliminarMatricula(matricula, (char*)id, mat, &num_matriculas);
                    }else if (aux == 4){
                        char* mat;
                        ListarMateriasMatricula(matricula, (char*)id, num_matriculas, materias);
                        printf("\nIntroduce el ID de la materia a crear: ");
                        scanf("%s", mat);
                        CrearMatricula(matricula, (char*)id, mat, &num_matriculas);
                    }
                }
            }else if (op == 3){
                sel = 0;
                printf("\n1. Dar de alta una materia.");
                printf("\n2. Dar de baja una materia.");
                printf("\n3. Modificar una materia.");
                printf("\n4. Listar materias.\n");
                scanf("%i", &sel);
                if (sel == 1){
                    AltaMaterias(materias, &num_materias);
                }else if (sel == 2){
                    ListarMaterias(materias, num_materias);
                    printf("Introduce el ID de la materia a eliminar: ");
                    int n;
                    scanf("%i", &n);
                    BajaMaterias(materias, (char*)n, &num_materias);
                }else if (sel == 3){
                    ListarMaterias(materias, num_materias);
                    printf("Introduce el ID de la materia a modificar: ");
                    int n;
                    scanf("%i", &n);
                    ModificarMateria(materias, (char*)n, &num_materias);
                }else if (sel == 4){
                    ListarMaterias(materias, num_materias);
                }
            }else if (op == 4){
                printf("\nNo esta implementado porque no hay modulo Horarios.");
            }else{
                op = -1;
            }
        }
    }while (op != -1);
    
    descargarUsuarios(usuario, &num_usuarios);
    GuardarAlumnos(alumno, &num_alumnos);
    GuardarMaterias(materias, &num_materias);
    GuardarMatriculas(matricula, &num_matriculas);
    return 0;
}