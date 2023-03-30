#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashtable.h"
// defino las constantes c1 y c2 para la funcion quadratic
#define C1 1  
#define C2 3

//----------------------------------------------------------------
//FUNCIONES HASH
//----------------------------------------------------------------
int h_prima_k (int k, int m)
{
    return k % m;
}

int h_1_k (int k, int m)
{
    return k % m;
}

int h_2_k (int k, int m)
{
    return 1 + (k % (m-1));
}

int h_linear(int k, int i, int m)
{
    return (h_prima_k(k, m) + i) % m;
}

int h_quadratic(int k, int i , int m)
{
    return (h_prima_k(k,m) + C1 * i + C2 * i * i) % m;
}

int h_double(int k, int i, int m)
{
    return (h_1_k(k,m) + i * h_2_k(k,m)) % m;
}
//----------------------------------------------------------------
//FUNCIONES DE LAS HASH TABLE
//----------------------------------------------------------------
void hashtable_init (hash_node ** HT, int hts)
{
    int counter = 0; // contador para recorrer HT

    for (counter = 0; counter < hts; counter++) {  //recorro HT a traves de un for hasta el maximo del array lo cual es hts(ht size)
        HT[counter] = malloc(sizeof(hash_node)); // pido memoria para cada nodo 
        HT[counter]->key = 0; // defino la key inicialmente en 0
        HT[counter]->value = ' ';  //dejo value como libre para ocupar
    }
}

void hashtable_print (hash_node ** HT, int HT_SIZE, FILE * archivo)
{
    int counter = 0; // contador para recorrer HT
    for (counter = 0; counter < HT_SIZE; counter++) // recorro HT a traves de un for hasta el maximo del array lo cual es HT_SIZE
    {
        if (counter % 100 == 0 && counter != 0) fprintf(archivo, "\n"); // hago un if para generar filas cada 100 columnas
        fprintf(archivo, "%c",HT[counter]->value); // printeo en el archivo el valor de mi respectivo value en cada nodo
    }
}

int hashtable_insert(hash_node ** HT, int HT_SIZE, int key, int type)
{
    int i = 0; // valor i para recorrer HT
    int j; // valor para ver que funcion hash ocupar
    while( i != HT_SIZE) // funciona hasta que lleguemos a un hash overflow aumentado i buscando la siguiente casilla libre segun su funcion hash
    {
        switch(type) //  veo que tipo de funcion hash es requerido segun el parametro type y lo defino en j
        {
            case 0:
                j = h_linear(key, i, HT_SIZE);
                break;
            case 1:
                j = h_quadratic(key, i, HT_SIZE);
                break;
            case 2:
                j = h_double(key, i , HT_SIZE);
                break;
        }
        if (HT[j]->value == ' ') // veo si la casilla esta vacia
        {
            HT[j]->value = 'x'; // la marco como ocupada
            HT[j]->key = key; // le inserto el valor de mi key
            return 1; // retorno 1 para ir sumando las casillas ocupadas de mis elementos ingresados en el main y termino el ciclo antes del mensaje de error
        } else if (HT[j]->value == 'x'){ // si esta ocupada aumento i para buscar la siguiente disponible segun mi funcion hash
            i = i + 1;
        }
    }
    printf("Error: hash table overflow\n"); // si i recorrio todo el hash_size printeo el error de overflow
    return 0;
}
