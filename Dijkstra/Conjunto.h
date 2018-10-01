#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "Lista.h"
#include "Lista.cpp"
#include"Libro.h"
using namespace std ;
template<typename Elem>
class Conjunto
{
    public:
        Conjunto();
        virtual ~Conjunto();
       void AgregaElementos(Elem valor);
        void Imprimir();
        int CantidadElementos() const ;
        bool PerteneceElemento( Elem valor);
         bool ConjuntoVacio() const ;
   Elem elemento () ;
   void reset();
        bool final();
        void avanzar();
    void VaciaConjunto();
   void EliminaElemento(Elem elemento);
void Union (   Conjunto<Elem> & C, Conjunto<Elem> &  Resultado );
void Interseccion (   Conjunto<Elem> &  C, Conjunto<Elem>  & Resultado);
void Diferencia(   Conjunto<Elem> &  C, Conjunto<Elem> &  Resultado );
    protected:
    private:
                Lista<Elem> ConjuntoElemento;

};
//antunezmatias@gmail.com
#endif // CONJUNTO_H
