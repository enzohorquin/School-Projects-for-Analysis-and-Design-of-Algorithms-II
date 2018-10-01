#ifndef LISTA_H
#define LISTA_H
#include <string>
#include "Libro.h"
using namespace std;
template<typename Elem>
class Lista
{
    public:
        Lista();
        void   AgregarElementos( int pos, Elem valor);
        void Imprimir();
        virtual ~Lista();
        int longlista() const ;

        Elem elemento();
        void reset();
        bool final();
        void avanzar();
        void VaciaLista();
        void AgregaElementosPrincipio(Elem valor);
        void AgregaElementosFinal( Elem valor);
        bool PerteneceElemento( Elem valor);
         bool ListaVacia() const ;
   void EliminaElemento(Elem elemento);
    protected:
    private:
       struct Nodo { Nodo* SigLista;
                Elem valor;};
        Nodo * ListaElementos;
        Nodo * cursor;

        int l;  // variable que guarda el valor de la longitud de  la lista
        void AgregaElem(Nodo * & Lista, int pos, Elem valor, int cont);
        void Print(Nodo * Lista);
        void AgregaElemFinal( Nodo * & Lista, Elem valor);
        bool PerteneceElem( Nodo * & Lista, Elem valor );
       void  EliminaElementoLista ( Nodo * & Lista, Elem elemento);
        void Elimina(Nodo * & Lista);

};

#endif // LISTA_H
