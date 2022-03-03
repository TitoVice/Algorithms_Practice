/** @file SolucionadorUnic.h
    @brief Classe SolucionadorUnic
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef SOLUCIONADORUNIC_H
#define SOLUCIONADORUNIC_H
#include "SolucioUnic.h"
#include "CandidatUnic.h"
#include "myexception.h"
#include <iostream>
#include <string>

using namespace std;

/** @class SolucionadorUnic
    @brief Gestiona el solucionador del backtracking d'una solució
    @author Vicenç Verge
    @date 10/1/2019
*/

class SolucionadorUnic
{
    public:
        SolucionadorUnic();
        /**<
        @brief Crea un SolucionadorUnic buit
        @pre Cert
        @post Constructor buit
        */

        bool solucionar(const SolucioUnic &inicial);
        /**<
        @brief Diu si s'ha trobat una solució o no
        @pre Cert
        @post Retorna cert si ha trobat una solució, fals altrament
        */

        SolucioUnic retornarSolucio() const;
        /**<
        @brief Dona la solució
        @pre Cert
        @post Getter de solucio
        */

    private:
        SolucioUnic solucio; ///< Solucio que guarda la solució
        bool teSolucio; ///< Cert si s'ha trobat una solució, fals altrament

        void trobarSolucio();
        /**<
        @brief Busca una solució a partir de backtracking
        @pre Cert
        @post Fa el backtracking per trobar una solucio
        */
};

#endif // SOLUCIONADORUNIC_H
