#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/hashtable.h"
#include "hashtable.c"
#include <time.h>

int main(int argc, char **argv)
{   
    //--------------------------------------------------
    // VARIABLES INICIALES :
    //--------------------------------------------------
    int HASHTABLE_SIZE; // Variables para datos de entrada a traves de la ejecucion del .exe
    int elementos_ingresar_0;
    int elementos_ingresar_1;
    int elementos_ingresar_2;
    int elementos_ingresar_3;
    int elementos_ingresar_case; //  Variable que ira evaluando elementos_ingresar_x

    HASHTABLE_SIZE = atoi(argv[1]); // 2000
    elementos_ingresar_0 = atoi(argv[2]); // 100
    elementos_ingresar_1 = atoi(argv[3]); // 500 
    elementos_ingresar_2 = atoi(argv[4]); // 1000 
    elementos_ingresar_3 = atoi(argv[5]); // 1500

    int i_while= 0; // Variable para evaluar los casos de elementos_ingresar_x

    int NC_Linear;  // Variables para guardar el numero de casillas ocupadas
    int NC_Quadratic;
    int NC_Double;

    char cadena_NC_Linear[80]; // Variables para guardar el nombre de los archivos de salida
    char cadena_NC_Quadratic[80];
    char cadena_NC_Double[80];
    
    //-----------------------------------------------
    // GENERACION NUMEROS ALEATORIOS: Genero 2000 numeros aleatorios a traves de la funcion rand en un array de 2000 casillass
    //-----------------------------------------------
    int array_keys[2000];
    int i;
    srand(time(NULL)); // variable para dar aleatoriedad a la semilla de rand a traves del tiempo

    for (i = 0; i < 2000; i++)
    {
        array_keys[i] = rand()%10000001;
    }
    //-----------------------------------------------
    // Bucle i_while: Genero un loop para evaluar los tamanios de elemento indicado en el .exe del codigo.
    //-----------------------------------------------
    while (i_while <= 3)
    {
        // Realizo un switch el cual por cada iteracion ira cambiando los tamanios ingresados por consola y realizando el codigo nuevamente con el fin de generar 4 mapas por tipo
        switch(i_while)
        {
            case 0:
                elementos_ingresar_case = elementos_ingresar_0; // 100
                break;
            case 1:
                elementos_ingresar_case = elementos_ingresar_1; // 500
                break;
            case 2:
                elementos_ingresar_case = elementos_ingresar_2; // 1000
                break;
            case 3:
                elementos_ingresar_case = elementos_ingresar_3; // 1500
                break;
        }
        // Inicio mis tablas
        hash_node * hashtable1[HASHTABLE_SIZE]; // tabla linear
        hash_node * hashtable2[HASHTABLE_SIZE]; // tabla quadratica
        hash_node * hashtable3[HASHTABLE_SIZE]; // tabla double
        // Inicio mis archivos de salida para cada tipo
        FILE * hash_linear_out;
        FILE * hash_quadratic_out;
        FILE * hash_double_out;
        // Contadores para casillas ocupadar por cada tipo, posteriormente se pondra en el nombre de archivo de los .txt de salida
        NC_Linear = 0;
        NC_Quadratic = 0;
        NC_Double = 0;

        //-----------------------------------------------
        // Inicializacion de mis 3 Hashtables
        //------------------------------------------------
        
        hashtable_init(hashtable1, HASHTABLE_SIZE);
        hashtable_init(hashtable2, HASHTABLE_SIZE);
        hashtable_init(hashtable3, HASHTABLE_SIZE);

        //------------------------------------------------
        // INSERTAR KEYS : En esta parte del codigo inserto las keys indicadas por el tamanio de elementos pedido, a traves de un for e igual aprovecho a contar las casillas ocupadas por los elementos ingresados
        //------------------------------------------------
        printf("Mensajes al ingresar por hash linear:\n"); // Estos mensajes son para separar los overflow de cada tipo(el mensaje de error se encuentra en la funcion insert)
        for (i = 0; i < elementos_ingresar_case; i++)
        {
            NC_Linear = NC_Linear + hashtable_insert(hashtable1, HASHTABLE_SIZE, array_keys[i], 0);
        }
        printf("%d elementos ingresados\n", NC_Linear);
        printf("Mensajes al ingresar por quadratic:\n");
        for (i = 0; i < elementos_ingresar_case; i++)
        {
            NC_Quadratic = NC_Quadratic + hashtable_insert(hashtable2, HASHTABLE_SIZE, array_keys[i], 1);
        }
        printf("%d elementos ingresados\n", NC_Quadratic);
        printf("Mensajes al ingresar por double:\n");
        for (i = 0; i < elementos_ingresar_case; i++)
        {
            NC_Double = NC_Double + hashtable_insert(hashtable3,HASHTABLE_SIZE, array_keys[i], 2);
        }
        printf("%d elementos ingresados\n", NC_Double);

        //------------------------------------------------
        // SALIDA DE ARCHIVOS : La salida de archivos es por cada ciclo, por lo tanto saldran 4 mapas de cada tipo
        //------------------------------------------------
        if (NC_Linear >= 1000) // Me aseguro de que hayan 4 digitos para numeros mayores que 100 de elementos ingresados
        sprintf(cadena_NC_Linear, "bin/hash_linear_%d.txt", NC_Linear); // A traves de sprintf transformo mi contador entero a string y lo concateno donde deberia ir en el nombrbe del archivo
        if (NC_Linear < 1000)
        sprintf(cadena_NC_Linear, "bin/hash_linear_0%d.txt", NC_Linear);

        if (NC_Linear >= 1000)
        sprintf(cadena_NC_Quadratic, "bin/hash_quadratic_%d.txt", NC_Quadratic);
        if (NC_Linear < 1000)
        sprintf(cadena_NC_Quadratic, "bin/hash_quadratic_0%d.txt", NC_Quadratic);
        
        if (NC_Linear >= 1000)
        sprintf(cadena_NC_Double, "bin/hash_double_%d.txt", NC_Double);
        if (NC_Linear < 1000)
        sprintf(cadena_NC_Double, "bin/hash_double_0%d.txt", NC_Double);

        hash_linear_out = fopen(cadena_NC_Linear, "wt"); // abro mis archivos como escritura y con el nombre correcto.
        hash_quadratic_out = fopen(cadena_NC_Quadratic, "wt");
        hash_double_out = fopen(cadena_NC_Double, "wt");

        hashtable_print(hashtable1, HASHTABLE_SIZE, hash_linear_out); // a traves de la funcion hashtable_print imprimo 
        hashtable_print(hashtable2, HASHTABLE_SIZE, hash_quadratic_out); 
        hashtable_print(hashtable3, HASHTABLE_SIZE, hash_double_out); 

        fclose(hash_linear_out); // Cierro mis archivos de escritura
        fclose(hash_quadratic_out);
        fclose(hash_double_out);

        for (i = 0; i < HASHTABLE_SIZE; i++) { // reinicio mis tablas hash y libero la memoria que pedi para ella dentro de hashtable_init
            hashtable1[i]->key = 0;
            hashtable1[i]->value = ' ';
            free(hashtable1[i]);

            hashtable2[i]->key = 0;
            hashtable2[i]->value = ' ';
            free(hashtable2[i]);

            hashtable3[i]->key = 0;
            hashtable3[i]->value = ' ';
            free(hashtable3[i]);
        }


        for (i= 0; i < 80; i++){  // limpio los caracteres de mis cadenas para los titulos
            cadena_NC_Linear[i] = '\0';
            cadena_NC_Quadratic[i] = '\0';
            cadena_NC_Double[i] = '\0';
        }
        i_while++; // sumo 1 a i_while para que se pueda hacer la tabla del siguiente elementos a ingresar indicado
    }    

    return 0;
}

