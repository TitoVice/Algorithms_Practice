/** @file CandidatUnic.h
    @brief Classe CandidatUnic
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef CANDIDATUNIC_H
#define CANDIDATUNIC_H
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class CandidatUnic
    @brief Gestiona el candidat del backtracking d'una opció
    @author Vicenç Verge
    @date 10/1/2019
*/

class CandidatUnic
{
    public:
        CandidatUnic();
        /**<
        @brief Crea un CandidatUnic buit
        @pre Cert
        @post Constructor buit
        */

        CandidatUnic(int n);
        /**<
        @brief Crea un CandidatUnic amb paràmetres
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

#endif // CANDIDATUNIC_H
