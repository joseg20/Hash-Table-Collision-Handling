#ifndef __TAREA3__
#define __TAREA3__

typedef struct hash_node_  // Estructura de las casillas de mi hash table
{
    int key; // key ingresada
    char value; // ' ' vacia ; 'x' ocupada
} hash_node;

//----------------------------------------------------------------
//FUNCIONES HASH
//----------------------------------------------------------------
int h_prima_k (int k, int m);

int h_1_k (int k, int m);

int h_2_k (int k, int m);

int h_linear(int k, int i, int m);

int h_quadratic(int k, int i , int m);

int h_double(int k, int i, int m);
//----------------------------------------------------------------
//FUNCIONES DE LAS HASH TABLE
//----------------------------------------------------------------
//hashtable_init: Esta funcion inicializa una Hash table.
void hashtable_init (hash_node ** HT, int HT_SIZE);  // Parametros de entrada: HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table.
//hashtable_print: Esta funcion escribe en los archivos de salida los mapas de ocupacion.
void hashtable_print (hash_node ** HT, int HT_SIZE, FILE * archivo); // Parametros de entrada: HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table ; archivo = Archivo de salida.
//hashtable_insert: Esta funcion inserta una key en mi hash table dependiendo del tipo de funcion hash a utilizar(linear, quadratic, double).
int hashtable_insert(hash_node ** HT, int HT_SIZE, int key, int type); // Parametros de entrada: HT = Array de la hash table ; HT_SIZE = Tamanio de la hash table; key = Key a ingresar, type = tipo de funcion hash a utilizar(0:linear, 1:quadratic, 2:double).


#endif // __TAREA3__

