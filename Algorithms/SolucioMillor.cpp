#include "SolucioMillor.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"
#include "CandidatMillor.h"

using namespace std;

SolucioMillor::SolucioMillor(){

    _sumaPreferencia = desMinima = 0.0;
    nivell = nNoUsats = 1;
}

SolucioMillor::SolucioMillor(vector<Alumne> Al, vector<Tutor> Tut, double desafinacioMin){

    _alumnes = Al;
    _tutors = Tut;
    _usats.resize(_alumnes.size(), false);
    desMinima =  desafinacioMin;
    _sumaPreferencia = 0.0;
    nivell = 0;
    nNoUsats = _alumnes.size();
}

CandidatMillor SolucioMillor::inicialitzarCandidats() const{

    return CandidatMillor(static_cast<int>(_tutors.size()));
}

bool SolucioMillor::potSerMillor(const SolucioMillor &millor) const{

    if(_sumaPreferencia + ((_tutors.size() * (1.0 - desMinima)) * nNoUsats) > millor._sumaPreferencia) return true;
    else return false;
}

bool SolucioMillor::esMillor(const SolucioMillor &millor) const{

    if(_sumaPreferencia > millor._sumaPreferencia) return true;
    else return false;
}

bool SolucioMillor::acceptable(const CandidatMillor &iCan) const{

    if(_tutors[iCan.actual()].getMaxAl() > _tutors[iCan.actual()].getQAlumnes() and _alumnes[nivell].getDesafinacio() <= _tutors[iCan.actual()].getMaxDes() and
       _usats[nivell] == false and nivell < static_cast<int>(_alumnes.size())) return true;
    else return false;
}

void SolucioMillor::anotar(const CandidatMillor &iCan){

    _sumaPreferencia += _alumnes[nivell].donarPreferencia(_tutors[iCan.actual()]) * (1.0 - _alumnes[nivell].getDesafinacio());
    _tutors[iCan.actual()].sumaAlumne();
    _usats[nivell] = true;
    _res[_tutors[iCan.actual()]].push_back(_alumnes[nivell]);
    nNoUsats--;
    nivell++;
}

void SolucioMillor::desanotar(const CandidatMillor &iCan){

    nivell--;
    nNoUsats++;
    _sumaPreferencia -= _alumnes[nivell].donarPreferencia(_tutors[iCan.actual()]) * (1.0 - _alumnes[nivell].getDesafinacio());
    _tutors[iCan.actual()].restaAlumne();
    _usats[nivell] = false;
    _res[_tutors[iCan.actual()]].pop_back();
    if(_res[_tutors[iCan.actual()]].empty()) _res.erase(_tutors[iCan.actual()]);
}

bool SolucioMillor::completa() const{

    bool acabat = true;
    vector<bool>::const_iterator itV = _usats.begin();

    while(itV != _usats.end() and acabat){
        if(*itV == false) acabat = false;
        else itV++;
    }
    return acabat;
}

void SolucioMillor::mostrar() const{

    map<Tutor, vector<Alumne>>::const_iterator itM = _res.begin();

    while(itM != _res.end()){
        itM->first.mostrarTutor();
        cout<<endl;
        vector<Alumne>::const_iterator itV = itM->second.begin();
        while(itV != itM->second.end()){
            cout<<"    "<<itV->getNom()<<" "<<itV->getCognom()<<" "<<1.0 - itV->getDesafinacio()<<" "<<itV->donarPreferencia(itM->first)<<endl;
            itV++;
        }
        itM++;
    }
    cout<<"Suma preferencia*afinacio: "<<_sumaPreferencia<<endl;
}
