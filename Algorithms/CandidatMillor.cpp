#include "CandidatMillor.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

CandidatMillor::CandidatMillor(){

    iCan = maxim = 0;
}

CandidatMillor::CandidatMillor(int n){

    iCan =  0;
    maxim = n;
}

int CandidatMillor::actual() const{

    if(esFi()) throw myexception("No hi ha més candidats");
    return iCan;
}

bool CandidatMillor::esFi() const{

    return iCan >= maxim;
}

void CandidatMillor::seguent(){

    if(esFi()) throw myexception("No hi ha més candidats");

    iCan++;
}
