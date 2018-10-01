#include "TP2_Grafo.h"
#include "list"
#include "iostream"
#include "set"
#define INFINITO 999;
#define Discernible -1;
using namespace std;
void Inicializacion(Grafo<int> & G, set<int> & S, set<int> & Q,int  Distancia[], int Padre[],int origen, int Cant);
void Dijkstra(Grafo<int> & G, set<int> & S, set<int> & Q, int  Distancia[], int Padre[],int origen,int Cant, set<int> & V);
int ExtraerMin(int Distancia[], set<int> & Q, int N,int origen );
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

	g.agregarArco(1,2,10);
	g.agregarArco(2,3,50);
	g.agregarArco(1,5,100);
	g.agregarArco(4,5,60);
	g.agregarArco(3,5,10);
	g.agregarArco(1,4,30);
	g.agregarArco(4,3,20);


cout << "Estructura del grafo:\n" << g << "\n";

 int N = g.devolverLongitud();
 int Distancia[N];
 int Padre[N];
set<int> S,Q;
int origen=1;

 set<int> V;
 for (int j=1;j<=N;j++)
   {
       V.insert(j);

   }
Q=V;
 Dijkstra(g,S,Q,Distancia,Padre,origen,N,V);
cout<<endl;
for (int j=1;j<=N;j++)
    cout<<Distancia[j]<< "   ";
cout<< "Arreglo Padres"<<endl;
for (int j=1;j<=N;j++)
    cout<<Padre[j]<< "   ";
}


void Dijkstra(Grafo<int> & G, set<int> & S, set<int> & Q, int  Distancia[], int Padre[],int origen,int Cant, set<int> & V)
{
    int v= V.size();

    int Contador=v;

Inicializacion(G,S,Q,Distancia,Padre,origen,Cant);

Contador--;
cout<<Contador;
while(Contador>= 0)
{
    int w=ExtraerMin(Distancia,Q,Cant, origen);
    S.insert(w);


    list<typename Grafo<int>::Arco> Ady;
    G.devolverAdyacentes(w,Ady);

    typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
    iteListaAdyacentes= Ady.begin();

    while(iteListaAdyacentes!=  Ady.end())
    {
       int v=iteListaAdyacentes->devolverAdyacente();
        int CostoArco= iteListaAdyacentes->devolverCosto();
        if(Distancia[v]> Distancia[w]+ CostoArco)
        {Distancia[v]= Distancia[w]+ CostoArco;
        Padre[v]=w;
        iteListaAdyacentes++;

        }
            else
                iteListaAdyacentes++;
    }


 Contador=Contador -1;

}

}
int ExtraerMin(int Distancia[], set<int> & Q, int N,int origen)
{
typename set<int>::const_iterator Ite ;
    int Menor=1000;
    int vertice;
    for ( int i=1;i<=N; i++)
    {
    Ite=Q.find(i);
        if ( Ite!=Q.end())
           { if (i!= origen)

            if(Distancia[i]< Menor)
               {
                   Menor=Distancia[i];
                    vertice=i;
               }

           }
    }

     set<int> q;
    set<int>:: iterator Iter=Q.begin();

    while(Iter!=Q.end()){
       if(*Iter!=vertice)
    {
        q.insert(*Iter);
         Iter++;
    }

   else Iter++;  }

   Q.clear();
   Q=q;


    return vertice;
}
 void Inicializacion(Grafo<int> & G, set<int> & S, set<int> & Q, int  Distancia[], int Padre[],int origen, int Cant)
 {

     S.insert(origen);
    list<int> ListaVertices;
    G.devolverVertices(ListaVertices);
    list<int> :: iterator IteListaVertices= ListaVertices.begin();
    set<int>:: const_iterator Ite= Q.find(origen);
    Q.erase(Ite);
    while(IteListaVertices!= ListaVertices.end())
    {    int v=*IteListaVertices;
        if(v!= origen)
        {
            if(G.existeArco(origen,v))
            {
               list<typename Grafo<int>::Arco> adyacentes;
                G.devolverAdyacentes(origen, adyacentes);
                typename list<typename Grafo<int>::Arco>::iterator ady = adyacentes.begin();
                while ((ady != adyacentes.end())&&(ady->devolverAdyacente()!=v))
                    ady++;
               int CostoArco= ady->devolverCosto();


                Distancia[v]= CostoArco;
                Padre[v]=origen;
            }
        else
            {Distancia[v]=INFINITO;
            Padre[v]= Discernible;}


        }
    else
        {Distancia[v]=0;
        Padre[v]=0;}


     IteListaVertices++;;
    }

 }
