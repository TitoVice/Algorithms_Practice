/** @file Alumne.h
    @brief Classe Alumne
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef ALUMNE_H
#define ALUMNE_H
#include <string>
#include <vector>
#include "Tutor.h"

using namespace std;

/** @class Alumne
    @brief Gestiona la informaci� de l'alumne
    @author Vicen� Verge
    @date 10/1/2019
*/

class Alumne
{
    public:
        Alumne();
        /**<
        @brief Crea un Alumne buit
        @pre Cert
        @post Constructor buit
        */

        Alumne(string nom, string cognom, double desafinacio);
        /**<
        @brief Crea un Alumne amb par�metres
        @pre Cert
        @post Constructor amb par�metres
        */

        void inserirPreferencia(const vector<Tutor> &preferencies);
        /**<
        @brief Copia el vector de prefer�ncies que se li passa
        @pre Cert
        @post Copia el vector de tutors a _preferencies
        */

        int donarPreferencia(const Tutor &tActual) const;
        /**<
        @brief Retorna la prefer�ncia demanada
        @pre Cert
        @post Retorna la preferencia del professor que es dona, si no existeix retorna -1
        */

        Tutor donarMaxPreferencia(int n) const;
        /**<
        @brief Retorna el tutor amb la prefer�ncia m�xima
        @pre Cert
        @post Retorna el tutor amb maxima preferencia
        */

        string getNom() const;
        /**<
        @brief Retorna el nom de l'alumne
        @pre Cert
        @post Getter de _nom
        */

        string getCognom() const;
        /**<
        @brief Retorna el cognom de l'alumne
        @pre Cert
        @post Getter de _cognom
        */

        double getDesafinacio() const;
        /**<
        @brief Retorna la desafinaci� de l'alumne
        @pre Cert
        @post Getter de _desafinacio
        */

        bool operator<(Alumne const &n) const;
        /**<
        @brief Operador < de la classe
        @pre Cert
        @post Operador menor que
        */

    private:
        double _desafinacio; ///< Valor que guarda la desafinaci� de l'alumne va de 0.0 a 1.0
        string _nom, _cognom; ///< Valors que guarden el nom i el cognom de l'alumne, respectivament
        vector<Tutor> _preferencies; ///< Vector que guarda les prefer�ncies que t� l'alumne cap a cada professor, ordenat de petit a gran segons la prefer�ncia
};

#endif // ALUMNE_H
