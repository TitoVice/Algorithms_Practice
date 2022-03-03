/** @file SolucioUnic.h
    @brief Classe SolucioUnic
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef SOLUCIOUNIC_H
#define SOLUCIOUNIC_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "myexception.h"
#include "Tutor.h"
#include "Alumne.h"
#include "CandidatUnic.h"

using namespace std;

/** @class SolucioUnic
    @brief Gestiona la soluci� del backtracking d'una soluci�
    @author Vicen� Verge
    @date 10/1/2019
*/

class SolucioUnic
{
    public:
        SolucioUnic();
        /**<
        @brief Crea un SolucioUnic buit
        @pre Cert
        @post Constructor buit
        */

        SolucioUnic(int minim, vector<Alumne> Al, vector<Tutor> Tut);
        /**<
        @brief Crea un SolucioUnic llegint les dades del fitxer
        @pre Cert
        @post Constructor per par�metres
        */

        CandidatUnic inicialitzarCandidats() const;
        /**<
        @brief Inicialitza el candidat
        @pre Cert
        @post Retorna CandidatUnic
        */

        bool acceptable(const CandidatUnic &iCan) const;
        /**<
        @brief Diu si el candidat �s acceptable
        @pre Cert
        @post Retorna cert si iCan es acceptable, fals altrament
        */

        void anotar(const CandidatUnic &iCan);
        /**<
        @brief Anota el candidat a la soluci�
        @pre Cert
        @post Anota el candidat a _res
        */

        void desanotar(const CandidatUnic &iCan);
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
        double _sumaPreferencia; ///< Valor que guarda la suma de prefer�ncia*afinaci�
        int nivell, _minimPreferencia; ///< Valors que guarden el alumne el qual hem d'usar i el m�nim de prefer�ncia perm�s
};

#endif // SOLUCIOUNIC_H
