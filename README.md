# Hash-Table-Collision-Handling
Esta carpeta contiene los siguientes archivos:

- Folder "Resultados_que_analice": guarde la situacion donde corri el codigo y analice patrones.

- main.c: En este archivo encontraremos el codigo principal de la tarea.

- hashtable.h: En este archivo encontraremos la declaracion de las funciones
a implementar las cuales son las siguientes:
	
	- Funciones Hash(Resumen general por simplicidad):
		* Tipo de funcion: int.
		* Parametros de entrada: (int k, int i, int m). Donde k = key ingresada, i = valor de iteracion en caso de colision, m = modulo que es el tamaño de la Hash Table
		* Funcionalidad: Esta funciones respecto a una key ingresada nos devuelve un index de la Hash Table donde puede entrar la key.
		* Retorna: El index de la hash table donde puede ingresar.
	- hashtable_init:
		* Tipo de funcion: void.
		* Parametros de entrada: (hash_node ** HT, int HT_SIZE). Donde HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table.
		* Funcionalidad: Esta funcion escribe en los archivos de salida los mapas de ocupacion.
		* Retorna: -.
	- hashtable_print:
		* Tipo de funcion: void.
		* Parametros de entrada: (hash_node ** HT, int HT_SIZE, FILE * archivo). Donde HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table ; archivo = Archivo de salida.
		* Funcionalidad: Esta funcion escribe en los archivos de salida los mapas de ocupacion.
		* Retorna: -.
	- hashtable_insert:
		* Tipo de funcion: int.
		* Parametros de entrada: (hash_node ** HT, int HT_SIZE, int key, int type). Donde Parametros de entrada: HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table; key = Key a ingresar, type = tipo de funcion hash a utilizar(0:linear, 1:quadratic, 2:double).
		* Funcionalidad: Esta funcion inserta una key en mi hash table dependiendo del tipo de funcion hash a utilizar(linear:0, quadratic:1, double:2).
		* Retorna: -.

- hashtable.c: En este archivo se encuentra la implementacion de las funciones declaradas en hashtable.h.
-------------------------------------------------------------------------------

Compilacion

Para compilar el programa debemos de conectarnos al servidor de elo aragorn
a traves de nuestra terminal favorita, luego con ambos archivos y en la 
ubicacion de la carpeta compilar de la siguiente manera:

	gcc main.c -o main.exe
	
----------------------------------------------------------------------------

Ejecucion

Para ejecutar el programa luego de compilar deberemos ejecutar nuestro
archivo main.exe, estando todavia en la ubicacion de la carpeta de la
siguiente manera:

	./main.exe TAMAÑO_TABLA_HASH Elementos_ingresar_mapa_1 Elementos_ingresar_mapa_2 Elementos_ingresar_mapa_3 Elementos_ingresar_mapa_4 

Al ejecutar el programa se generaran 4 mapas de ocupacion para cada tipo de funcion hash(linear,quadratic,double) dependiendo de los
elementos a ingresar indicados. Ejemplo de ejecucion:

    ./main.exe 2000 100 150 500 1000 1500

