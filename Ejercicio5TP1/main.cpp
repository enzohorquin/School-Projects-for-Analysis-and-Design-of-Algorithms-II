#include "TP2_Grafo.h"
#include "list"
#include "iostream"
struct nodo { char letra; string color; int v;};
using namespace std;
void ImprimeLista(list<int> & Lista);
void DFS(Grafo<int> & G,list<int> & Caminos,   bool  Marca [ ],int origen, int destino);

struct nodoMarca{ int v; bool Visitado;};
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
	g.agregarVertice(9);
	g.agregarVertice(10);
	// Luego los arcos
	g.agregarArco(1,2,1);
	g.agregarArco(2,3,1);
	g.agregarArco(1,4,1);
	g.agregarArco(4,7,1);
	g.agregarArco(5,4,1);
	g.agregarArco(5,3,1);
	g.agregarArco(6,3,1);
	g.agregarArco(8,3,1);
	g.agregarArco(7,6,1);
	g.agregarArco(7,10,1);
	g.agregarArco(10,9,1);
	g.agregarArco(10,8,1);
	g.agregarArco(9,8,1);
cout << "Estructura del grafo:\n" << g << "\n";


bool Marca[11];
for(int i=1;i<=11;i++)
{
    Marca[i]= false;
}
list<int> Caminos;

int origen;
int destino;
cout<< "Ingrese vertice Origen : ";
cin>>origen;
cout<<endl<<"Ingrese vertice destino : ";
cin>>destino;
cout<<endl;


DFS(g,Caminos,Marca,origen,destino);

}
void DFS(Grafo<int> & G,list<int> & Caminos , bool  Marca [ ],int origen, int destino)
{

Marca[origen]= true;
Caminos.push_back(origen);

if(origen==destino)
{
ImprimeLista(Caminos);
}
else {
    list<typename Grafo<int>::Arco> Ady;
    G.devolverAdyacentes(origen,Ady);

    typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
    iteListaAdyacentes= Ady.begin();

    while(iteListaAdyacentes!= Ady.end())
        {   int V=iteListaAdyacentes->devolverAdyacente();

            if ((Marca[V]== false))
                    {

                                    DFS(G,Caminos,Marca,V,destino);

                                }





        iteListaAdyacentes++;
        }
    }



Marca[origen]=false;
typename list<int>:: iterator ite;
ite=Caminos.begin();

while((ite!=Caminos.end())&&(*ite != origen))
ite++;

Caminos.erase(ite);

}
void ImprimeLista(list<int> & Lista)
{
typename list<int>:: iterator ite;
ite=Lista.begin();
cout<< " Camino :";
while(ite!=Lista.end())
      {
          cout<<*ite<< " ";
          ite++;
      }

}

