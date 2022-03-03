/** @file main.cpp
    @brief Main
*/

// Vicenç Verge Mondéjar
// Usuari u1954010
// Pràctica 2

#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include "Processos.h"
#include "myexception.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;


/** @class Processos
    @brief Fa la lectura del fitxer i acciona els procediments
    @author Vicenç Verge
    @date 10/1/2019
*/


/**
    @brief Mostra l'ajuda per entrar comandes
    @pre Cert
    @post Mostra per pantalla
*/
void mostrarHelp(char *nom){
//Pre: --
//Post: mostra per pantalla

    cout<<"Utilització: "<<nom<<" [--help, -h, -u x, -m, -g] fitxer"<<endl<<endl
        <<"-h, --help: mostra aquest missatge d'ajuda i surt"<<endl
        <<"-u x:       cerca i mostra, si la troba, una solucio on la preferència mínima és x"<<endl
        <<"-m:         mostra una assignació que maximitza el grau global de preferències"<<endl
        <<"-g:         utilitza una estrategia vorac (greedy)"<<endl<<endl
        <<"el fitxer ha de ser un fitxer de text amb aquesta estructura:"<<endl
        <<"3"<<endl
        <<"Pere Recasens 0.25 2"<<endl
        <<"Ines Feliu 0.25 1"<<endl
        <<"Mireia Peracuala 0.75 2"<<endl
        <<"4"<<endl
        <<"Xavier Martinez 0.10"<<endl
        <<"Andrea Iverna 0.25"<<endl
        <<"Lluis Esteve 0.50"<<endl
        <<"Yero Baleh 0.75"<<endl
        <<"3 2 1"<<endl
        <<"1 2 3"<<endl
        <<"3 2 1"<<endl
        <<"3 1 2"<<endl;
}

/**
    @brief Ens diu si el que se li passa és (--help)
    @pre Cert
    @post Retorna cert si nom == "--help", fals altrament
*/
bool esHelp(char *nom){
//Pre: --
//Post: retorna cert si nom == --help

    string opcio(nom);
    return opcio == "--help";
}

/**
    @brief Int main()
    @pre Cert
    @post Part principal del programa
*/
int main(int argn, char **argv){
#ifdef _WIN32
SetConsoleOutputCP( CP_UTF8 );
SetConsoleCP( CP_UTF8 );
#endif
using namespace std::chrono;

    try{
        //if (argn < 2 or argn > 3)
        if(argn == 1){
            cout<<"Falten arguments (./tfg --help per ajuda)"<<endl;
            return 0;
        }
        else if(argn == 2 and ((argv[1][0] == '-' and argv[1][1] == 'h') or esHelp(argv[1]))){
            cout<<"*** ASSIGNADOR DE TUTORS TFG ***"<<endl;
            mostrarHelp(argv[0]);
            return(0);
        }
        else if(argn == 2){
            if(argv[1][0] == '-' and (argv[1][1] == 'm' or argv[1][1] == 'g' or argv[1][1] == 'u')){
                if(argv[1][1] == 'u'){
                        cout<<"A la comanda: "<<argv[1]<<", li falta la preferència mínima (x) i el fitxer"<<endl;
                        return 0;
                }
                else{
                    cout<<"A la comanda: "<<argv[1]<<", li falta el fitxer"<<endl;
                    return 0;
                }
            }
            else{
                cout<<"La comanda: "<<argv[1]<<", és desconeguda"<<endl;
                return 0;
            }
        }
        else if(argn == 3){
            if(argv[1][0] == '-' and argv[1][1] == 'm'){
                string fitxer(argv[2]);
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                Processos dades(fitxer.c_str());
                dades.backtrackingMillor();
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
                cout<<"Temps: "<<time_span.count()<<" segons"<<endl;
            }
            else if(argv[1][0] == '-' and argv[1][1] == 'g'){
                string fitxer(argv[2]);
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                Processos dades(fitxer.c_str());
                dades.algoritmeVorac();
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
                cout<<"Temps: "<<time_span.count()<<" segons"<<endl;
            }
            else if(argv[1][0] == '-' and argv[1][1] == 'u'){
                if(argv[2][0] >= '1' and argv[2][0] <= '9'){
                    cout<<"A la comanda: "<<argv[1]<<", li falta el fitxer"<<endl;
                    return 0;
                }
                else{
                    cout<<"A la comanda: "<<argv[1]<<", li falta la preferència mínima (x)"<<endl;
                    return 0;
                }
            }
            else{
                cout<<"La comanda: "<<argv[1]<<", és desconeguda"<<endl;
                return 0;
            }
        }
        else if(argn == 4){
            if(argv[1][0] == '-' and argv[1][1] == 'u'){
                if(argv[2][0] >= '1' and argv[2][0] <= '9'){
                    int minim = atoi(argv[2]);
                    string fitxer(argv[3]);
                    high_resolution_clock::time_point t1 = high_resolution_clock::now();
                    Processos dades(fitxer.c_str());
                    dades.backtrackingUnic(minim);
                    high_resolution_clock::time_point t2 = high_resolution_clock::now();
                    duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
                    cout<<"Temps: "<<time_span.count()<<" segons"<<endl;
                }
                else{
                    cout<<"La comanda: "<<argv[1]<<", no està ben implementada. La x no és un enter"<<endl;
                    return 0;
                }
            }
            else{
                cout<<"La comanda: "<<argv[1]<<", és desconeguda"<<endl;
                return 0;
            }
        }
        else{
            cout<<"Sobren arguments (./tfg --help per ajuda)"<<endl;
            return 0;
        }
    }
    catch (myexception e){
      cerr<<e.what()<<endl;
    }

    return 0;
}
