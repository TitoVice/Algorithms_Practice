/** @file Processos.h
    @brief Classe Processos
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

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
    @author Vicen� Verge
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
        @post Constructor per par�metres
        */

        void backtrackingMillor();
        /**<
        @brief Fa el backtracking amb millor soluci�
        @pre Cert
        @post Fa el backtracking buscant la millor solucio, si no en troba una ho diu per pantalla
        */

        void backtrackingUnic(const int &minim);
        /**<
        @brief Fa el backtracking amb una soluci�
        @pre Cert
        @post Fa el backtracking buscant una solucio, si no en troba una ho diu per pantalla
        */

        void algoritmeVorac();
        /**<
        @brief Fa un algoritme vora� per trobar una solucio
        @pre Cert
        @post Fa l'algoritme vora� per trobar una solucio, si  no en troba una dona un missatge
        */

    private:
        int minimPreferencia; ///< Guarda el valor m�nim de la prefer�ncia que es demana pel backtracking d'una soluci�
        vector<Alumne> _vAlumnes; ///< Vector que guarda els alumnes
        vector<Tutor> _vTutors; ///< Vector que gurada els Tutors
        double desafinacioMin; ///< Guarda el valor m�nim de desafinaci� per a utilitzar-lo en el backtracking de millor soluci�

        void mostrarResVorac(const map<Tutor, vector<Alumne>> &res, double suma);
        /**<
        @brief Mostra per pantalla el resultat
        @pre Cert
        @post Mostra el resultat, si n'hi ha, de l'algoritme vora�
        */
};

#endif // PROCESSOS_H
