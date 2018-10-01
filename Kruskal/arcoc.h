#ifndef ARCOC_H
#define ARCOC_H
#include <iostream>

template <typename C> class ArcoC
{
    public:

        ArcoC(int origen, int destino, const C & costo);
        ~ArcoC();
        bool  operator < ( const ArcoC & OtroArco)const;
        int devolverOrigen( );
        int devolverDestino();
        const C & devolverCosto() const ;
        protected:
    private: int origen;
            int destino;
            C Costo;
};
template<typename C> ArcoC<C>:: ~ArcoC()
{

}
template <typename C> ArcoC<C>::ArcoC(int origen, int destino, const C & costo)
{
   this->destino= destino;
   this->origen= origen;
   this->Costo= costo;


}
template <typename C> int ArcoC<C>::devolverDestino()
{

    return destino;
}
template <typename C> bool  ArcoC<C>:: operator < ( const ArcoC & OtroArco) const
{
    return (Costo > OtroArco.devolverCosto());




}
template <typename C> int ArcoC<C>::devolverOrigen()
{

    return origen;
}
template <typename C> const C & ArcoC<C>::devolverCosto() const
{
    return Costo;
}
#endif // ARCOC_H
