/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <math.h>

double valorPago, valorDevido;

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
double valorMoedas[MAX_MOEDAS] = {0.50, 0.10, 0.05, 0.01};

int calculaQuantidadePorTipo(double valorTotal, double valor)
{
    double quant = 0;
    
    // Calcula quantidades
    if(valorTotal >= valor) {
        quant = valorTotal / valor;
    }
    return quant;
}


// Calcula numero de cedulas, salva no vetor e retorna a parte fracionaria restante
double getNumCedulas(double troco)
{
    double valorParcial = roundf(troco * 100) / 100;
    
    for (int i=0;i<MAX_CEDULAS;i++){
        // Calcula numero de itens (cedulas ou moedas)
        cedulas[i] = calculaQuantidadePorTipo(valorParcial, valorCedulas[i]);
        // Caclula troco restante
        valorParcial -= (cedulas[i] * valorCedulas[i]);
    }
    return valorParcial;
}

void testeGetNumCedulas(){
    double resposta = getNumCedulas(500);
    if(resposta == 0) std::cout << "Numero de Celulas OK" << std::endl;
    else std::cout << "Numero de Celulas ERRADO!!!!!!!" << std::endl;
}

// Calcula numero de moedas para o valor fracionario desejado
void getNumMoedas(double troco)
{
    double valorParcial = troco;
    
    for (int i=0;i<MAX_MOEDAS;i++){
        // Calcula numero de itens (cedulas ou moedas)
        moedas[i] = calculaQuantidadePorTipo(valorParcial, valorMoedas[i]);
        // Caclula troco restante
        valorParcial -= (moedas[i] * valorMoedas[i]);
    }
}

void lerDados()
{
    std::cout << "Entre com o valor pago: " << std::endl;
    std::cin >> valorPago;
    std::cout << "Entre com o valor devido: " << std::endl;
    std::cin >> valorDevido;
    
    if(valorPago < valorDevido || valorDevido < 0 || valorPago < 0) {
        std::cout << "Valores Invalidos " << std::endl;
    }
}

int main()
{
    double troco;
    double trocoParcial;
    
    lerDados();
    testeGetNumCedulas();
    // Calcula o troco
    troco = valorPago - valorDevido;
    
    // Calcula as cedulas do troco
    trocoParcial = getNumCedulas(troco);
    
    // Calcula as moedas do troco
    getNumMoedas(trocoParcial);
    
    if (troco > 0)
    {
        // Calcula as cedulas e moedas do troco
        
        std::cout << "O troco sera devolvido conforme abaixo:"  << std::endl;
        
        // Verifica se existe algum troco para tipo de cedulas
        for (int i = 0; i < MAX_CEDULAS; i++)
        {
            if (cedulas[i] > 0)
            {
                std::cout << cedulas[i] << "cedulas de R$" << valorCedulas[i] << std::endl;
            }
        }

        // Verifica se existe algum troco para tipo de moedas
        for (int i = 0; i < MAX_MOEDAS; i++)
        {
            if (moedas[i] > 0)
            {
                std::cout << moedas[i] << "moedas de R$" << valorMoedas[i] << std::endl;
            }
        }
    }
    

    return 0;
}
