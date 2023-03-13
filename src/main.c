#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"
#include "analizadorSintactico.h"
#include "sistemaEntrada.h"
#include "analizadorLexico.h"


int main(){
    //dar comienzo al sistema de entrada
    iniciarSistemaEntrada("demo.d");

    //inicializar tabla de simbolos y mostrarla por pantalla
    iniciarTabla();
    imprimirTabla();

    //iniciar el procesamiento del analizador sintactico
    procesar();
    
    //PRUEBAS BORRAR
    
    

    //volver a imprimir la tabla de simbolos
    //imprimirTabla();

    //liberacion de memoria de la tabla y del sistema de entrada
    liberarTabla();
    liberarSistemaEntrada();
    
    //PRUEBAS BORRAR
    //siguienteComponenteLexico();
}