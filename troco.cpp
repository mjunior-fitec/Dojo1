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

enum {
    MOEDA_50,
    MOEDA_10,
    MOEDA_5,
    MOEDA_1,
    MAX_MOEDAS
};

int cedulas[MAX_CEDULAS];
int moedas[MAX_MOEDAS];
double valorCedulas[MAX_CEDULAS] = {100, 50, 10, 5, 1};
double valorMoedas[MAX_MOEDAS] = {0.50, 0.10, 0.5, 0.1};

int calculaQuantidadePorTipo(double valorTotal, double valor)
{
    int quant = 0;
    
    // Calcula quantidades
    if(valorTotal > valor) {
        
        quant = (int) valorTotal / valor;
    }
    
    return quant;
}


// Calcula numro de cedulas para o troco
//
void getNumCedulas(double troco)
{
    int numCedulas = 0;
    double valorParcial = troco;
    
    for (int i=0;i<MAX_CEDULAS;i++){
        // Calcula numero de itens (cedulas ou moedas)
        cedulas[i] = calculaQuantidadePorTipo(valorParcial, valorCedulas[i]);
        // Caclula troco restante
        valorParcial -= (cedulas[i] * valorCedulas[i]);
    }
}


void getNumMoedas(double troco)
{
    int numMoedas = 0;
    double valorParcial = troco;
    
    for (int i=0;i<MAX_MOEDAS;i++){
        // Calcula numero de itens (cedulas ou moedas)
        moedas[i] = calculaQuantidadePorTipo(valorParcial, valorMoedas[i]);
        // Caclula troco restante
        valorParcial -= (moedas[i] * valorMoedas[i]);
    }
}


int main()
{
    printf("Hello World");

    return 0;
}
