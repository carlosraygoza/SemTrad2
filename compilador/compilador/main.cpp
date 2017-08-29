//
//  main.cpp
//  compilador
//
//  Created by Carlos Raygoza on 27/08/17.
//  Copyright © 2017 Carlos Raygoza. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string>

#include "Lexico.hpp"

using namespace std;

int main(){
    
    
    Lexico lexico;
//    lexico.setCadena("+12.3a");
    lexico.leer("+-*/<>;,(){}=");
    
//    cout << "Resultado del Analisis Lexico" << endl << endl;
//    cout << "Simbolo\t\tTipo" << endl;
//
//    cin.get();

    
 
    
    return 0;
}
