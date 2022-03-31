#include "LoginUsuario.h"
#include<locale.h> 
#define ñ 164
#define in 168


//esta es una estructura de apoyo la cual se utiliza en los usuarios para facilitar la rapidez a la hora de deccidir el numero nuevo en el sistema
//consiste en un vector de booleanos(como en c no hay de enteros), que guardan un uno si ese id esta en uso y un 0 si no lo esta
//de esta forma tenemos controlados el numeo de ids disponibles de foma mas sencill y visible
//ademas la estructura almacenara la menor id disponible lo que sumado a que este vector tiempre estara ordenado aumenta la eficuencia de la eleccion de entero
//esto para numero pequeños no es realmete un coste demasiado dispar al de este pero teneiendo pero esto creo que es lo realmente correcto para los casos generales sin ver el contezto de este proyecto

//cambiar los parematros de entrada del leer documentos
//cambiar para que no se permita el caracter -

int iniciarSesion(char* s_usuario, char* s_contraseñnna, usuario* vUsuario, int nUsuario);
void dardeAltaUsuario(usuario**, int* nUsuario);
void dardeBajaUsuario(usuario**, int* nUsuario);
void modificarUsuario(usuario**, int* nUsuario);
void listaUsuarios(usuario*, int* nUsuario);

int iniciarSesion(char* s_usuario, char* s_contrasenna, usuario* vUsuario, int nUsuario){

    int i = 0;
    int salida = 0;

    do {

        if (strcmp(s_usuario, vUsuario[i].Usuario) == 0){
            if (strcmp(s_contrasenna, vUsuario[i].Contrasenna) == 0){
                salida = 1;
            }
        }
        i++;

    } while (salida && i < nUsuario);

    return salida;

}
void dardeAltaUsuario(usuario** vUsuario, int* nUsuario){

    char* ci;   //cadena intermedia
    char ca;    //caracter administrador

    ci = (char *) malloc(100*sizeof(char));

    int control = 0,i = 1, j = 0, control2 = 1, controlFor = 0;

    //añade un nuevo espacio al vector dinamico
    (*nUsuario)++;
    *vUsuario = (usuario*)realloc(*vUsuario, ((*nUsuario)) * sizeof(usuario));

    printf("Datos del nuevo usuario:\n\n");
    do{
        control = 0;
        printf("Usuario:");
        fflush(stdin);
        scanf("%s", ci);
        fflush(stdin);
        if (ci[0] == '\0'){
            printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
            
            control = 1;
        }
        else if(strlen(ci)>5){
            printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
            
            control = 1;
        }
        else if(strchr(ci, '-') != NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            
            control = 1;
        }
        else {
            controlFor = 1;
            
            for(i = 0; i < (*nUsuario) && controlFor; i++){
                if(strcmp(ci, (*vUsuario)[i].Usuario) == 0){
                    controlFor = 0;
                }
            }
            if (controlFor == 1){
                strcpy((*vUsuario)[(*nUsuario) - 1].Usuario, ci);
            }
            else{
                printf("\nEste nombre ya esta registrado, utiliza otro nombre.\n");
                
                control = 1;
            }
        }
    }while(control);
    do{
        control = 0;
        printf("Contrase%ca;", ñ);
        fflush(stdin);
        scanf("%s", ci);
        fflush(stdin);
        if (ci[0] == '\0'){
            printf("\nError, no ha escrito ninguna contraseña, intentelo de nuevo.\n");
            
            control = 1;
        }
        else if(strlen(ci)>8){
            printf("\nError, la contrase%ca es demasiado larga, intentelo de nuevo.\n", ñ);
            
            control = 1;
        }
        else if(strchr(ci, '-') != NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            
            control = 1;
        }
        else{
            strcpy((*vUsuario)[(*nUsuario) - 1].Contrasenna, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("Nombre del usuario:");
        fflush(stdin);
        scanf("%s", ci);
        fflush(stdin);
        if (ci[0] == '\0'){
            strcpy((*vUsuario)[(*nUsuario) - 1].Nomb_usuario, "ANONIMO");
        }
        else if(strlen(ci)>20){
            printf("\nError, el nombre es demasiado larga, introduce solo el primer apellido o utiliza abreviatura.\n");
            
            control = 1;
        }
        else if(strchr(ci, '-') != NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            
            control = 1;
        }
        else{
            strcpy((*vUsuario)[(*nUsuario) - 1].Nomb_usuario, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("%csera un usuario administrador? (s/n)\n",in);
        fflush(stdin);
        scanf("%s", ci);
        fflush(stdin);
        if (ci[0] == 's' || ci[0] == 'S'){
            (*vUsuario)[(*nUsuario) - 1].Perfil_usuario = 1;
        }
        else if(ci[0] == 'n' || ci[0] == 'N'){
            (*vUsuario)[(*nUsuario) - 1].Perfil_usuario = 0;
        }
        else {
            printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
            
            control = 1;
        }
    }while(control);

    control = 1;
    control = 1;
    for (i = 1; i < 1000 && control2; i++){   
        control = 1; 
        for(j = 0; j < *nUsuario - 1 && control; j++){
            //printf("%i",i);
            if ((*vUsuario)[j].id_usuario == i){
                control = 0;
            }
        }
        if(control){
            printf("%i", i);
            (*vUsuario)[*nUsuario - 1].id_usuario = i;
            control2 = 0;
        }

    }

}
//da de baja un usuario
void dardeBajaUsuario(usuario** vUsuario, int* nUsuario){

    char ci[30];
    char ca;

    int control = 0, eleccion = 0,controlFor = 0,i = 0, id = 0, seleccion = 0;

    do{
        control = 0;
        printf("%cSabes que usuario quieres eliminar? (s/n)\n", in);
        fflush(stdin);
        scanf("%s", ci);
        fflush(stdin);
        if (ci[0] == 's' || ci[0] == 'S'){
            eleccion = 0;
        }
        else if(ci[0] == 'n' || ci[0] == 'N'){
            eleccion = 1;
        }
        else {
            printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
            
            control = 1;
        }
    }while(control);



    if (eleccion == 1){     //tiene diferentes parametros para buscar que eliminar

        do{
            control = 0;
            printf("Selecciona una:\n\n1-Usuario\n2-Nombre Usuario\n\n");
            fflush(stdin);
            scanf("%i", &seleccion);
            fflush(stdin);
            if(seleccion == 1){
                do{
                    control = 0;
                    printf("Usuario:");
                    fflush(stdin);
                    scanf("%s", ci);
                    fflush(stdin);
                    if (ci[0] == '\0'){
                        printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                        
                        control = 1;
                    }
                    else if(strlen(ci)>6){
                        printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                        
                        control = 1;
                    }
                    else if(strchr(ci, '-') != NULL){
                        printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                        
                        control = 1;
                    }
                    else if(!(strcmp(ci, "NULL") == 0)){
                        controlFor = 0;
                        for(i = 0; i < *nUsuario && controlFor == 0; i++){
                            if(strcmp(ci, (*vUsuario)[i].Usuario) == 0){
                                controlFor = 1;
                                (*vUsuario)[i] = (*vUsuario)[(*nUsuario) - 1];
                                (*nUsuario)--;
                            }
                        }
                    }
                }while(control);
            }
            else if(seleccion == 2){
                do{
                    control = 0;
                    printf("Nombre del usuario:");
                    fflush(stdin);
                    fflush(stdout);
                    scanf("%s", ci);
                    //fgets(ci, 29,stdin);
                    printf("%s", ci);
                    fflush(stdin);
                    if(strlen(ci)>20){
                        printf("\nError, el nombre es demasiado larga, introduce solo el primer apellido o utiliza abreviatura.\n");
                        
                        control = 1;
                    }
                    else if(strchr(ci, '-') != NULL){
                        printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                        
                        control = 1;
                    }
                    else if(!(strcmp(ci, "NULL") == 0)){
                        controlFor = 0;
                        for(i = 0; i < *nUsuario && controlFor == 0; i++){
                            if(strcmp(ci, (*vUsuario)[i].Nomb_usuario) == 0){
                                controlFor = 1;
                                (*vUsuario)[i] = (*vUsuario)[(*nUsuario) - 1];
                                (*nUsuario)--;
                            }
                        }
                    }
                }while(control);
            }
            else {
                printf("\nError, no es una de las opciones, intentelo de nuevo.\n");
                control = 1;
            }
        }while(control);

    }
    else {
        do{         //conoce el usuario
            control = 0;
            printf("ID_Usuario:");
            fflush(stdin);
            scanf("%i", &id);
            fflush(stdin);
            if (id > 1000 ){
                printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                
                control = 1;
            }
            else if(id <= 0){
                printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                
                control = 1;
            }
            else {
                controlFor = 1;
                    //printf("hola");
                for(i = 0; i < (*nUsuario) && controlFor; i++){
                        //printf("%i", (*nUsuario));
                    if(id == (*vUsuario)[i].id_usuario){
                        controlFor = 0;
                        (*vUsuario)[i] = (*vUsuario)[(*nUsuario) - 1];
                        (*nUsuario)--;
                    }
                }
            }
        }while(control);

    }

    (*vUsuario) = (usuario*)realloc(*vUsuario, (*nUsuario) * sizeof(usuario));
}       //mirar para hacerlo funciones para mayor legibilidad
void modificarUsuario(usuario** vUsuario, int* nUsuario){

    char ci[30];
    char ca;

    int control = 0, id = 0,seleccion = 0, i = 0, controlFor = 0, it = 0;

    do{
        control = 0;
        printf("Id del usuario a modificar\n");
        scanf("%i", &id);
        if (id >= 1000){
            printf("\nError, numero incorrecto, intentelo de nuevo.\n");
            
            control = 1;
        }
        else if(id <= 0){
            printf("\nError, numero incorrecto, intentelo de nuevo.\n");
            
            control = 1;
        }
    }while(control);

    controlFor = 0;
    for(i = 0; i < *nUsuario && controlFor == 0; i++){
        if(id == (*vUsuario)[i].id_usuario){
            it = i;
            controlFor = 1;
        }
    }

    do{
        control = 0;
        printf("Selecciona una:\n\n1-Usuario\n2-Nombre Usuario\n3-Contraseña\n4-Perfil\n\n");
        scanf("%i", &seleccion);
        if (seleccion == 1){
            do{
                control = 0;
                printf("Usuario:");
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else if(strlen(ci)>5){
                    printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else if(strchr(ci, '-') != NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else {
                    strcpy((*vUsuario)[it].Usuario, ci);
                }
            }while(control);
        }
        else if (seleccion == 2){
            do{
                control = 0;
                printf("Nombre del usuario:");
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else if(strlen(ci)>21){
                    printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else if(strchr(ci, '-') != NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else {
                    strcpy((*vUsuario)[it].Nomb_usuario, ci);
                }
            }while(control);
        }
        else if (seleccion == 3){
            do{
                control = 0;
                printf("Contrase%ca;", ñ);
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ninguna contraseña, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else if(strlen(ci)>9){
                    printf("\nError, la contrase%ca es demasiado larga, intentelo de nuevo.\n", ñ);
                    
                    control = 1;
                }
                else if(strchr(ci, '-') != NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    
                    control = 1;
                }
                else{
                    strcpy((*vUsuario)[it].Contrasenna, ci);
                }
            }while(control);
        }
        else if (seleccion == 4){
            do{
                control = 0;
                printf("%csera un usuario administrador? (s/n)\n",in);
                scanf("%s", ci);
                if (ci[0] == 's' || ci[0] == 'S'){
                    (*vUsuario)[it].Perfil_usuario = 1;
                }
                else if(ci[0] == 'n' || ci[0] == 'N'){
                    (*vUsuario)[it].Perfil_usuario = 0;
                }
                else {
                    printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
                    
                    control = 1;
                }
            }while(control);
        }
        else {
            printf("\nError, no es una de las opciones, intentelo de nuevo.\n");
            
            control = 1;
        }
    }while(control);


}
void listaUsuarios(usuario* vUsuario, int *nUsuario){

    int i;

    printf("Id/Nombre/Tipo/Usuario/Contraseña\n\n");
    for(i = 0; i < *nUsuario; i++){
        if(vUsuario[i].Perfil_usuario == 1){
            printf("%i/%s/administrador/%s/%s\n", vUsuario[i].id_usuario, vUsuario[i].Nomb_usuario, vUsuario[i].Usuario, vUsuario[i].Contrasenna);
        }
        else {
            printf("%i/%s/No administrador/%s/%s\n", vUsuario[i].id_usuario, vUsuario[i].Nomb_usuario, vUsuario[i].Usuario, vUsuario[i].Contrasenna);
        }
        
    }

}

void cargarUsuarios(usuario** vUsuarios, int* nUsuarios){
    FILE* archivo;
    usuario tem;
    int n = 0;

    archivo = fopen("./usuarios.txt", "r");

    *vUsuarios = NULL;
    (*nUsuarios) = 0;

    while (!feof(archivo)){

        (*nUsuarios)++;
        *vUsuarios = (usuario*)realloc(*vUsuarios,(*nUsuarios)*sizeof(usuario));
        fscanf(archivo, "%i-%[^-]-%i-%[^-]-%[^\n]\n", &tem.id_usuario, tem.Nomb_usuario, &tem.Perfil_usuario, tem.Usuario, tem.Contrasenna);
        (*vUsuarios)[n].id_usuario = tem.id_usuario;
        strcpy((*vUsuarios)[n].Nomb_usuario, tem.Nomb_usuario);
        (*vUsuarios)[n].Perfil_usuario = tem.Perfil_usuario;
        strcpy((*vUsuarios)[n].Usuario, tem.Usuario);
        strcpy((*vUsuarios)[n].Contrasenna, tem.Contrasenna);
        n++;
    }

    fclose(archivo);

}
void descargarUsuarios(usuario* vUsuarios, int* nUsuarios){
    FILE* archivo;
    usuario tem;
    int n = 0;

    archivo = fopen("usuario.txt", "w");

    while (n < (*nUsuarios)){
        //printf("%i\n", *nUsuarios);
        fprintf(archivo, "%i-%s-%i-%s-%s\n", vUsuarios[n].id_usuario, vUsuarios[n].Nomb_usuario, vUsuarios[n].Perfil_usuario, vUsuarios[n].Usuario, vUsuarios[n].Contrasenna);
        n++;

    }

    fclose(archivo);
}
void menuPrincipal(usuario* vUsuario, int *nUsuario){

    char* user = malloc(12*sizeof(char));
    char* cont = malloc(12*sizeof(char));

    int control = 0, i = 0;

    printf("################################\n########Cuaderno Dijital########\n################################\n\n");
    do{
        control = 0;
        printf("Usuario:");
        scanf("%s", user);
        printf("contrase%ca:", ñ);
        scanf("%s", cont);
        if (user[0] == '\0' || cont[0] == '\0'){
            printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
            
            control = 1;
        }
        else if(strlen(user)>6 || strlen(cont)>9){
            printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
            
            control = 1;
        }
        else {
            control = !(iniciarSesion(user, cont, vUsuario, *nUsuario));
            if (control == 1){
                printf("\nError, usuario incorrecto o contrase%ca, intentelo de nuevo.\n", ñ);
                
            }
        }
    }while(control);

}
void gestionarUsuario(usuario** vUsuario, int* nUsuario){

    int control, op;



    do{
        control = 0;
        printf("%cQue desea realizar?\n\n1.Dar de alta a un nuevo usuario.\n2.Dar de baja a un usuario\n3.Modificar un usuario\n4.Lista de usuarios\n5.Salir\n",in);
        scanf("%i", &op);
        if (op > 6 || op < 1){
            printf("\nError, no existe esta opcion intentalo de nuevo, intentelo de nuevo.\n");
            
            control = 1;
        }
    }while(control);

    if (op == 1){
        dardeAltaUsuario(vUsuario, nUsuario);
    }
    else if (op == 2){
        dardeBajaUsuario(vUsuario, nUsuario);
    }
    else if (op == 3){
        modificarUsuario(vUsuario, nUsuario);
    }
    else if (op == 4){
        listaUsuarios(*vUsuario, nUsuario);
    }
}//error terminar de nuevo
