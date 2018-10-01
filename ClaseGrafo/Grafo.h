#ifndef GRAFO_H_
#define GRAFO_H_
#include <list>
#include <iostream>
#define INFINITO 9999999;
//-----------------------------------------------------------------------------------------------//
using namespace std;

template <typename C> class Grafo
{
    public:

        class Arco
        {
            public:
                Arco();

                Arco(int adyacente, const C & costo);
                int devolverAdyacente() const;
                const C & devolverCosto() const;
                int vertice;
                C costo;
        };
    public:
        Grafo();
        Grafo(const Grafo & otroGrafo);
        ~Grafo();
        Grafo & operator = (const Grafo & otroGrafo);
        bool estaVacio() const;
        int devolverLongitud() const;
        bool existeVertice(int vertice) const;
        bool existeArco(int origen, int destino) const;
        const C & costoArco(int origen, int destino) const;
        void devolverVertices(list<int> & vertices) const;
        void devolverAdyacentes(int origen, list<Arco> & adyacentes) const;
        void agregarVertice(int vertice);
        void eliminarVertice(int vertice);
        void agregarArco(int origen, int destino, const C & costo);
        void eliminarArco(int origen, int destino);
        void vaciar();
    private:
        struct NGrafo{
            int vertice;
            list<Arco> adyacentes;
        };
        list<NGrafo> grafo;
};


template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{
    vertice = adyacente;
    this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolverAdyacente() const
{
    return this->vertice;
}

template <typename C> const C & Grafo<C>::Arco::devolverCosto() const
{
    return costo;
}

template <typename C> Grafo<C>::Grafo()
{
    // Se llama al constructor de la lista
}
template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{
    list<int> otroGrafo_vertices;
    list<Arco> otroGrafo_adyacentes;
    vaciar();
    typename list<int>::const_iterator vertices;
    otroGrafo.devolverVertices(otroGrafo_vertices);
    for(vertices = otroGrafo_vertices.begin(); vertices != otroGrafo_vertices.end(); vertices++)
        this->agregarVertice(*vertices);
    typename list<int>::const_iterator otroGrafo_iterador;
    typename list<Arco>::const_iterator otroGrafo_adyacentes_iterador;
    for(vertices = otroGrafo_vertices.begin(); vertices != otroGrafo_vertices.end(); vertices++, otroGrafo_adyacentes_iterador++)
    {
        otroGrafo.devolverAdyacentes(*vertices,otroGrafo_adyacentes);
        for(otroGrafo_adyacentes_iterador = otroGrafo_adyacentes.begin(); otroGrafo_adyacentes_iterador != otroGrafo_adyacentes.end(); otroGrafo_adyacentes_iterador++)
            agregarArco(*vertices, otroGrafo_adyacentes_iterador->devolverAdyacente(), otroGrafo_adyacentes_iterador->devolverCosto());
    }
}

template <typename C> Grafo<C>::~Grafo()
{
// Se llama al destructor de la lista.

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
    list<int> otroGrafo_vertices;
    list<Arco> otroGrafo_adyacentes;
    vaciar();
    typename list<int>::const_iterator vertices;
    otroGrafo.devolverVertices(otroGrafo_vertices);
    for(vertices = otroGrafo_vertices.begin(); vertices != otroGrafo_vertices.end(); vertices++)
        this->agregarVertice(*vertices);
    typename list<int>::const_iterator otroGrafo_iterador;
    typename list<Arco>::const_iterator otroGrafo_adyacentes_iterador;
    for(vertices = otroGrafo_vertices.begin(); vertices != otroGrafo_vertices.end(); vertices++, otroGrafo_adyacentes_iterador++)
    {
        otroGrafo.devolverAdyacentes(*vertices,otroGrafo_adyacentes);
        for(otroGrafo_adyacentes_iterador = otroGrafo_adyacentes.begin(); otroGrafo_adyacentes_iterador != otroGrafo_adyacentes.end(); otroGrafo_adyacentes_iterador++)
            agregarArco(*vertices, otroGrafo_adyacentes_iterador->devolverAdyacente(), otroGrafo_adyacentes_iterador->devolverCosto());
    }
}

template <typename C> bool Grafo<C>::estaVacio() const
{
    return grafo.size();
}

template <typename C> int Grafo<C>::devolverLongitud() const
{
    return grafo.size();
}

template <typename C> bool Grafo<C>::existeVertice(int vertice) const
{
    typename list<NGrafo>::const_iterator it;
    it = grafo.begin();
    while ((it != grafo.end())&&(it->vertice != vertice))
        it++;
    if (it != grafo.end())
        return true;
    else
        return false;
}

template <typename C> bool Grafo<C>::existeArco(int origen, int destino) const
{
    list<Arco> adyacentes;
    devolverAdyacentes(origen,adyacentes);
    if(adyacentes.size())
    {
        typename list<Arco>::const_iterator it;
        it = adyacentes.begin();
        while((it != adyacentes.end())&&(it->devolverAdyacente() != destino))
            it++;
        if (it != adyacentes.end())
            return true;
        else
            return false;
    }
    else
        return false;
}

template <typename C> const C & Grafo<C>::costoArco(int origen, int destino) const
{
    list<Arco> ady;
    devolverAdyacentes(origen,ady);
    if(!ady.empty())
    {
        typename list<Arco>::const_iterator ite;

        ite=ady.begin();

        while((ite!= ady.end())&&(ite->devolverAdyacente()!= destino))
            ite++;

        if(ite->devolverAdyacente()== destino)
            return ite->devolverCosto();
        else return -1;


    }
else  return -1;



}

template <typename C> void Grafo<C>::devolverVertices(list<int> & vertices) const
{
    typename list<NGrafo>::const_iterator it;
    it = grafo.begin();
    while (it != grafo.end())
    {
        vertices.push_back(it->vertice);
        it++;
    }
}

template <typename C> void Grafo<C>::devolverAdyacentes(int origen, list<Arco> & adyacentes) const
{
    if(existeVertice(origen))
    {
        typename list<NGrafo>::const_iterator it;
        it = grafo.begin();
        while ((it != grafo.end())&&(it->vertice != origen))
            it++;
        adyacentes = it->adyacentes;
    }
}

template <typename C> void Grafo<C>::agregarVertice(int vertice)
{
    NGrafo Nuevo;
    Nuevo.vertice = vertice;
    this->grafo.push_back(Nuevo);
}

template <typename C> void Grafo<C>::eliminarVertice(int vertice)
{
    typename list<NGrafo>:: iterator ite;
    ite=grafo.begin();

    while((ite!=grafo.end())&&(ite->vertice!= vertice))
        ite++;

    if(ite!= grafo.end())
    {
        ite->adyacentes.clear();
        grafo.erase(ite);


    }
    else cout<<"No se encontro el vertice ";



}

template <typename C> void Grafo<C>::agregarArco(int origen, int destino, const C & costo)
{
    typename list<NGrafo>::iterator ite;
    ite=grafo.begin();


    while ((ite!=grafo.end())&&(ite->vertice!=origen))
              ite++;

            Arco nuevo(destino,costo);
            ite->adyacentes.push_front(nuevo);

}

template <typename C> void Grafo<C>::eliminarArco(int origen, int destino)
{
   typename list<NGrafo>:: const_iterator ite;
   typename list<Arco>:: const_iterator itelistaAdy;
   typename list<Arco>:: const_iterator itelistaAdyEnd;
   ite=grafo.begin();
   while((ite!=grafo.end())&&(ite->vertice!=origen))
    ite++;
   itelistaAdyEnd=ite.adyacentes.end();
   if (ite!=grafo.end())
   {
       itelistaAdy=ite->adyacentes;
       while((itelistaAdy!=itelistaAdyEnd)&&(itelistaAdy->devolverAdyacentes()!= destino))//avanzo sobre la lista de vertices adyacentes.
        itelistaAdy++;

       if(itelistaAdy!=itelistaAdyEnd)      //Pregunto si el iterador es distinto de end,
       {                                    //dado que si es igual a end significa que no encontro el vertice destino
          ite->adyacentes.erase(itelistaAdy);


       }
       else cout<<"No se puede eliminar arco"<<endl;
   }
else cout<<"No se puede eliminar arco"<<endl;
}

template <typename C> void Grafo<C>::vaciar()
{
grafo.clear();
}

#endif /* GRAFO_H_ */
