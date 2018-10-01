#include "TP2_Grafo.h"
#include "list"
#include "iostream"
#include "set"
#define INFINITO 999;
#define Discernible -1;
using namespace std;
void Prim(Grafo<int> & G, int S[], int MenorCosto[], int MasCercano[],int N);
void Inicializacion(Grafo<int> & G, int S[], int MenorCosto[], int MasCercano[],int N,int origen);
int VerticeMenorCosto(int MenorCosto[], int MasCercano[],int N,int S[]);
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

	g.agregarArco(1,2,5);
	g.agregarArco(2,1,5);

	g.agregarArco(2,3,5);
	g.agregarArco(3,2,5);
	g.agregarArco(1,3,50);
	g.agregarArco(3,1,50);
	g.agregarArco(2,4,10);
	g.agregarArco(4,2,10);
	g.agregarArco(3,4,3);
	g.agregarArco(4,3,3);


cout << "Estructura del grafo:\n" << g << "\n";
int N = g.devolverLongitud();

int S[N+1];
int MenorCosto[N+1];
int MasCercano[N+1];
Prim(g,S,MenorCosto,MasCercano,N);

for(int i=1;i<=N;i++)
{   cout<<MenorCosto[i]<< " ";

}
cout<<endl;
for(int i=1;i<=N;i++)
{   cout<<MasCercano[i]<< " ";

}
}
void Prim(Grafo<int> & G, int S[], int MenorCosto[], int MasCercano[],int N)
{   int x;
    cout<<"Elija vertice origen" << endl;
    cin>>x;

list<int> ListaVertices;
G.devolverVertices(ListaVertices);

Inicializacion(G,S,MenorCosto,MasCercano,N,x);
S[x]=1;
list<int>::iterator IteListaVertices;
IteListaVertices=ListaVertices.begin();
while(IteListaVertices!=ListaVertices.end())
{
    int w=VerticeMenorCosto(MenorCosto,MasCercano,N,S);
        cout<<w<< " MINIMO COSTOOO "<<endl;
    S[w]=1;
list<int>::iterator Ite2;
   Ite2= ListaVertices.begin();
   while(Ite2!= ListaVertices.end())
   {
       int v= *Ite2;


       if(G.existeArco(w,v))
       {list<typename Grafo<int>:: Arco> Ady;

       G.devolverAdyacentes(w,Ady);
                typename list< Grafo<int>::Arco>:: iterator iteListaAdyacentes;
            iteListaAdyacentes= Ady.begin();

            while((iteListaAdyacentes!= Ady.end())&&(iteListaAdyacentes->devolverAdyacente()!=v))
            {
            iteListaAdyacentes++;


            }
             int Costo=iteListaAdyacentes->devolverCosto();
            if((Costo<MenorCosto[v])&&(S[v]== 0))
            {
                MenorCosto[v]=Costo;
                MasCercano[v]=w;

            }

       }
       Ite2++;



   }
    IteListaVertices++;

}
}
int VerticeMenorCosto(int MenorCosto[], int MasCercano[],int N,int S[])
{   int vertice=1;
    int Menor=1000;
    for(int i=1; i<=N; i++)
    {   cout<<MenorCosto[i]<< "  "<< S[i]<<" "<<Menor<<endl;
        if ((MenorCosto[i]< Menor)&&(S[i]==0))
        {
            Menor=MenorCosto[i];
            vertice=i;
        }


    }

 return vertice;
}
void Inicializacion(Grafo<int> & G, int S[], int MenorCosto[], int MasCercano[],int N,int x)
{
    for(int i=1;i<=N ;i++)
        S[i]=0;
    list<int> ListaVertices;
    G.devolverVertices(ListaVertices);
    list<int> :: iterator IteListaVertices= ListaVertices.begin();

    while(IteListaVertices!= ListaVertices.end())
    {    int v=*IteListaVertices;
        if(v!=x)
        {
            if(G.existeArco(x,v))
            {
               list<typename Grafo<int>::Arco> adyacentes;
                G.devolverAdyacentes(x, adyacentes);
                typename list<typename Grafo<int>::Arco>::iterator ady = adyacentes.begin();
                while ((ady != adyacentes.end())&&(ady->devolverAdyacente()!=v))
                    ady++;
               int CostoArco= ady->devolverCosto();


                MenorCosto[v]= CostoArco;
                MasCercano[v]=x;
            }
        else
            {MenorCosto[v]=INFINITO;
            MasCercano[v]= Discernible;}


        }
    else
        {MenorCosto[v]=0;
        MasCercano[v]=0;}


     IteListaVertices++;;
    }
}
