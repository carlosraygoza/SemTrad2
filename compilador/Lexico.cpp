//
//  Lexico.cpp
//  compilador
//
//  Created by Carlos Raygoza
//  Copyright © 2017 Carlos Raygoza. All rights reserved.
//

#include "Lexico.hpp"

//void Lexico::leer(string cadena){
//    int i;
//
//    for (i = 0; i < cadena.size(); i++){
//        //Envía cada caracter al método Automata.
//        c = cadena[i];
////        cout<<"cadena: "<<cadena.size()<<" vs i:"<<i<<endl;
//       // Automata(c,true);
//    }
//    
//    if(i==cadena.size()){
//        //se ha leído toda la cadena
////        cout<<"fin"<<endl;
//       // Automata(c, false);
//        
//        if(c!=' '){
//            cout<<"esto fue lo ultimo guardado: "<<c<<endl;
//        }
//    }
//}

void Lexico::setCadena(string cad){
    cadena = cad;
}

string Lexico::getCadena(){
    return cadena;
}

void Lexico::sigCaracter(){
    
    
}

void Lexico::Automata(char c, bool final){
    estado = 0; //inicio de automata
    
    while (final) {
//        c = sigCaracter();
//        c == leer();
//        cout<<"WHILE"<<endl;
        switch (estado) {
            case 0:
                //NÚMERICO edo 0
                cout<<"estado 0 "<<endl;
                if(isdigit(c)){
                    estado = 1;
                    esTipo(token += c, 1);
                }
                // else NO ES DIGITO
                final = false;
                break;
            case 1:
                //NÚMERICO edo 1
                cout<<"estado 1 "<<endl;
                if(isdigit(c)){
                    estado = 1;
                    esTipo(token += c, 1);
                }else{
                    break;
                }
                break;
            case 2:
                // REAL edo 2
                if(c=='.'){
                    estado = 3;
                    esTipo(token += c, 2);
                    cout<<"this is a point"<<endl;
                }
                
                break;
                
            default:
                break;
        }
    }
}

bool Lexico::esTipo(char token, int tipo){
    Lexico l;
    
//    if ((l.tipoAnterior == 1 && tipo == 2)) {//&& (l.tipoAnterior != tipo)) {
//        
//    }
    tipoAnterior = tipo;
    
    
    Tipos t;
    switch (tipo) {
        case  t.IDENTIFICADOR: // letra (letra|digito)*
            
            break;
        case  t.ENTERO: //0, 1, ... , 9
            cout<<"Tipo de dato: ENTERO"<<endl;
            break;
        case  t.REAL: // 0.10
            cout<<"Tipo de dato: REAL"<<endl;
            break;
//            CADENA = 3:
//        TIPO: //int, float, void
//        SUMA: //+ -
//        MULTIP: //* /
//        RELACIONAL: // <, <=, >, >=
//        OR: // ||
//        AND: // &&
//        NOT: // !
//        IGUALDAD: // ==, !=
//        PUNTOCOMA: // ;
//        COMA: // ,
//        ABRE_PARENTESIS: // (
//        CIERRA_PARENTESIS: // )
//            ABRE_LLAVE = 16; // {
//             CIERRA_LLAVE = 17; // }
//            IGUAL = 18; // =
//           IF = 19;
//            WHILE = 20;
//             RETURN = 21;
//            ELSE = 22;
//            DINERO = 23; // $
    
            
        default:
            break;
    }
    
    
    
    return false;
}

bool Lexico::esLetra(char c){
    return isalpha(c) || c=='_';
}

bool Lexico::esEspacio(char c){
    return c== ' ' || c== '\t';
}
