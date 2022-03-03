/** @file Processos.h
    @brief Classe Processos
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef PROCESSOS_H
#define PROCESSOS_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"

using namespace std;

/** @class Processos
    @brief Fa la lectura del fitxer i acciona els procediments
    @author Vicenç Verge
    @date 10/1/2019
*/

class Processos
{
    public:
        Processos();
        /**<
        @brief Crea un Processos buit
        @pre Cert
        @post Constructor buit
        */

        Processos(const char *nomFitxer);
        /**<
        @brief Crea un Processos llegint les dades del fitxer
        @pre Cert
        @post Constructor per paràmetres
        */

        void backtrackingMillor();
        /**<
        @brief Fa el backtracking amb millor solució
        @pre Cert
        @post Fa el backtracking buscant la millor solucio, si no en troba una ho diu per pantalla
        */

        void backtrackingUnic(const int &minim);
        /**<
        @brief Fa el backtracking amb una solució
        @pre Cert
        @post Fa el backtracking buscant una solucio, si no en troba una ho diu per pantalla
        */

        void algoritmeVorac();
        /**<
        @brief Fa un algoritme voraç per trobar una solucio
        @pre Cert
        @post Fa l'algoritme voraç per trobar una solucio, si  no en troba una dona un missatge
        */

    private:
        int minimPreferencia; ///< Guarda el valor mínim de la preferència que es demana pel backtracking d'una solució
        vector<Alumne> _vAlumnes; ///< Vector que guarda els alumnes
        vector<Tutor> _vTutors; ///< Vector que gurada els Tutors
        double desafinacioMin; ///< Guarda el valor mínim de desafinació per a utilitzar-lo en el backtracking de millor solució

        void mostrarResVorac(const map<Tutor, vector<Alumne>> &res, double suma);
        /**<
        @brief Mostra per pantalla el resultat
        @pre Cert
        @post Mostra el resultat, si n'hi ha, de l'algoritme voraç
        */
};

#endif // PROCESSOS_H
