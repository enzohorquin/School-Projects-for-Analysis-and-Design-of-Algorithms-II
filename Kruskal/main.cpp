#include "TP2_Grafo.h"
#include "list"
#include "iostream"
#include "set"
#define INFINITO 999;
#define Discernible -1;
#include "unionfind.h"
#include "arcoc.h"
#include <queue>
using namespace std;


struct Nodo{ int origen;int destino; int Costo;};
void CreaColaPrioridad( priority_queue<ArcoC<int> > & MiCola, Grafo<int> & G);

void Kruskal( priority_queue<ArcoC<int> >& MiCola,int N);

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<int> vertices;
	grafo.devolverVertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolverAdyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolverAdyacente() << " (" << ady->devolverCosto() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}
int main(int argc, char **argv)
{
	Grafo<int> g;

	// Cargamos un grafo dirigido
	// Primero los vértices

	g.agregarVertice(1);
    g.agregarVertice(2);
    g.agregarVertice(3);
    g.agregarVertice(4);
    g.agregarVertice(5);
    g.agregarVertice(6);
    g.agregarVertice(7);
    g.agregarVertice(8);
    g.agregarVertice(9);

    g.agregarArco(1,2,1);
    g.agregarArco(1,4,2);
    g.agregarArco(2,1,1);
    g.agregarArco(2,3,8);
    g.agregarArco(2,4,2);
    g.agregarArco(2,5,17);
    g.agregarArco(2,6,16);
    g.agregarArco(3,2,8);
    g.agregarArco(3,6,9);
    g.agregarArco(4,1,2);
    g.agregarArco(4,2,2);
    g.agregarArco(4,7,9);
    g.agregarArco(4,5,5);
    g.agregarArco(5,2,17);
    g.agregarArco(5,4,5);
    g.agregarArco(5,6,1);
    g.agregarArco(5,7,17);
    g.agregarArco(5,8,11);
    g.agregarArco(5,9,4);
    g.agregarArco(6,2,16);
    g.agregarArco(6,3,9);
    g.agregarArco(6,5,1);
    g.agregarArco(6,9,4);
    g.agregarArco(7,4,9);
    g.agregarArco(7,5,17);
    g.agregarArco(7,8,16);
    g.agregarArco(8,5,11);
    g.agregarArco(8,7,16);
    g.agregarArco(8,9,3);
    g.agregarArco(9,5,4);
    g.agregarArco(9,6,4);
    g.agregarArco(9,8,3);





cout << "Estructura del grafo:\n" << g << "\n";

priority_queue<ArcoC<int> > MiCola;


CreaColaPrioridad(MiCola,g);
int N=g.devolverLongitud();

Kruskal(MiCola,N);



}

void CreaColaPrioridad( priority_queue<ArcoC<int> >  & MiCola , Grafo<int> & G)
{
    list<int> LVertices;
    G.devolverVertices(LVertices);
    list<int>::iterator IteListaVertices=LVertices.begin();
    while(IteListaVertices!= LVertices.end())
    {


        int V= *IteListaVertices;
        list<typename Grafo<int> ::Arco> Ady;
        G.devolverAdyacentes(V,Ady);
         list<typename Grafo<int> ::Arco>::iterator IAdy=Ady.begin();
         while(IAdy!= Ady.end())
         {  int ori= V;
            int dest= IAdy->devolverAdyacente();
            int c= IAdy->devolverCosto();


             ArcoC<int> UnArco(ori,dest,c);
            MiCola.push(UnArco);

            IAdy++;

         }
        Ady.clear();
        IteListaVertices++;
    }


}
void Kruskal(priority_queue<ArcoC<int> >  & MiCola, int N)
{   list<Nodo> Resultado;
    int CostoTotal=0;
    Union_Find Arreglo(N);
    int Cantidad=0;
    while ((!MiCola.empty())&&(Cantidad!=N))
    {   ArcoC<int> UnArco= MiCola.top();

        int ori=UnArco.devolverOrigen();
      int dest= UnArco.devolverDestino();
      int Cost= UnArco.devolverCosto();
      int j=Arreglo.Encontrar(ori);
      int i=Arreglo.Encontrar(dest);
         MiCola.pop();
      if( i!=j)
      {
         Arreglo.Union(ori,dest,j,i,N);
        Arreglo.Mostrar(N);
        cout<<endl;
        Nodo Nuevo;
        Nuevo.Costo=Cost;
        Nuevo.destino=dest;
        Nuevo.origen=ori;
         Cantidad=Arreglo.CantComponentes(ori);
        Resultado.push_back(Nuevo);
        CostoTotal=CostoTotal + Cost;


      }




    }


    list<Nodo>:: const_iterator IteResultado= Resultado.begin();

    while(IteResultado!= Resultado.end())
    {
        cout<<"("<<IteResultado->origen<<" , " << IteResultado->destino<< ")"<<" ("<<IteResultado->Costo<<")"<<endl;
        IteResultado++;



    }


cout<< "Costo Asociado al Arbol "<< CostoTotal;



}
