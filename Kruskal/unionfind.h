#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <iostream>
using namespace std;
class Union_Find
{
    public:
        Union_Find(int N);
         ~Union_Find();
       int  Encontrar(int vertice);
       int CantComponentes(int vertice);
    void Union(int vertice1, int vertice2, int RaizComponente1, int RaizComponente2,int N);
    void Mostrar(int N);
    protected:
    private:
        int * Padre;
};

Union_Find::Union_Find(int N)
{
    Padre = new int[N+1];
    for(int i=1; i<= N; i++)
        Padre[i]=-1;
}
Union_Find::~Union_Find()
{
    delete [] Padre;
}
int Union_Find::CantComponentes(int vertice)
{
    return (-(Padre[vertice]));




}
void Union_Find::Mostrar(int N)
{
    for (int i=1; i<=N ; i++)
        cout<< Padre[i]<< "  ";


}


 int Union_Find::Encontrar(int vertice)
 {
     int Dad = Padre[vertice];
      if (Dad<0 )                   // En caso de que el vertice sea el padre, retorna el mismo vertice
        return vertice;
     else{ int j=Dad;
     while(Dad > 0)
     {     j=Dad;                   // Mientras que la variable Dad sea mayor que cero, voy buscando el padre, guardando en una variable j en caso de que
           Dad=Padre[j];                         // lo encuentre

         if(Dad<0)
        return j;

     }}


 }
 void Union_Find::Union(int vertice1, int vertice2,int RaizComponente1, int RaizComponente2,int N)
 {
     int CantidadComponentes1= Padre[RaizComponente1];          //Guardo en dos variables la cantidad de vertices que tienen los dos componentes
     int CantidadComponentes2= Padre[RaizComponente2];
     bool RealizarUnionSobreC1=false;
     if(CantidadComponentes1<=CantidadComponentes2)             // Aca decido a que "Padre" decido agregar los componentes
        RealizarUnionSobreC1=true;

     int i=1;
     while(i<= N)
     {  if(RealizarUnionSobreC1)                            // Si es true, realizo la union de componentes del "Conjunto 2" al "Conjunto 1"
         {if( i!= RaizComponente1)                          //Pregunto si mi variable es distinta al Padre del Conjunto 1
            {
                int j=Encontrar(i);                            //Asigno a mi variable j, el padre de esa variable i
                int CantComponentes= Padre[j];
            if(j== RaizComponente2)
                                                                //Si esa variable es igual al padre del Conjunto 2 , entonces hago que su nuevo padre sea el de
            {                                                   // Conjunto 1
                Padre[RaizComponente1]+= CantComponentes;
                Padre[i]=RaizComponente1;
                Padre[j]=RaizComponente1;
            }
            else{if (j==RaizComponente1)                           //En caso que sea distinto a la RaizComponente2 , pregunto si el padre es igual a RaizComponente 1
                    Padre[i]=RaizComponente1;                      // Si es asi, lo cambio.


            }

            }
         }
        else
            {if( i!= RaizComponente2)
            {
                int j=Encontrar(i);
                int CantComponentes= Padre[j];
            if(j== RaizComponente1)
            {
                Padre[RaizComponente2]+= CantComponentes;
                Padre[i]=RaizComponente2;
                Padre[j]=RaizComponente2;
            }
            else{if (j==RaizComponente2)
                    Padre[i]=RaizComponente2;


            }

            }



            }
        i++;
     }





 }
#endif // UNION_FIND_H
