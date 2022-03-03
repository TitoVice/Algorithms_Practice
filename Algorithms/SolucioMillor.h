/** @file SolucioMillor.h
    @brief Classe SolucioMillor
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef SOLUCIOMILLOR_H
#define SOLUCIOMILLOR_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"
#include "CandidatMillor.h"

using namespace std;

/** @class SolucioMillor
    @brief Gestiona la soluci� del backtracking de la millor soluci�
    @author Vicen� Verge
    @date 10/1/2019
*/

class SolucioMillor
{
    public:
        SolucioMillor();
        /**<
        @brief Crea un SolucioMillor buit
        @pre Cert
        @post Constructor buit
        */

        SolucioMillor(vector<Alumne> Al, vector<Tutor> Tut, double desafinacioMin);
        /**<
        @brief Crea un SolucioMillor llegint les dades del fitxer
        @pre Cert
        @post Constructor per par�metres
        */

        CandidatMillor inicialitzarCandidats() const;
        /**<
        @brief Inicialitza el candidat
        @pre Cert
        @post Retorna CandidatMillor
        */

        bool potSerMillor(const SolucioMillor &millor) const;
        /**<
        @brief Diu si la solucio pot ser millor que la soluci� <millor>
        @pre Cert
        @post Retorna cert si la solucio actual pot arribar a ser millor que la optima, fals altrament
        */

        bool esMillor(const SolucioMillor &millor) const;
        /**<
        @brief Diu si la solucio �s millor que la soluci� <millor>
        @pre Cert
        @post Retorna cert si la solucio actual es millor que la solucio optima, fals altrament
        */

        bool acceptable(const CandidatMillor &iCan) const;
        /**<
        @brief Diu si el candidat �s acceptable
        @pre Cert
        @post Retorna cert si iCan es acceptable, fals altrament
        */

        void anotar(const CandidatMillor &iCan);
        /**<
        @brief Anota el candidat a la soluci�
        @pre Cert
        @post Anota el candidat a _res
        */

        void desanotar(const CandidatMillor &iCan);
        /**<
        @brief Desanota el candidat de la soluci�
        @pre Cert
        @post Desanota el candidat de _res
        */

        bool completa() const;
        /**<
        @brief Diu si la soluci� est� completa
        @pre Cert
        @post Retorna cert si el bactracking est� complet, fals altrament
        */

        void mostrar() const;
        /**<
        @brief Mostra la soluci�
        @pre Cert
        @post Mostra _res
        */

    private:
        vector<Alumne> _alumnes; ///< Vector que guarda els alumnes
        vector<Tutor> _tutors; ///< Vector que guarda els tutors
        vector<bool> _usats; ///< Vector que ens diu quins alumnes han estat utilitzats i quins no
        map<Tutor, vector<Alumne>> _res; ///< Map que serveix per guardar el resultat
        double _sumaPreferencia, desMinima; ///< Valors que guarden la suma de prefer�ncia*afinaci� i la deafinaci� m�nima
        int nivell, nNoUsats; ///< Valors que guarden el alumne el qual hem d'usar i la quantitat d'alumnes que encara no s'han usat
};

#endif // SOLUCIOMILLOR_H
