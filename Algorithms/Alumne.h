/** @file Alumne.h
    @brief Classe Alumne
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef ALUMNE_H
#define ALUMNE_H
#include <string>
#include <vector>
#include "Tutor.h"

using namespace std;

/** @class Alumne
    @brief Gestiona la informació de l'alumne
    @author Vicenç Verge
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
        @brief Crea un Alumne amb paràmetres
        @pre Cert
        @post Constructor amb paràmetres
        */

        void inserirPreferencia(const vector<Tutor> &preferencies);
        /**<
        @brief Copia el vector de preferències que se li passa
        @pre Cert
        @post Copia el vector de tutors a _preferencies
        */

        int donarPreferencia(const Tutor &tActual) const;
        /**<
        @brief Retorna la preferència demanada
        @pre Cert
        @post Retorna la preferencia del professor que es dona, si no existeix retorna -1
        */

        Tutor donarMaxPreferencia(int n) const;
        /**<
        @brief Retorna el tutor amb la preferència màxima
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
        @brief Retorna la desafinació de l'alumne
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
        double _desafinacio; ///< Valor que guarda la desafinació de l'alumne va de 0.0 a 1.0
        string _nom, _cognom; ///< Valors que guarden el nom i el cognom de l'alumne, respectivament
        vector<Tutor> _preferencies; ///< Vector que guarda les preferències que té l'alumne cap a cada professor, ordenat de petit a gran segons la preferència
};

#endif // ALUMNE_H
