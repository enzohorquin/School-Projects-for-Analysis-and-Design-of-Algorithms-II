#include "TP2_Grafo.h"
#include "list"
#include "iostream"
#include "set"
#include "queue"
#define Blanco 0;
#define Gris 1;
#define Negro 2 ;
using namespace std;

void BFS(Grafo<int> & G, int Marca[], int s,int N);
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
	g.agregarVertice(2);
	g.agregarVertice(3);
	g.agregarVertice(4);
	g.agregarVertice(5);
	g.agregarVertice(6);
	g.agregarVertice(7);
	g.agregarVertice(8);

	g.agregarArco(1,2,1);
	g.agregarArco(2,1,1);
	g.agregarArco(1,4,1);
	g.agregarArco(4,1,1);
	g.agregarArco(1,5,1);
	g.agregarArco(5,1,1);
	g.agregarArco(2,3,1);
	g.agregarArco(2,5,1);
	g.agregarArco(5,2,1);
	g.agregarArco(3,2,1);
	g.agregarArco(4,7,1);
	g.agregarArco(7,4,1);
	g.agregarArco(3,1,1);
	g.agregarArco(1,3,1);
	g.agregarArco(4,5,1);
	g.agregarArco(5,4,1);
	g.agregarArco(4,6,1);
	g.agregarArco(6,4,1);
	g.agregarArco(5,6,1);
	g.agregarArco(6,5,1);
	g.agregarArco(7,6,1);
	g.agregarArco(6,7,1);
	g.agregarArco(5,8,1);
	g.agregarArco(8,5,1);
	g.agregarArco(7,8,1);
	g.agregarArco(8,7,1);



cout << "Estructura del grafo:\n" << g << "\n";

 int N = g.devolverLongitud();
 int Marca[N];
 int origen=4;
 BFS(g,Marca,origen,N);

}
void BFS(Grafo<int> & G, int Marca[], int s,int N)
{
    for(int i=1; i<= N; i++)
    {
        Marca[i]=Blanco;
    }

    Marca[s]=Gris;

    queue<int> Q,ColaVacia;
    Q.push(s);

    while(Q!=ColaVacia)
    {

        int u=Q.front();
        cout<<u<<"   " ;
        Q.pop();
        list<typename Grafo<int>::Arco> Ady;
    G.devolverAdyacentes(u,Ady);

    typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
    iteListaAdyacentes= Ady.begin();

    while(iteListaAdyacentes!=  Ady.end())
    {
       int v=iteListaAdyacentes->devolverAdyacente();
       if(Marca[v]==0)
       {Marca[v]=Gris;
       Q.push(v);}

       Marca[u]=Negro;
       iteListaAdyacentes++;
   }

}
}
