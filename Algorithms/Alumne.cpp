#include "Alumne.h"
#include <string>

using namespace std;

Alumne::Alumne(){

    _nom = _cognom = "";
    _desafinacio = 1.0;
}

Alumne::Alumne(string nom, string cognom, double desafinacio){

    _nom = nom;
    _cognom = cognom;
    _desafinacio = desafinacio;
}

void Alumne::inserirPreferencia(const vector<Tutor> &preferencies){

    _preferencies = preferencies;
}

int Alumne::donarPreferencia(const Tutor &tActual) const{

    int posicio = 0;
    bool trobat = false;
    vector<Tutor>::const_iterator itV = _preferencies.begin();

    while(itV != _preferencies.end() and !trobat){
        if(*itV == tActual) trobat = true;              //POTSER HE DE FER EL == A TUTORS
        else{
            itV++;
            posicio++;
        }
    }
    if(itV != _preferencies.end()) return posicio;
    else return -1;
}

Tutor Alumne::donarMaxPreferencia(int n) const{

    return _preferencies[_preferencies.size() - n];
}

string Alumne::getNom() const{

    return _nom;
}

string Alumne::getCognom() const{

    return _cognom;
}

double Alumne::getDesafinacio() const{

    return _desafinacio;
}

bool Alumne::operator<(Alumne const &n) const{

    if(_desafinacio < n._desafinacio) return true;
    else if(_desafinacio == n._desafinacio)
        if(_nom > n._nom) return true;
        else return false;
    else return false;
}
