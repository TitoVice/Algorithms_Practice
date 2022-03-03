/** @file Tutor.h
    @brief Classe Tutor
*/

// Vicen� Verge Mond�jar
// Usuari u1954010
// Pr�ctica 2

#ifndef TUTOR_H
#define TUTOR_H
#include <iostream>
#include <string>

using namespace std;

/** @class Tutor
    @brief Gestiona la informaci� del tutor
    @author Vicen� Verge
    @date 10/1/2019
*/

class Tutor
{
    public:
        Tutor();
        /**<
        @brief Crea un Tutor buit
        @pre Cert
        @post Constructor buit
        */

        Tutor(string nom, string cognom, double desafinacio, int maxAlum);
        /**<
        @brief Crea un Tutor amb par�metres
        @pre Cert
        @post Constructor amb par�metres
        */

        void sumaAlumne();
        /**<
        @brief Augmenta el n�mero d'alumnes als que fa tutoria
        @pre Cert
        @post Augmenta en un _qAlumnes
        */

        void restaAlumne();
        /**<
        @brief Decrementa el n�mero d'alumnes als que fa tutoria
        @pre Cert
        @post Decrementa en un _qAlumnes
        */

        void mostrarTutor() const;
        /**<
        @brief Mostra el nom i cognom del tutor
        @pre Cert
        @post Mostra el _nom i _cognom
        */

        int getMaxAl() const;
        /**<
        @brief Retorna el m�xim d'alumnes del tutor
        @pre Cert
        @post Getter de _maxAl
        */

        int getQAlumnes() const;
        /**<
        @brief Retorna la quantitat d'alumnes que tutoritza el tutor
        @pre Cert
        @post Getter de _qAlumnes
        */

        double getMaxDes() const;
        /**<
        @brief Retorna el m�xim de desafinaci� del tutor
        @pre Cert
        @post Getter de _maxDes
        */

        bool operator==(Tutor const &n) const;
        /**<
        @brief Operador == de la classe
        @pre Cert
        @post Operador igual que
        */

        bool operator<(Tutor const &n) const;
        /**<
        @brief Operador < de la classe
        @pre Cert
        @post Operador menor que
        */

    private:
        int _maxAl, _qAlumnes; ///< Valors que guarden  el m�xim d'alumnes que pot tutoritzar i la quantitat d'alumnes que tutoritza el tutor
        double _maxDes; ///< Valor que guarda el m�xim de desafinaci� que permet el tutor
        string _nom, _cognom; ///< Valors que guarden el nom i el cognom del tutor, respectivament
};

#endif // TUTOR_H
