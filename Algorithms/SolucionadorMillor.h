/** @file SolucionadorMillor.h
    @brief Classe SolucionadorMillor
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef SOLUCIONADORMILLOR_H
#define SOLUCIONADORMILLOR_H
#include "SolucioMillor.h"
#include "CandidatMillor.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class SolucionadorMillor
    @brief Gestiona el solucionador del backtracking de la millor solució
    @author Vicenç Verge
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
        @brief Diu si s'ha trobat una solució o no
        @pre Cert
        @post Retorna cert si ha trobat una solució, fals altrament
        */

        SolucioMillor retornarSolucio() const;
        /**<
        @brief Dona la solució
        @pre Cert
        @post Getter de millor
        */

    private:
        SolucioMillor millor, actual; ///< Solucions les quals millor guarda la solucio més optima i actual guarda la solució actual
        bool teSolucio; ///< Cert si s'ha trobat una solució, fals altrament

        void trobarMillorSolucio();
        /**<
        @brief Busca la millor solució a partir de backtracking
        @pre Cert
        @post Fa el backtracking per trobar la millor solucio
        */
};

#endif // SOLUCIONADORMILLOR_H
