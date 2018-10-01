#include <iostream>
#include "TP2_Grafo.h"
using namespace std;
void LongitudDFS(Grafo<int> & G, bool Marca[], int v, int longi, int longitudActual, list<int> & R );
void MostrarR(list<int> & R);

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
}int main()
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
int longi,longitudActual;
 int N = g.devolverLongitud();
 bool Marca[N];
  list<int> R;
  cout<<"Eliga longitud " ;
  cin>>longi;
longitudActual=0;
for(int i=1;i<=N; i++)
    Marca[i]=false;
 for(int i=1; i<=N;i++)
{
    if (Marca[i]==false)
        LongitudDFS(g,Marca,i,longi,longitudActual,R);
}


}
void MostrarR(list<int> & R)
{typename list<int>:: iterator Mostrar=R.begin();

while(Mostrar!=R.end())
{   cout<<*Mostrar<< "  ";
    Mostrar++;


}

cout<<endl;



}
void LongitudDFS(Grafo<int> & G, bool Marca[], int v, int longi, int longitudActual, list<int> & R )
{

    R.push_back(v);
    Marca[v]=true;

    if(longi==longitudActual)
        MostrarR(R);
    else{list<Grafo<int> :: Arco> Ady;
        G.devolverAdyacentes(v,Ady);
        typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
    iteListaAdyacentes= Ady.begin();

    while(iteListaAdyacentes!=  Ady.end())
    {
       int u=iteListaAdyacentes->devolverAdyacente();
       if(!Marca[u])
       {
           LongitudDFS(G,Marca,u,longi,longitudActual+1,R);




       }





     iteListaAdyacentes++;


    }

    }

typename list<int>:: iterator Borrar=R.begin();

while((Borrar!=R.end())&&(*Borrar!=v))
    Borrar++;

R.erase(Borrar);
Marca[v]=false;




}
