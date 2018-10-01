
#include "Grafo.h"
#include "list"
#include "iostream"
template <typename C> ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	list<int> vertices;   //Recorremos todos los vertices
	grafo.devolverVertices(vertices);
	list<int>::iterator v;
	v = vertices.begin();
	cout << endl;
	while (v != vertices.end())
	{
		salida << "Vertice: " << *v << endl;  // Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolverAdyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady;
		ady = adyacentes.begin();
		while (ady != adyacentes.end())
		{
			salida << "            " << "-> " << ady->devolverAdyacente() << " con costo: (" << ady->costo << ")" << endl;
			ady++;
		}
		v++;
		cout << endl;
	}
	cout << endl;
	return salida;
}

using namespace std;


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


cout<< " Estructura Grafo :"<< g;
g.vaciar();
cout<< " Estructura Grafo :"<< g;
}

