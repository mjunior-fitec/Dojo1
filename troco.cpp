/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

enum {
    CEDULA_100,
    CEDULA_50,
    CEDULA_10,
    CEDULA_5,
    CEDULA_1,
    MAX_CEDULAS
};

int cedulas[MAX_CEDULAS];


// Calcula numro de cedulas para o tronco
//
int getNumCedulas(double troco)
{
    int numCedulas;
    double valorParcial = troco;
    
    // Calculo numero de cedulas de R$100
    if(valorParcial > 100) {
        
        numCedulas = (int) valorParcial / 100;
        cedulas[CEDULA_100] = numCedulas;
        
        // Caclula troco restante
        valorParcial -= (numCedulas * 100);
    } 
    
    // Calculo numero de cedulas de R$50
    if(valorParcial > 100) {
        
        numCedulas = (int) valorParcial / 100;
        cedulas[CEDULA_100] = numCedulas;
        
        // Caclula troco restante
        valorParcial -= (numCedulas * 100);
    } 
}
int main()
{
    printf("Hello World");

    return 0;
}
