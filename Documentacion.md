# Cuaderno Digital

Documentacion de Usuario
=

Desccripción funcional
-
Este programa esta diseñado para ser un apoyo para el profesor de una clase en una escula. Este programa es capaz de administrar el horario, las asignaturas y laos alumnos que tiene un profesor.

Tecnologia
-
Los programas utilizados son visual studio code, tannto para la codificacion como para el git y el markdoun.

Instalaccion
-
Para la instalacion solo es necesario tener el archivo de ejecucion junto a los archivos de carga y descarga.

Acceso al sistema
-
Al abrir el programa, lo primero es iniciar sesion en e sistema, si es correcto, te aparece un menu con todas las opciones, despues es solo necesario seleccionear la opcion de salir y se termina la ejecucion del programa.

Manual de referencia
-

mediante esta aplicacion el profesor puede tener organizado de forma mas comoda tanto los alumnos como las asignaturas. Ademas desde el puento de vista del administrador, que en este caso seria en centro, puedes organiar de forma mas sencilla tus profesores y alumno.

Gia del operador
-
1. Si corresponde al perfilProfesor:Aparecerá una lista con todos los grupos y materias a los que imparte clases en ese día, con elobjetivo de que el profesor seleccione con qué grupo quiere trabajar en ese momento.
  
    ![Imagen no localizada](./recursosDoc/Captura%20de%20pantalla%20de%202022-04-07%2018-53-42.png)
    
    A continuación aparecerá el siguiente menú en pantalla. Suponiendo este ejemplo de selección degrupo y materia:

    ![Imagen no localizada](./recursosDoc/Captura%20de%20pantalla%20de%202022-04-07%2018-46-59.png)

    1. La primera opción mostrará la lista de todos los alumnos del grupo seleccionado que estánmatriculados en la materia correspondiente, pudiendo seleccionar algún alumno en concreto.Una vez hecha la selección se permitirán las siguientes acciones sobre el mismo:
        1. Ficha del alumno.Esta opción mostrará la ficha con los datos personales del alumno y una opción que permitaal profesor la edición para modificar esos datos.

        2. Calificaciones del alumno.Esta opción mostrará la lista de las calificaciones que tiene actualmente el alumno en esamateria,  y  un  menú  de  opciones  para  modificar  una  calificación  de  la  lista,  borrarla  oañadir una nueva al alumno actual.
        
        3. Volver.Esta opción permitirá al usuario volver al menú anterior.

        ![Imagen no localizada](./recursosDoc/Captura%20de%20pantalla%20de%202022-04-07%2018-52-18.png)

    2. La segunda opción permitirá al profesor cambiar de grupo y materia mostrando de nuevo lalista inicial de selección
      
2.  Si corresponde al perfilAdministrador:En el caso de que sea un usuario administrador, el menú que aparecerá en pantalla será el siguiente:

    ![Imagen no localizada](./recursosDoc/Captura%20de%20pantalla%20de%202022-04-07%2018-52-03.png)

    a.  UsuariosPermitirá  al  administrador  gestionar  los  usuarios  del  sistema  pudiendo  dar  de  alta,  baja,modificar y listar usuarios.
    
    b.  Alumnos.Permitirá  al  administrador  gestionar  los  alumnos  del  sistema  pudiendo  dar  de  alta,  baja,modificar  y  listar  alumnos.  Además,  para  un  alumno  seleccionado,  se  permitirá  mostrar  lalista de materias en las que se encuentra matriculado, realizar cambios de matrícula a otrasmaterias, eliminar matrícula en alguna materia y crear nuevas matrículas.
    
    c.  Materias.Permitirá  al  usuario  administrador  gestionar  todas  las  materias  impartidas  en  el  centropudiendo dar de alta, baja, modificar y listar materias.

    d.  Horarios.Permitirá al administrador gestionar todos los horarios de profesores pudiendo añadir horas declase a un profesor concreto, eliminarlas, modificarlas y listar horarios de cada profesor.

Documentación del sistema
=

Especificacion de sitema
-

El problema para una mayor facilidad de los datos para los programadores hemos dividido las funciones segun si maneganlos datos donde se amacenan los datos, y depues los repartimos en tres mododulos, uno para cada participante del grupo. Tras estar hecho todos los modulos, se coordinaran en el main para que el programa funcione correctamente.

Modulos
-

Funciones modulo Usuarios:

- **Menu Principal:**  
    **Precondicion:** que el txt este en el en el directorio donde se alojan los archivos  
    **Poscondicion:** Un vector de la estructura usuario cargada con la informacion del archivo  
    ***void cargarUsuarios(usuario\*\* vUsuarios, int\* nUsuarios);***
- **Gestionar usuarios;**  
    **Precondicion:** el vector de datos a alojar  
    **Poscondicion:** al,acena en el archivo elejido  
    ***void descargarUsuarios(usuario\* vUsuarios, int\* nUsuarios);***  

- **Cargar usuarios;**  
    **Precondicion:** se le da el vector de usuarios  
    **Poscaoncicion:** pausa la ejecucion del codigo hasta que se inicie sesion algien correctamente  
    ***void menuPrincipal(usuario\* vUsuario, int \*nUsuario);***

- **Descargar usuarios**  
    **Precondicion:** se le da el vector de usuarios  
    **Poscondicion:** muetra las diferentes opciones y las realiza  
    ***void gestionarUsuario(usuario\*\* vUsuarios, int\* nUsuarios);*** 

Plan de prueba
-

### Pruebas modulo Usuarios
  
La funcion elejida para este modulo es la funcion de inicio de sesion:

~~~
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
~~~
como podemos observar enn esta  funcion, los parametros de entrada son 4, dos cadena de caracteres que son el usuario y contraseña, un vector de la estructuara usuario, y por ultimo un entero con el numero masximos de elementos en el vector.
    
Esta funcion se encarga de comprobar primero que el usuario existe en el vector, y so es asi que la contraseña dada sea igual a la que hay almavenada.
    
1. Pruevas de caja negra 
  
  
    Para este caso la funcion esta preparada para que dado cualquier cadena devuelva 1 si esta cadena de usuario esta en el vecto y coincide la contraseña o 0 si es cualquier otro usuario. siendo estos casos dos, que el usuario se encuantre y que la contraseña no coincidan o que el usuario no se encuentre, asi que esas seran las tres pruebas de caja negra.

    | Usuario | contraseña | salida |
    | -- | -- | -- |
    | Existe | Existe | 1 |
    | Existe | No Existe | 0 |
    | No Existe | Indiferente | 0 |
      

2. Pruebas de caja blanca 
  
    Para este caso hay que intentar que tosos los posibles casos dados en la funcion sean recorridos. Para esto utilizaremos una de los metodos aprendidos en clase para hace esto. 
    
    Primero realizamos un esquema del algoritmo de esta forma 

    ![Error, archivo no encontrado](./recursosDoc/diagrama%20funcion.png)
      
    Los metos para obtener las posibles rutas:
      
    - Numero de aristas - Numero de nodos + 2 = 9 - 7 + 2 = 4
    - Numero de nodos prediscados + 1 = 3 + 1 = 1
    - nuero de regiones = 4
      
    Para de esta forma sabemos el numero de runas no dependiantes de otras, y estas son:

    1. 1 - 2 - 5 - 6 - 2 - 3 - 4 - 6 - 7
    2. 1 - 2 - 3 - 4 - 5 - 6 - 7
    3. 1 - 2 - 3 - 5 - 6 - 7
    4. 1 - 2 - 5 - 6 - 7
      
    Las cuales se comprueban con un vector de tamaño 2 y poner en cada caso poner un usuario y contraseña diferentes.

    En este caso si el usuario y contraseña son correctos puede ir a uno de los dos, el 2, en el que el usuario correcto es el primer elemento, y el resto de casos accede al camino 1.

    Para el caso de que sea el usuario correcto pero la contraseña no, usara el camino 3

    Por ultimo el caso en que el usuario no esta, que es el caso 4