//archivo que contiene el analizador sintactico
//se encargara de consumir los componentes que el 
//analizador lexico le proporcione (de uno en uno)

#include <stdio.h>
#include <stdlib.h>
#include "analizadorLexico.h"
#include "definiciones.h"

void procesar(){
    //COMPONENTE ACTUAL
    tipoelem e;
    e.identificador = NULL;
    //iniciamos el componente actual con el primer componente del archivo

    //mientras no se alcance el fin de fichero se procesan los componentes
    while(e.valor != EOF){

    }

    
    do{
        nextComponent(&e);

        if(e.valor != EOFVALUE){
            printf("\n<\"%s\", %d>",e.identificador, e.valor);
        }

        //se libera la memoria del identificador
        if(e.identificador != NULL){
            free(e.identificador);
            e.identificador = NULL;
        }

    }while(e.valor != EOFVALUE);

}