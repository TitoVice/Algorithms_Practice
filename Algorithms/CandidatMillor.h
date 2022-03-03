/** @file CandidatMillor.h
    @brief Classe CandidatMillor
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef CANDIDATMILLOR_H
#define CANDIDATMILLOR_H
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class CandidatMillor
    @brief Gestiona el candidat del backtracking de la millor solució
    @author Vicenç Verge
    @date 10/1/2019
*/

class CandidatMillor
{
    public:
        CandidatMillor();
        /**<
        @brief Crea un CandidatMillor buit
        @pre Cert
        @post Constructor buit
        */

        CandidatMillor(int n);
        /**<
        @brief Crea un CandidatMillor amb paràmetres
        @pre Cert
        @post Constructor per paràmetres
        */

        int actual() const;
        /**<
        @brief Retorna el candidat actual
        @pre Cert
        @post Retorna iCan
        */

        bool esFi() const;
        /**<
        @brief Diu si encara hi ha candidats o no
        @pre Cert
        @post Retorna cert si iCan > que maxim, fals altrament
        */

        void seguent();
        /**<
        @brief Passa al següent candidat
        @pre Cert
        @post Avança en 1 el candidat
        */

    private:
        int iCan, maxim; ///< Valors que guarden el candidat actual i el valor màxim d'aquest
};

#endif // CANDIDATMILLOR_H
