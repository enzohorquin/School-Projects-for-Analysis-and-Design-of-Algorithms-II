#include "Conjunto.h"
#include <iostream>

using namespace std;
template <typename Elem>Conjunto<Elem>::Conjunto()
{
    //ctor
}

template <typename Elem>Conjunto<Elem>::~Conjunto()
{

}
template <typename Elem>int Conjunto<Elem> :: CantidadElementos() const
{

    return  ConjuntoElemento.longlista();               //Retorna la cantidad de elementos que tiene el conjunto
}
 template <typename Elem> void Conjunto<Elem> :: AgregaElementos( Elem valor)
{

       if (ConjuntoElemento.PerteneceElemento(valor)== false)
           ConjuntoElemento.AgregaElementosPrincipio(valor);        //Agrega Elementos al Conjunto



}
template <typename Elem> void Conjunto<Elem>::reset()
{
    ConjuntoElemento.reset();                   //resetea la iteracion
}
template <typename Elem> bool Conjunto<Elem>::final()
{
    return ConjuntoElemento.final();            //Pregunta si llego al final de la iteracion
}

 template <typename Elem> void Conjunto<Elem>::avanzar()
 {
     ConjuntoElemento.avanzar();                            //Avanza en la iteracion
 }
template <typename Elem> Elem Conjunto<Elem>::elemento()
{

    return ConjuntoElemento.elemento();                                         //Retorna el elemento en donde esta el cursor en la iteracion
}
template<typename Elem> bool Conjunto<Elem>:: ConjuntoVacio() const
{
    return ConjuntoElemento.ListaVacia();

}
template <typename Elem> bool Conjunto<Elem> ::  PerteneceElemento( Elem valor)
 {

     return ( ConjuntoElemento.PerteneceElemento(valor));   //retorna V si el elemento pertenece al conjunto y F si no pertenece

 }
 template <typename Elem> void Conjunto<Elem> :: EliminaElemento(Elem elemento)
{
   ConjuntoElemento.EliminaElemento(elemento);

}
template <typename Elem> void  Conjunto<Elem>:: Union (    Conjunto<Elem> &  C, Conjunto<Elem> &  Resultado)
{
C.reset();

while (!C.final())
{
    Resultado.AgregaElementos(C.elemento());
    C.avanzar();
}
ConjuntoElemento.reset();
while (!ConjuntoElemento.final())
{
      Resultado.AgregaElementos(ConjuntoElemento.elemento());
        ConjuntoElemento.avanzar();
}


C.reset();
ConjuntoElemento.reset();


Resultado.reset();


}
template <typename Elem> void  Conjunto<Elem>:: Diferencia (   Conjunto<Elem> & C, Conjunto<Elem> &  Resultado )
{




    ConjuntoElemento.reset();
    while (!ConjuntoElemento.final())
    {   if ( C.PerteneceElemento(ConjuntoElemento.elemento()) == false)
        {
            Resultado.AgregaElementos(ConjuntoElemento.elemento());
            ConjuntoElemento.avanzar();

        }

        else     ConjuntoElemento.avanzar();

    }


ConjuntoElemento.reset();


}
template<typename Elem> void Conjunto<Elem> :: VaciaConjunto()
{

    ConjuntoElemento.VaciaLista();



}
template <typename Elem> void  Conjunto<Elem>:: Interseccion (      Conjunto<Elem> &  C, Conjunto<Elem> &  Resultado )
{

    ConjuntoElemento.reset();
    while (!ConjuntoElemento.final())                                                   //Mientras que el ConjuntoElemento no termina, pregunta si el cada elemento
                                                                                        // del conjunto tambien pertenece al Conjunto C , si es asi, lo agrega al conjunto
    {
        Elem j= ConjuntoElemento.elemento();                                             // nuevo y avanza, sino avanza solamente
        if (C.PerteneceElemento(j))
           {
            Resultado.AgregaElementos(j);
            ConjuntoElemento.avanzar();}

        else
            ConjuntoElemento.avanzar();
    }
C.reset();
ConjuntoElemento.reset();

}
template <typename Elem>void Conjunto<Elem>:: Imprimir()
{

   ConjuntoElemento.Imprimir();

}
template class Conjunto<int>;
template class Conjunto<float>;
template class Conjunto<char>;
template class Conjunto<Libro*>;
