#include "SolucionadorUnic.h"
#include "SolucioUnic.h"
#include "CandidatUnic.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

SolucionadorUnic::SolucionadorUnic(){

    teSolucio = false;
}

bool SolucionadorUnic::solucionar(const SolucioUnic &inicial){

    teSolucio = false;
    solucio = inicial;
    trobarSolucio();

    return teSolucio;
}

SolucioUnic SolucionadorUnic::retornarSolucio() const{

    if (!teSolucio) throw myexception("No s'ha trobat una solució");

    return solucio;
}

void SolucionadorUnic::trobarSolucio(){

    CandidatUnic iCan = solucio.inicialitzarCandidats();

    while(!iCan.esFi() and !teSolucio){
        if(solucio.acceptable(iCan)){
            solucio.anotar(iCan);
            if(!solucio.completa()){
                trobarSolucio();
                if(!teSolucio) solucio.desanotar(iCan);
            }
            else teSolucio = true;
        }
        iCan.seguent();
    }
}
