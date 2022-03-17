#include "LoginUsuarios.h"

//esta es una estructura de apoyo la cual se utiliza en los usuarios para facilitar la rapidez a la hora de deccidir el numero nuevo en el sistema
//consiste en un vector de booleanos(como en c no hay de enteros), que guardan un uno si ese id esta en uso y un 0 si no lo esta
//de esta forma tenemos controlados el numeo de ids disponibles de foma mas sencill y visible
//ademas la estructura almacenara la menor id disponible lo que sumado a que este vector tiempre estara ordenado aumenta la eficuencia de la eleccion de entero
//esto para numero pequeños no es realmete un coste demasiado dispar al de este pero teneiendo pero esto creo que es lo realmente correcto para los casos generales sin ver el contezto de este proyecto
struct identificacion_usuario //meter en una nestructura mas grande con la otra estructura
{
    int numero[1000];
    int ultimo;
};

struct identificacion_usuario identificacion;
char ñ = 164;
char in = 168;

//cambiar los parematros de entrada del leer documentos
//cambiar para que no se permita el caracter -

int iniciarSesion(char* s_usuario, char* s_contraseñnna, usuario* vUsuario, int nUsuario);
void dardeAltaUsuario(usuario**, int* nUsuario);
void dardeBajaUsuario(usuario**, int* nUsuario);
void modificarUsuario(usuario**, int* nUsuario);
void listaUsuarios(usuario*, int* nUsuario);
void siguenteid();
void descartarid(int n);

int iniciarSesion(char* s_usuario, char* s_contrasenna, usuario* vUsuario, int nUsuario){

    int i = 0;
    int salida = 0;

    do {

        if (strcmp(s_usuario, vUsuario[i].Usuario) == 0){
            if (strcmp(s_contrasenna, vUsuario[i].Contrasenna) == 0){
                salida = 1;
            }
        }

    } while (salida || i < nUsuario);

    return salida;
        
}
void dardeAltaUsuario(usuario** vUsuario, int* nUsuario){

    char* ci;   //cadena intermedia
    char ca;    //caracter administrador

    ci = (char *) malloc(100*sizeof(char));

    int control = 0,i = 0,controlFor = 0;

    //añade un nuevo espacio al vector dinamico
    *vUsuario = (usuario*)realloc(*vUsuario, ++(*nUsuario) * sizeof(usuario));

    printf("Datos del nuevo usuario:\n\n");
    do{     
        control = 0;
        printf("Usuario:");
        scanf("%s", ci);
        if (ci[0] == '\0'){
            printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else if(strlen(ci)>6){
            printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else if(strchr(ci, '-') == NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else {
            strcpy((*vUsuario)[*nUsuario].Usuario, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("Contrase%ca;", ñ);
        scanf("%s", ci);
        if (ci[0] == '\0'){
            printf("\nError, no ha escrito ninguna contraseña, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else if(strlen(ci)>9){
            printf("\nError, la contrase%ca es demasiado larga, intentelo de nuevo.\n", ñ);
            get();
            control = 1;
        }
        else if(strchr(ci, '-') == NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else{
            strcpy((*vUsuario)[*nUsuario].Contrasenna, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("Nombre del usuario:");
        scanf("%s", ci);
        if (ci[0] == '\0'){
            strcpy((*vUsuario)[*nUsuario].Nomb_usuario, "ANONIMO");
        }
        else if(strlen(ci>21)){
            printf("\nError, el nombre es demasiado larga, introduce solo el primer apellido o utiliza abreviatura.\n");
            get();
            control = 1;
        }
        else if(strchr(ci, '-') == NULL){
            printf("\nError, caracter no permitico, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else{
            controlFor = 0;
            for(i = 0; i < nUsuario || controlFor; i++){
                if(strcmp(ci, (*vUsuario)[i].Usuario) == 0){
                    controlFor = 1;
                }
            }
            if (controlFor == 0){
                strcpy((*vUsuario)[*nUsuario].Nomb_usuario, ci);
            }
            else{
                printf("\nEste nombre ya esta registrado, utiliza otro nombre.\n");
                get();
                control = 1;
            }
        }
    }while(control);
    do{
        control = 0;
        printf("%csera un usuario administrador? (s/n)\n",in);
        scanf("%c", &ca);
        if (ca == 's' || ca == 'S'){
            (*vUsuario)[*nUsuario].Perfil_usuario = 0;
        }
        else if(ca == 'n' || ca == 'N'){
            (*vUsuario)[*nUsuario].Perfil_usuario = 1;
        }
        else {
            printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
            get();
            control = 1;
        }
    }while(control);
    
    if (identificacion.numero[0] > 0){
        (*vUsuario)[*nUsuario].id_usuario = identificacion.ultimo;
        siguienteid();
    }
    
}
//da de baja un usuario
void dardeBajaUsuario(usuario** vUsuario, int* nUsuario){

    char* ci;
    char ca;
    
    int control = 0, eleccion = 0,controlFor = 0,i = 0, id = 0, seleccion = 0;
    
    do{
        control = 0;
        printf("%cSabes que usuario quieres eliminar? (s/n)\n", in);
        scanf("%c", &ca);
        if (ca == 's' || ca == 'S'){
            eleccion = 0;
        }
        else if(ca == 'n' || ca == 'N'){
            eleccion = 1;
        }
        else {
            printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
            get();
            control = 1;
        }
    }while(control);

    

    if (eleccion == 1){     //tiene diferentes parametros para buscar que eliminar
        
        do{                 
            control = 0;
            printf("Selecciona una:\n\n1-Id\n2-Usuario\n3-Nombre Usuario\n\n", in);
            scanf("%c", &seleccion);
            if (seleccion == 1){
                do{         //eleccion de
                    control = 0;
                    printf("ID_Usuario:");
                    scanf("%i", &id);
                    if (id >= 1000 && id != 32765){
                        printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(id <= 0){
                        printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(!(id == 32765)){
                        controlFor = 0;
                        for(i = 0; i < *nUsuario || controlFor == 0; i++){
                            if(id == (*vUsuario)[i].Usuario){
                                controlFor = 1;
                                (*vUsuario)[i] = (*vUsuario)[*nUsuario];
                                (*nUsuario)--;
                                descartarid(i);
                            }
                        }
                    }
                }while(control);
            }
            else if(seleccion == 2){
                do{
                    control = 0;
                    printf("Usuario:");
                    scanf("%s", ci);
                    if (ci[0] == '\0'){
                        printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(strlen(ci)>6){
                        printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(strchr(ci, '-') == NULL){
                        printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(!(strcmp(ci, "NULL") == 0)){
                        controlFor = 0;
                        for(i = 0; i < *nUsuario || controlFor == 0; i++){
                            if(strcmp(ci, (*vUsuario)[i].Usuario) == 0){
                                controlFor = 1;
                                (*vUsuario)[i] = (*vUsuario)[*nUsuario];
                                (*nUsuario)--;
                                descartarid(i);
                            }
                        }
                    }
                }while(control);
            }
            else if(seleccion == 3){
                do{
                    control = 0;
                    printf("Nombre del usuario:");
                    scanf("%s", ci);
                    if (ci[0] == '\0'){
                        strcpy((*vUsuario)[*nUsuario].Nomb_usuario, "ANONIMO");
                    }
                    else if(strlen(ci>21)){
                        printf("\nError, el nombre es demasiado larga, introduce solo el primer apellido o utiliza abreviatura.\n");
                        get();
                        control = 1;
                    }
                    else if(strchr(ci, '-') == NULL){
                        printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                        get();
                        control = 1;
                    }
                    else if(!(strcmp(ci, "NULL") == 0)){
                        controlFor = 0;
                        for(i = 0; i < *nUsuario || controlFor == 0; i++){
                            if(strcmp(ci, (*vUsuario)[i].Nomb_usuario) == 0){
                                controlFor = 1;
                                (*vUsuario)[i] = (*vUsuario)[*nUsuario];
                                (*nUsuario)--;
                                descartarid(i);
                            }
                        }
                        if (controlFor == 0){
                            strcpy((*vUsuario)[*nUsuario].Nomb_usuario, ci);
                        }
                        else{
                            printf("\nEste nombre ya esta registrado, utiliza otro nombre.\n");
                            get();
                            control = 1;
                        }
                    }
                }while(control);
            }
            else {
                printf("\nError, no es una de las opciones, intentelo de nuevo.\n");
                get();
                control = 1;
            }
        }while(control);

    }
    else {
        do{         //conoce el usuario
            control = 0;
            printf("ID_Usuario:");
            scanf("%i", &id);
            if (id >= 1000 && id != 32765){
                printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                get();
                control = 1;
            }
            else if(id <= 0){
                printf("\nError, numero incorrecto, intentelo de nuevo.\n");
                get();
                control = 1;
            }
            else if(!(id == 32765)){
                controlFor = 0;
                for(i = 0; i < *nUsuario || controlFor == 0; i++){
                    if(id == (*vUsuario)[i].Usuario){
                        controlFor = 1;
                        (*vUsuario)[i] = (*vUsuario)[*nUsuario];
                        (*nUsuario)--;
                        descartarid(i);
                    }
                }
            }
        }while(control);

    }

    vUsuario = (usuario*)realloc(vUsuario, --(*nUsuario) * sizeof(usuario));
}       //mirar para hacerlo funciones para mayor legibilidad
void modificarUsuario(usuario** vUsuario, int* nUsuario){

    char* ci;
    char ca;
    
    int control = 0, id = 0,seleccion = 0, i = 0, controlFor = 0, in = 0;
    
    do{
        control = 0;
        printf("Id del usuario a modificar\n");
        scanf("%i", &id);
        if (id >= 1000){
            printf("\nError, numero incorrecto, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else if(id <= 0){
            printf("\nError, numero incorrecto, intentelo de nuevo.\n");
            get();
            control = 1;
        }
    }while(control);

    controlFor = 0;
    for(i = 0; i < *nUsuario || controlFor == 0; i++){
        if(id == (*vUsuario)[i].id_usuario){
            i = in;
            controlFor = 1;
        }
    }

    do{                 
        control = 0;
        printf("Selecciona una:\n\n1-Usuario\n2-Nombre Usuario\n3-Contraseña\n4-Perfil\n\n", in);
        scanf("%c", &seleccion);
        if (seleccion == 1){
            do{
                control = 0;
                printf("Usuario:");
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else if(strlen(ci)>6){
                    printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else if(strchr(ci, '-') == NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else {
                    strcpy((*vUsuario)[in].Usuario, ci);
                }
            }while(control);
        }
        if (seleccion == 2){
            do{
                control = 0;
                printf("Nombre del usuario:");
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else if(strlen(ci)>21){
                    printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else if(strchr(ci, '-') == NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else {
                    strcpy((*vUsuario)[in].Usuario, ci);
                }
            }while(control);
        }
        if (seleccion == 3){
            do{
                control = 0;
                printf("Contrase%ca;", ñ);
                scanf("%s", ci);
                if (ci[0] == '\0'){
                    printf("\nError, no ha escrito ninguna contraseña, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else if(strlen(ci)>9){
                    printf("\nError, la contrase%ca es demasiado larga, intentelo de nuevo.\n", ñ);
                    get();
                    control = 1;
                }
                else if(strchr(ci, '-') == NULL){
                    printf("\nError, caracter no permitico, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
                else{
                    strcpy((*vUsuario)[in].Contrasenna, ci);
                }
            }while(control);
        }
        if (seleccion == 4){
            do{
                control = 0;
                printf("%csera un usuario administrador? (s/n)\n",in);
                scanf("%c", &ca);
                if (ca == 's' || ca == 'S'){
                    (*vUsuario)[in].Perfil_usuario = 0;
                }
                else if(ca == 'n' || ca == 'N'){
                    (*vUsuario)[in].Perfil_usuario = 1;
                }
                else {
                    printf("\nError, no es uno de los caracteres permitidos, intentelo de nuevo.\n");
                    get();
                    control = 1;
                }
            }while(control);
        }
        else {
            printf("\nError, no es una de las opciones, intentelo de nuevo.\n");
            get();
            control = 1;
        }
    }while(control);


}
void listaUsuarios(usuario* vUsuario, int* nUsuario){

    int i;
    
    for(i = 0; i < *nUsuario; i++){
        printf("%i/%s/%i/%s/%s", vUsuario[i].id_usuario, vUsuario[i].Nomb_usuario, vUsuario[i].Perfil_usuario, vUsuario[i].Usuario, vUsuario[i].Contrasenna);
    }
    
}
void siguenteid(){
    
    int i, control = 1;
    if (identificacion.numero[0] < 999){
        for(i = 0; i < 1000 && control; i++){
            if(identificacion.numero[i] = 0){
                control = 0;
                identificacion.ultimo = i;
            }
        }
        identificacion.numero[0]++;
    }
}
void descartarid(int n){

    identificacion.numero[n] = 0;
    if (identificacion.ultimo > n){
        identificacion.ultimo = n;
    }
}

void cargarUsuarios(usuario** vUsuarios, int* nUsuarios){
    FILE* archivo;
    usuario tem;
    int n = 0;

    archivo = fopen("usuario.txt", "r");

    while(feof(archivo)){
        fscanf(archivo, "%[^\n]\n");
        (*nUsuarios)++;
    }

    *vUsuarios = (usuario*)malloc((*nUsuarios)*sizeof(usuario*));
    rewind(archivo);

    while (n < (*nUsuarios)){

        fscanf(archivo, "%i/%[^-]/%i/%[^-]/%[^-]\n", tem.id_usuario, tem.Nomb_usuario, tem.Perfil_usuario, tem.Usuario, tem.Contrasenna);
        (*vUsuarios)[n].id_usuario = tem.id_usuario;
        strcpy((*vUsuarios)[n].Nomb_usuario, tem.Nomb_usuario);
        (*vUsuarios)[n].Perfil_usuario = tem.Perfil_usuario;
        strcpy((*vUsuarios)[n].Usuario, tem.Usuario);
        strcpy((*vUsuarios)[n].Contrasenna, tem.Contrasenna);
        n++;
    }

    fclose(archivo);
    free(archivo);
}
void descargarUsuarios(usuario* vUsuarios, int* nUsuarios){
    FILE* archivo;
    usuario tem;
    int n = 0;

    archivo = fopen("usuario.txt", "w");

    while (n < nUsuarios){

        fprintf(archivo, "%i/%s/%i/%s/%s\n", vUsuarios[n].id_usuario, vUsuarios[n].Nomb_usuario, vUsuarios[n].Perfil_usuario, vUsuarios[n].Usuario, vUsuarios[n].Contrasenna);
        n++;

    }

    fclose(archivo);
    free(archivo);
}
void menuPrincipal(usuario* vUsuario, int *nUsuario){

    char* user;
    char* cont;

    int control = 0, i = 0;

    printf("################################\n########Cuaderno Dijital########\n################################\n\nUsuario:");
    do{     
        control = 0;
        printf("Usuario:");
        scanf("%s", user);
        printf("contrase%a", ñ);
        scanf("%s", cont);
        if (user[0] == '\0' || cont[0] == '\0'){
            printf("\nError, no ha escrito ningun nombre, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else if(strlen(user)>6 || strlen(cont)>9){
            printf("\nError, el usuario es demasiado largo, intentelo de nuevo.\n");
            get();
            control = 1;
        }
        else {
            control = !(iniciarSesion(user, cont, vUsuario, &nUsuario));
            if (control == 1){
                printf("\nError, usuario incorrecto o contrase%ca, intentelo de nuevo.\n", ñ);
                get();
            }
        }
    }while(control);

}
void gestionarUsuario(usuario** vUsuario, int nUsuario){
    
    int control, op;

    

    do{
        control = 0;
        printf("%cQue desea realizar?\n\n1.Dar de alta a un nuevo usuario.\n2.Dar de baja a un usuario\n3.Modificar un usuario\n5.Salir\n",in);
        scanf("%i", &op);
        if (op > 5 || op >1){
            printf("\nError, no existe esta opcion intentalo de nuevo, intentelo de nuevo.\n");
            get();
            control = 1;
        }
    }while(control);

    if (op == 1 ){
        void dardeAltaUsuario(usuario**, int* nUsuario);
    }
    else if (op == 2 ){
        void dardeBajaUsuario(usuario**, int* nUsuario);
    }
    else if (op == 3 ){
        void modificarUsuario(usuario**, int* nUsuario);
    }
    else if (op == 4 ){
        void listaUsuarios(usuario*, int* nUsuario);
    }
}