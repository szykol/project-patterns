#pragma once

#include <iostream>

class Komponent {
public:
    virtual void drukuj() {std::cout<<"Drukuje komponent\n";}
};

class DekoratorPotwierdzenia : public Komponent{
private:
    Komponent* mojKomponent = nullptr;
public:
    virtual void drukuj() override { if (mojKomponent != nullptr) mojKomponent->drukuj();}
    DekoratorPotwierdzenia(Komponent* k) : mojKomponent(k) {}
};

class Potwierdzenie : public Komponent {
public:
    virtual void drukuj() override {std::cout<<"Potwierdzenie\n";}
};

class DekoratorNaglowka : public DekoratorPotwierdzenia {
public:
    virtual void drukuj() override { drkNaglowka(); DekoratorPotwierdzenia::drukuj();}
    DekoratorNaglowka(Komponent* k) : DekoratorPotwierdzenia(k) {}
    void drkNaglowka() {std::cout<<"Drknaglwka\n";}
};

class DekoratorStopki : public DekoratorPotwierdzenia {
public:
    virtual void drukuj() override { DekoratorPotwierdzenia::drukuj(); drkStopki();}
    DekoratorStopki(Komponent* k) : DekoratorPotwierdzenia(k) {}
    void drkStopki() {std::cout<<"Drkspotki\n";}
};

class DekoratorNaglowka2 : public DekoratorPotwierdzenia {
public:
    virtual void drukuj() override { drkNaglowka(); DekoratorPotwierdzenia::drukuj();}
    DekoratorNaglowka2(Komponent* k) : DekoratorPotwierdzenia(k) {}
    void drkNaglowka() {std::cout<<"Drknaglwka2\n";}
};

class DekoratorStopki2 : public DekoratorPotwierdzenia {
public:
    virtual void drukuj() override { DekoratorPotwierdzenia::drukuj(); drkStopki();}
    DekoratorStopki2(Komponent* k) : DekoratorPotwierdzenia(k) {}
    void drkStopki() {std::cout<<"Drkspotki2\n";}
};

class Konfiguracja {
public:
    enum class Type {FIRST, SECOND};
    void getConfiguration(Type t) {
        auto p = Potwierdzenie();
        auto dn = DekoratorNaglowka(&p);
        auto s = DekoratorStopki(nullptr);
        auto s2 = DekoratorStopki2(nullptr);
        auto d2 = DekoratorNaglowka2(&p);
        if (t == Type::FIRST) {
            dn.drukuj();
            s.drukuj();
            s2.drukuj();
        } else {
            DekoratorNaglowka(nullptr).drukuj();
            d2.drukuj();
            s2.drukuj();
        }
    }
};