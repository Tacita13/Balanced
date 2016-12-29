//Client file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 7                         Prof. R. J. Colorado
//   Archivo     : balanced.cpp           Fecha : 4/11/16
//
//******************************************************************
//    Propósito :This file contains the client file for a program
//    that checks if there is a balanced number of parenthesis.
//
//******************************************************************

#include <iostream>
#include "stack.h"
using namespace std;

//prototypes
bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, char openSymbol);

int main(){
    char symbol;
    stack<int> stack;
    bool balanced = true;
    char openSymbol;


    cout<< "Enter an expression and press return."<< endl;
    cin.get(symbol);
    while(symbol != '\n' && balanced){
        if(isOpen(symbol)){
            stack.push(symbol);
        }
        else if(isClosed(symbol)){
            if(stack.empty()){
                balanced = false;
            }
            else{
                openSymbol = stack.top();
                stack.pop();
                balanced = matches(symbol, openSymbol);
            }
        }
        cin.get(symbol);
    }
    //uses the designated functions to check if the expression
    //entered has a balanced number of parenthesis.
    if(balanced && stack.empty()){
        cout<<"Expression is well formed.\n";
    }
    else{
        cout<<"Expression is not well formed.\n";
    }

    return 0;
}

//checks for open parenthesis
bool isOpen(char symbol){
    if((symbol == '(') || (symbol == '{') || (symbol == '[')){
        return true;
    }
    else{
        return false;
    }
}

//checks for closed parenthesis
bool isClosed(char symbol){
    if((symbol == ')') || (symbol == '}') || (symbol == ']')){
        return true;
    }
    else{
        return false;
    }
}

//matches with the three type of parenthesis (), {}, []
bool matches(char symbol, char openSymbol){

    return (((openSymbol == '(') && symbol == ')')
          || ((openSymbol == '{') && symbol == '}')
          || ((openSymbol == '[') && symbol == ']'));
}






























