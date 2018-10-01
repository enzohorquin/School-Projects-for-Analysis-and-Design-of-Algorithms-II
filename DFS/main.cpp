#include "TP2_Grafo.h"
#include "list"
#include "iostream"
#include "set"

using namespace std;

void Dfs( Grafo<int> & G,int u, bool Marca[], int Padre[],int Descubierto[],int Finalizado[],int  & tiempo);
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

	g.agregarArco(1,6,1);
	g.agregarArco(2,3,1);
	g.agregarArco(2,6,1);
	g.agregarArco(2,7,1);
	g.agregarArco(7,8,1);
	g.agregarArco(8,3,1);
	g.agregarArco(1,5,1);
	g.agregarArco(3,4,1);
	g.agregarArco(4,8,1);

    g.agregarArco(5,1,6);

cout << "Estructura del grafo:\n" << g << "\n";

 int N = g.devolverLongitud();
 bool Marca[N];
 int Padre[N];
int Descubierto[N];
int Finalizado[N];
int tiempo=0;
list<int> ListaVertices;
g.devolverVertices(ListaVertices);
typename list<int>:: const_iterator Ite= ListaVertices.begin();
for(int i=1;i<=N;i++)
{   Descubierto[i]=0;
    Finalizado[i]=0;
    Marca[i]=false;
    Padre[i]=0;
}


for(int i=1; i<=N;i++)
{
    if (Marca[i]==false)
        Dfs(g,i,Marca,Padre,Descubierto,Finalizado,tiempo);
}
cout<<"El recorrido DFS es " <<endl;
for(int i=1; i<=N;i++)
    cout<<Padre[i]<<"  " ;
cout<<endl;
for(int i=1; i<=N;i++)
    cout<<Finalizado[i]<<"  " ;

}
void Dfs( Grafo<int> & G,int u, bool Marca[], int Padre[],int Descubierto[],int Finalizado[],int &tiempo)
{   tiempo=tiempo+1;
    Descubierto[u]=tiempo;
    Marca[u]=true;
     list<typename Grafo<int>::Arco> Ady;
    G.devolverAdyacentes(u,Ady);

    typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
    iteListaAdyacentes= Ady.begin();

    while(iteListaAdyacentes!=  Ady.end())
    {
       int v=iteListaAdyacentes->devolverAdyacente();
       if(!Marca[v])
       {

           Padre[v]=u;
           Dfs(G,v,Marca,Padre,Descubierto,Finalizado,tiempo);
       }
    iteListaAdyacentes++;
    }
tiempo=tiempo+1;
Finalizado[u]=tiempo;
}
