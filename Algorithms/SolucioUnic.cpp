#include "SolucioUnic.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"
#include "CandidatUnic.h"

using namespace std;

SolucioUnic::SolucioUnic(){

    _sumaPreferencia = 0.0;
    nivell = _minimPreferencia = 1;
}

SolucioUnic::SolucioUnic(int minim, vector<Alumne> Al, vector<Tutor> Tut){

    _alumnes = Al;
    _tutors = Tut;
    _usats.resize(_alumnes.size(), false);
    _sumaPreferencia = 0.0;
    nivell = 0;
    _minimPreferencia = minim;
}

CandidatUnic SolucioUnic::inicialitzarCandidats() const{

    return CandidatUnic(static_cast<int>(_tutors.size()));
}

bool SolucioUnic::acceptable(const CandidatUnic &iCan) const{

    if(_tutors[iCan.actual()].getMaxAl() > _tutors[iCan.actual()].getQAlumnes() and _alumnes[nivell].getDesafinacio() <= _tutors[iCan.actual()].getMaxDes() and
       _alumnes[nivell].donarPreferencia(_tutors[iCan.actual()]) >= _minimPreferencia and _usats[nivell] == false ) return true;
    else return false;
}

void SolucioUnic::anotar(const CandidatUnic &iCan){

    _sumaPreferencia += _alumnes[nivell].donarPreferencia(_tutors[iCan.actual()]) * (1.0 - _alumnes[nivell].getDesafinacio());
    _tutors[iCan.actual()].sumaAlumne();
    _usats[nivell] = true;
    _res[_tutors[iCan.actual()]].push_back(_alumnes[nivell]);
    nivell++;
}

void SolucioUnic::desanotar(const CandidatUnic &iCan){

    nivell--;
    _sumaPreferencia -= _alumnes[nivell].donarPreferencia(_tutors[iCan.actual()]) * (1.0 - _alumnes[nivell].getDesafinacio());
    _tutors[iCan.actual()].restaAlumne();
    _usats[nivell] = false;
    _res[_tutors[iCan.actual()]].pop_back();
}

bool SolucioUnic::completa() const{

    bool acabat = true;
    vector<bool>::const_iterator itV = _usats.begin();

    while(itV != _usats.end() and acabat){
        if(*itV == false) acabat = false;
        else itV++;
    }
    return acabat;
}

void SolucioUnic::mostrar() const{

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
