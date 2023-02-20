// Archivo donde se definen las funciones de la tabla de símbolos 
// la estructura de datos será un árbol binario de búsqueda. Este
// archivo será invocado por los analizadores léxico y sintáctico.

#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definiciones.h"

#define NUM_PALABRAS_RESERVADAS 8

abb tabla;

void insertarElemento(char* id, int valor);
void iniciarTabla();
void liberarTabla();
void imprimirTabla();
void _printTable(abb A);

void iniciarTabla(){
    //inicializamos la estructura de datos
    crear(&tabla);

    //Array que contiene subarrays de dos elementos donde el primer 
    //elemento es un componente lexico y el segundo la palabra reservada

    char *lexemas[NUM_PALABRAS_RESERVADAS];
    lexemas[0] = "import";
    lexemas[1] = "double";
    lexemas[2] = "int";
    lexemas[3] = "while";
    lexemas[4] = "for";
    lexemas[5] = "foreach";
    lexemas[6] = "return";
    lexemas[7] = "void";

    int valores[NUM_PALABRAS_RESERVADAS];
    valores[0] = IMPORT;
    valores[1] = DOUBLE;
    valores[2] = INT;
    valores[3] = WHILE;
    valores[4] = FOR;
    valores[5] = FOREACH;
    valores[6] = RETURN;
    valores[7] = VOID;

    //insertar las palabras reservadas en la tabla de simbolos
    for(int i = 0; i < NUM_PALABRAS_RESERVADAS; i++){
        insertElement(lexemas[i], valores[i]);
    }

}

void insertarElemento(char* id, int valor){
    //creacion tipoelem
    tipoelem e;
    int tam = strlen(id) + 1;
    e.id = (char*)malloc(sizeof(char)*tam);
    strcpy(e.id, id);
    e.valor = valor;
    //insercion en el abb
    insertar(&tabla, e);
}

void liberarTabla(){
    //liberacion del espacio del  abb
    destruir(&tabla);
}

void imprimirTabla(){
    printf("************************");
    printf("TABLA DE SIMBOLOS");
    printf("************************");
    _impresionRecursivaArbol(tabla);

}

void _impresionRecursivaArbol(abb A){
    tipoelem e;
    if(!es_vacio(A)){
        _impresionRecursivaArbol(izq(A));
        leer(A,&e);
        printf("%s --> %d\n",e.id,e.valor);
        _impresionRecursivaArbol(der(A));
    }
}