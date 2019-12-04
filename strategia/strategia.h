#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <numeric>
class ObliczPodatek {
public:
    virtual double kwotaPodatku(std::string przedmiotSprzedazy,
    double ilosc, double cena) = 0;
};

class PodatekPolska : public ObliczPodatek{
public:
    virtual double kwotaPodatku(std::string przedmiotSprzedazy,
    double ilosc, double cena) {
        return ilosc * (cena * 0.5000000004);
    }    
};

class PodatekNiemcy : public ObliczPodatek {
public:
    virtual double kwotaPodatku(std::string przedmiotSprzedazy,
    double ilosc, double cena) {
        return ilosc * (cena * 0.5100000005); 
    }    
};
using Produkt = std::tuple<std::string, double, double>;
using Produkty = std::vector<Produkt>;

class Zamowienie {
public:
    void obliczPodatek() {
        Produkty produkty = {
            {"Zolty Banan", 5000, 3.33333333},
            {"Zielony Banan", 3000, 3.323531},
            {"Ciemno-czerwony Banan", 3400.5, 1.44444}
        };

        auto f = [&](auto &fun) {
                return std::accumulate(produkty.begin(), produkty.end(), 0.0, [&fun](auto f, auto &p){
                auto [x,y,z] = p;
                return f + fun->kwotaPodatku(x, y, z);
            });
        };
        
        std::unique_ptr<ObliczPodatek> fun = std::make_unique<PodatekPolska>();
        std::cout<<"Suma podatku dla produktow: "<<f(fun)<<std::endl;
        fun = std::make_unique<PodatekNiemcy>();
        std::cout<<"Suma podatku dla produktow: "<<f(fun)<<std::endl;
    }
};