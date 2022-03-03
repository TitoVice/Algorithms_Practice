/** @file CandidatMillor.h
    @brief Classe CandidatMillor
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef CANDIDATMILLOR_H
#define CANDIDATMILLOR_H
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class CandidatMillor
    @brief Gestiona el candidat del backtracking de la millor soluci�
    @author Vicen� Verge
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
        @brief Crea un CandidatMillor amb par�metres
        @pre Cert
        @post Constructor per par�metres
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
        @brief Passa al seg�ent candidat
        @pre Cert
        @post Avan�a en 1 el candidat
        */

    private:
        int iCan, maxim; ///< Valors que guarden el candidat actual i el valor m�xim d'aquest
};

#endif // CANDIDATMILLOR_H
