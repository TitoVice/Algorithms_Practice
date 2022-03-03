/** @file SolucionadorMillor.h
    @brief Classe SolucionadorMillor
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef SOLUCIONADORMILLOR_H
#define SOLUCIONADORMILLOR_H
#include "SolucioMillor.h"
#include "CandidatMillor.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class SolucionadorMillor
    @brief Gestiona el solucionador del backtracking de la millor soluci�
    @author Vicen� Verge
    @date 10/1/2019
*/

class SolucionadorMillor
{
    public:
        SolucionadorMillor();
        /**<
        @brief Crea un SolucionadorMillor buit
        @pre Cert
        @post Constructor buit
        */

        bool solucionar(const SolucioMillor &inicial);
        /**<
        @brief Diu si s'ha trobat una soluci� o no
        @pre Cert
        @post Retorna cert si ha trobat una soluci�, fals altrament
        */

        SolucioMillor retornarSolucio() const;
        /**<
        @brief Dona la soluci�
        @pre Cert
        @post Getter de millor
        */

    private:
        SolucioMillor millor, actual; ///< Solucions les quals millor guarda la solucio m�s optima i actual guarda la soluci� actual
        bool teSolucio; ///< Cert si s'ha trobat una soluci�, fals altrament

        void trobarMillorSolucio();
        /**<
        @brief Busca la millor soluci� a partir de backtracking
        @pre Cert
        @post Fa el backtracking per trobar la millor solucio
        */
};

#endif // SOLUCIONADORMILLOR_H
