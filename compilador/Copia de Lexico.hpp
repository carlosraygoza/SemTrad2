//
//  Lexico.hpp
//  compilador
//
//  Created by Carlos Raygoza
//  Copyright © 2017 Carlos Raygoza. All rights reserved.
//

#ifndef Lexico_hpp
#define Lexico_hpp

#include <stdio.h>
#include <iostream>

#define OPERADORES = 7; //13

using namespace std;
class Tipos{
public:
    static const int ERROR= -1;
    static const int IDENTIFICADOR= 0; // letra (letra|digito)*
    static const int ENTERO = 1; //0, 1, ... , 9
    static const int REAL = 2; // 0.10
    static const int CADENA = 3; 
    static const int TIPO = 4; //int, float, void
    static const int SUMA = 5; //+ -
    static const int MULTIP = 6; //* /
    static const int RELACIONAL = 7; // <, <=, >, >=
    static const int OR = 8; // ||
    static const int AND = 9; // &&
    static const int NOT = 10; // !
    static const int IGUALDAD = 11; // ==, !=
    static const int PUNTOCOMA = 12; // ;
    static const int COMA = 13; // ,
    static const int ABRE_PARENTESIS = 14; // (
    static const int CIERRA_PARENTESIS = 15; // )
    static const int ABRE_LLAVE = 16; // {
    static const int CIERRA_LLAVE = 17; // }
    static const int IGUAL = 18; // =
    static const int IF = 19;
    static const int WHILE = 20;
    static const int RETURN = 21;
    static const int ELSE = 22;
    static const int DINERO = 23; // $
};

class Lexico{
private:
    static const int Operador = 7;
    char token, c;
    string cadena;
    int tipoOperador;
    int tipoAnterior;
    bool final;
    void Automata(char c, bool final);
    bool esTipo(int tipo);
    int tipo;
    
    bool esLetra(char c);
    bool esEspacio(char c);
    char operadoresTipo[Operador] = {'+', '-', '*', '/', '<', '>','!'}; //, '>=', '||', '&&', '==', '!=', '<='};
    
    
public:
    int estado;
    void setCadena(string cad);
    string getCadena();
    void sigCaracter();
    int operadores(char c);
    
    void leer (string cadena);
    

    Lexico(){
        token = ' ';
        c = ' ';
        final = true;
        tipoAnterior = 0;
        tipo = 0;
        estado = 0;
    }
    
};

#endif /* Lexico_hpp */
