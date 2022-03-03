#include "CandidatUnic.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

CandidatUnic::CandidatUnic(){

    iCan = maxim = 0;
}

CandidatUnic::CandidatUnic(int n){

    iCan =  0;
    maxim = n;
}

int CandidatUnic::actual() const{

    if(esFi()) throw myexception("No hi ha més candidats");
    return iCan;
}

bool CandidatUnic::esFi() const{

    return iCan >= maxim;
}

void CandidatUnic::seguent(){

    if(esFi()) throw myexception("No hi ha més candidats");

    iCan++;
}
