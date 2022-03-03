#include "SolucionadorMillor.h"
#include "SolucioMillor.h"
#include "CandidatMillor.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

SolucionadorMillor::SolucionadorMillor(){

    teSolucio = false;
}

bool SolucionadorMillor::solucionar(const SolucioMillor &inicial){

    teSolucio = false;
    millor = inicial;
    actual = inicial;

    trobarMillorSolucio();

    return teSolucio;
}

SolucioMillor SolucionadorMillor::retornarSolucio() const{

    if (!teSolucio) throw myexception("No s'ha trobat una solució");

    return millor;
}

void SolucionadorMillor::trobarMillorSolucio(){

    CandidatMillor iCan = actual.inicialitzarCandidats();

    while(!iCan.esFi()){
        if(actual.acceptable(iCan) and actual.potSerMillor(millor)){
            actual.anotar(iCan);
            if(!actual.completa()) trobarMillorSolucio();
            else if(actual.esMillor(millor)){
                millor = actual;
                teSolucio = true;
            }
            actual.desanotar(iCan);
        }
        iCan.seguent();
    }
}
