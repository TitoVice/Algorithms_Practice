#include "Processos.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"
#include "SolucionadorMillor.h"
#include "SolucionadorUnic.h"
#include "SolucioMillor.h"
#include "SolucioUnic.h"

using namespace std;

Processos::Processos(){

    desafinacioMin = 1.0;
    minimPreferencia = 1;
}

Processos::Processos(const char *nomFitxer){

    int qTutors, qAlum, maxAlum, preferencia;
    string nom, cognom;
    double desafinacio;
    desafinacioMin = 2.0;

	ifstream f_ent(nomFitxer);
    if (f_ent.fail()) throw myexception("Fitxer no trobat.");
    else{
        f_ent>>qTutors;
        for(int i = 0; i < qTutors; i++){
            f_ent>>nom>>cognom>>desafinacio>>maxAlum;
            Tutor _tutor(nom, cognom, desafinacio, maxAlum);
            _vTutors.push_back(_tutor);
        }

        f_ent>>qAlum;
        for(int j = 0; j < qAlum; j++){
            f_ent>>nom>>cognom>>desafinacio;
            if(desafinacio < desafinacioMin) desafinacioMin = desafinacio;
            Alumne _alumne(nom, cognom, desafinacio);
            _vAlumnes.push_back(_alumne);
        }

        for(int x = 0; x < qAlum; x++){
            vector<Tutor> aux(qTutors + 1);
            for(int y = 0; y < qTutors; y++){
                f_ent>>preferencia;
                aux[preferencia] = _vTutors[y];
            }
            _vAlumnes[x].inserirPreferencia(aux);
        }
        f_ent.close();
        minimPreferencia = 1;
    }
}

void Processos::backtrackingMillor(){

    SolucioMillor sIni(_vAlumnes, _vTutors, desafinacioMin);
    SolucionadorMillor algBack;
    bool teSolucio = algBack.solucionar(sIni);

    if (teSolucio){
        SolucioMillor sol = algBack.retornarSolucio();
        sol.mostrar();
    }
    else cout << "L'algoritme no té solució" << endl;
}

void Processos::backtrackingUnic(const int &minim){

    minimPreferencia = minim;

    SolucioUnic sIni(minimPreferencia, _vAlumnes, _vTutors);
    SolucionadorUnic algBack;
    bool teSolucio = algBack.solucionar(sIni);

    if (teSolucio){
        SolucioUnic sol = algBack.retornarSolucio();
        sol.mostrar();
    }
    else cout << "L'algoritme no té solució" << endl;
}

void Processos::algoritmeVorac(){

    set<Alumne> sAlumnes;
    map<Tutor, vector<Alumne>> res;
    int preferencia = 1, posicio = 0;
    double suma = 0;

    for(int compt = 0; compt < static_cast<int>(_vAlumnes.size()); compt++){
        sAlumnes.insert(_vAlumnes[compt]);
    }
    set<Alumne>::iterator itS = sAlumnes.begin();

    while(itS != sAlumnes.end() and preferencia <= static_cast<int>(_vTutors.size())){
        Tutor Taux = itS->donarMaxPreferencia(preferencia);
        posicio = 0;
        vector<Tutor>::iterator itV = _vTutors.begin();
        bool acabat = false;
        while(itV != _vTutors.end() and !acabat){
            if(*itV == Taux) acabat = true;
            else{
                itV++;
                posicio++;
            }
        }

        if(Taux.getMaxDes() >= itS->getDesafinacio() and Taux.getMaxAl() > itV->getQAlumnes()){
            res[Taux].push_back(*itS);
            _vTutors[posicio].sumaAlumne();
            suma += (static_cast<int>(_vTutors.size()) + 1 - preferencia) * (1.0 - itS->getDesafinacio());
            preferencia = 1;
            itS++;
        }
        else preferencia++;
    }
    if(preferencia <= static_cast<int>(_vTutors.size())) mostrarResVorac(res, suma);
    else cout<<"L'algoritme no té solucio."<<endl;
}

void Processos::mostrarResVorac(const map<Tutor, vector<Alumne>> &res, double suma){

    map<Tutor, vector<Alumne>>::const_iterator itM = res.begin();

    while(itM != res.end()){
        itM->first.mostrarTutor();
        cout<<endl;
        vector<Alumne>::const_iterator itV = itM->second.begin();
        while(itV != itM->second.end()){
            cout<<"    "<<itV->getNom()<<" "<<itV->getCognom()<<" "<<1.0 - itV->getDesafinacio()<<" "<<itV->donarPreferencia(itM->first)<<endl;
            itV++;
        }
        itM++;
    }
    cout<<"Suma preferencia*afinacio: "<<suma<<endl;
}
