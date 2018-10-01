#include "Lista.h"
#include <iostream>
using namespace std;

template <typename Elem>Lista<Elem>::Lista()
{
    ListaElementos=0;l=0;cursor=0;

}
template <typename Elem>Lista<Elem>::~Lista()
{
  Elimina(ListaElementos);
    l=0;
    ListaElementos=0;

}
template <typename Elem> void Lista<Elem>:: VaciaLista()
{
Elimina(ListaElementos);
l=0;

}
 template <typename Elem> bool Lista<Elem> ::   PerteneceElem( Nodo * & Lista, Elem valor )
{
     if ( Lista== 0)
    return false;
else
    if ( Lista -> valor== valor)
        return true ;
        else
            return PerteneceElem(Lista->SigLista,valor)     ;


}
template <typename Elem> void Lista<Elem> :: EliminaElemento(Elem elemento)
{
    EliminaElementoLista(ListaElementos,elemento);
    l--;


}
template <typename Elem> void Lista<Elem> :: EliminaElementoLista ( Nodo * & Lista, Elem elemento)
{
    if (Lista!= 0)
        {if ( Lista->valor == elemento)
        {   Nodo* Aux=0;
            Aux= Lista;
            Lista= Lista->SigLista;

            delete Aux;}

            else
                EliminaElementoLista(Lista->SigLista,elemento);}
}
template <typename Elem>bool Lista<Elem> :: ListaVacia ( ) const
{
    if (ListaElementos==0)
        return true;
    else
        return false;
}
 template <typename Elem> bool Lista<Elem> ::  PerteneceElemento( Elem valor)
 {
    bool j= PerteneceElem(ListaElementos,valor);
    return (j);

 }

 template <typename Elem> void Lista<Elem>:: AgregaElemFinal( Nodo * & ListaElementos, Elem valor)
 {

     if (ListaElementos!=0)
        AgregaElemFinal(ListaElementos->SigLista,valor);
    else
        {       Nodo*Aux= new Nodo;
                Aux->valor=valor;
                Aux->SigLista=0;
                ListaElementos=Aux;

        }


 }
template <typename Elem>void Lista<Elem> :: AgregaElementosFinal( Elem valor)
{

    AgregaElemFinal(ListaElementos,valor);
    l++;
}
template<typename Elem> void Lista<Elem>::Elimina(Nodo*& Lista)
{
    if(Lista!=0)
    {
        Elimina(Lista->SigLista);
        delete(Lista);
    }
Lista=0;

}
template <typename Elem> void Lista<Elem> :: AgregaElementosPrincipio( Elem valor)
{
        Nodo * Aux = new Nodo;
        Aux->valor=valor;
        Aux->SigLista= ListaElementos;
        ListaElementos=Aux;
        l++;
}
template <typename Elem> void  Lista<Elem> :: AgregaElem( Nodo*& ListaElementos, int pos,Elem valor, int contador)
{

    if (ListaElementos!=0)
      {
            if ( contador== pos )
        {

                Nodo * Aux = new Nodo ;
                Aux->valor= valor;
                Aux->SigLista= ListaElementos;
                ListaElementos= Aux;
        }

    else
        AgregaElem(ListaElementos->SigLista,pos,valor,contador+1);}
else
   {
       AgregaElementosPrincipio(valor);l--;// Le resto uno por que el metodo Agrega Elementos Principio
                                                                //ya incrementa en uno y no hace falta incrementar
   }
}
template <typename Elem>void Lista<Elem> :: AgregarElementos(int pos, Elem valor)
{
int contador=0;
if (pos==0)
   {AgregaElementosPrincipio(valor);}
else
    if ((0<pos)&&(pos<= longlista()+1))
    {AgregaElem(ListaElementos,pos,valor,contador);
   l++;}
else
    {
        cout<<"Posicion Incorrecta, por favor vuelva a ingresar una nueva posicion";
    }

}
template <typename Elem>void Lista<Elem>:: Imprimir()
{

    Print(ListaElementos);

}
template <typename Elem> void Lista<Elem>:: Print( Nodo* ListaElementos)
{
   if (ListaElementos != 0)
        {cout<< ListaElementos->valor<<" ";
        Print(ListaElementos->SigLista);

        }

}


template <typename Elem> Elem Lista<Elem>::elemento()
{
    if (cursor!=0)
        return cursor->valor;

}

template <typename Elem> void Lista<Elem>::reset()
{
    cursor=ListaElementos;
}
template <typename Elem> bool Lista<Elem>::final()
{
    return (cursor==0);
}

 template <typename Elem> void Lista<Elem>::avanzar()
 {
     if (cursor)
        cursor=cursor->SigLista;
 }

template <typename Elem>int Lista<Elem> :: longlista() const
{

    return l;
}
template class Lista<int>;
template class Lista<float>;
template class Lista<char>;
template class Lista<string>;
template class Lista<Libro*>;
