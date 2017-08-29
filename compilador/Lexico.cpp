//
//  Lexico.cpp
//  compilador
//
//  Created by Carlos Raygoza
//  Copyright © 2017 Carlos Raygoza. All rights reserved.
//

#include "Lexico.hpp"

void Lexico::leer(string cadena){
    int i;
    
    for (i = 0; i < cadena.size(); i++){
        //Envía cada caracter al método Automata.
        c = cadena[i];
        
//        cout<<"c: "<<c<<" // i:"<<i<<endl;
        Automata(c,true);
    }
    
    if(i==cadena.size()){
        //se ha leído toda la cadena
//        cout<<"fin de cadena, metodo leer"<<endl;
        Automata(c, false);
        
//        if(c!=' '){
////            cout<<"esto fue lo ultimo guardado: "<<c<<endl;
//        }
    }
}

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
    Tipos t;
    //    setCadena(cadena);
//    cout<<"metodo automata"<<endl;
    while (final) {
        //        c = sigCaracter();
        //        c == leer();
//        cout<<"WHILE"<<endl;
        switch (estado) {
            case 0: //NÚMERICO edo 0
//                cout<<"estado 0 "<<endl;
                if(isdigit(c)){
                    estado = 1;
                    tipo = 1;
                    break;
                    
                }else{
                    estado = 4;
                }
                // else NO ES DIGITO
                //final = false;
            case 1: //NÚMERICO edo 1
//                cout<<"estado 1 "<<endl;
                if(isdigit(c)){
                    estado = 1;
                    tipo = 1;
                    break;
                }else{
                    estado = 4;
                }
                break;
            case 2: // REAL edo 2
//                cout<<"estado 2"<<endl;
                if(c=='.'){
                    estado = 3;
                    tipo = 2;
//                    cout<<"this is a point"<<endl;
                    break;
                }else{
                    estado = 4;
                }
            case 3: // STAND BY
//                cout<<"estado 3"<<endl;
                //                break;
                
            case 4: //OPERADORES
//                cout<<"estado 4"<<endl;
                if(operadores(c)!=-1){
                    final = false;
                    break;
                }else{
                    estado = 5;
                }
                break;
                
            case 5:
//                cout<<"Estado 5"<<endl;
                if(c==';'){
                    final = false;
                    cout<<c<<"\t * Es punto y coma *"<<endl;
                    break;
                }else{
                    estado = 6;
                }
                break;
                
            case 6:
                if(c==','){
                    final = false;
                    cout<<c<<"\t * Es coma *"<<endl;
                    break;
                }else{
                    estado = 7;
                }
                break;
            case 7:
                if(c=='('){
                    final = false;
                    cout<<c<<"\t * Es inicio parentésis *"<<endl;
                    break;
                }else{
                    estado = 8;
                }
                break;
            case 8:
                if(c==')'){
                    final = false;
                    cout<<c<<"\t * Es final parentésis *"<<endl;
                    break;
                }else{
                    estado = 9;
                }
                break;
            case 9:
                if(c=='{'){
                    final = false;
                    cout<<c<<"\t * Es corchete *"<<endl;
                    break;
                }else{
                    estado = 10;
                }
                break;
            case 10:
                if(c=='}'){
                    final = false;
                    cout<<c<<"\t * Es corchete *"<<endl;
                    break;
                }else{
                    estado = 10;
                }
                break;
            case 11:
                if(c=='='){
                    final = false;
                    cout<<c<<"\t * Es simbolo de igual *"<<endl;
                    break;
                }else{
                    estado = 0;
                }
                break;
                
            default:
                break;
        }
    }
}

int Lexico::operadores(char c){
    //for (int i = 0; i < Operador; i++) {
//    cout<<"metodo operadores"<<endl;
//    cout<<"c: "<<c<<endl;
    switch (c) {
        case '+':
            cout<<c<<"\t * Es operador suma * "<<endl;
            return tipoOperador = 5;
            break;
            
        case '-':
            cout<<c<<"\t * Es operador resta * "<<endl;
            return tipoOperador = 5;
            break;
            
        case '*':
            cout<<c<<"\t * Es operador multiplicación * "<<endl;
            return tipoOperador = 6;
            break;
            
        case '/':
            cout<<c<<"\t * Es operador división * "<<endl;
            return tipoOperador = 6;
            break;
            
        case '<':
            cout<<c<<"\t * Es operador relacional menor que * "<<endl;
            return tipoOperador = 7;
            break;
            
        case '>':
            cout<<c<<"\t * Es operador relacional mayor que * "<<endl;
            return tipoOperador = 7;
            break;
            
        case '!':
            cout<<c<<"\t * Es operador Not * "<<endl;
            return tipoOperador = 10;
            break;
            
        default:
            break;
    }
    
    return tipoOperador = -1;
}



bool Lexico::esTipo(int tipo){
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
            cout<<" Tipo de dato: Default "<<endl;
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
