/** @file myexception.h
    @brief Classe myexception
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

/** @class myexception
    @brief Classe que fa saltar les excepcions.
    @author Vicenç Verge
    @date 10/1/2019
*/

class myexception: public exception {
private:
  string _message; ///< Valor que guarda el missatge
public:
  myexception(const string message);
  /**<
    @brief Constructor al que se li dona un string
    @pre Cert
    @post Constructor amb un string introduit;
   */

  virtual ~myexception() throw();
  /**<
    @brief Destructor
    @pre Cert
    @post Destructor
   */

  virtual const char* what() const throw();
  /**<
    @brief Treu per pantalla l'string
    @pre Cert
    @post Treu per pantalla l'string
  */
};

#endif // MYEXCEPTION_H
