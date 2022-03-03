#include "Tutor.h"
#include <iostream>
#include <string>

using namespace std;

Tutor::Tutor(){

    _nom = _cognom = "";
    _maxAl = _qAlumnes = 0;
    _maxDes = 1.0;
}

Tutor::Tutor(string nom, string cognom, double desafinacio, int maxAlum){

    _nom = nom;
    _cognom = cognom;
    _maxAl = maxAlum;
    _maxDes = desafinacio;
    _qAlumnes = 0;
}

void Tutor::sumaAlumne(){

    _qAlumnes++;
}

void Tutor::restaAlumne(){

    _qAlumnes--;
}

void Tutor::mostrarTutor() const{

    cout<<_nom<<" "<<_cognom;
}

int Tutor::getMaxAl() const{

    return _maxAl;
}

int Tutor::getQAlumnes() const{

    return _qAlumnes;
}

double Tutor::getMaxDes() const{

    return _maxDes;
}

bool Tutor::operator==(Tutor const &n) const{

    if(_maxAl == n._maxAl and _maxDes == n._maxDes and _nom == n._nom and _cognom == n._cognom) return true;
    else return false;
}

bool Tutor::operator<(Tutor const &n) const{

    if(_maxAl < n._maxAl)
        return true;
    else if(_maxAl == n._maxAl)
        if(_maxDes < n._maxDes) return true;
        else return false;
    else return false;
}
