#pragma once

#include <iostream>

class SterownikEkranu {
public:
    virtual void rysuj() = 0;
};

class SterownikDrukarki {
public:
    virtual void drukuj() = 0;
};

class SENR {
public:
    void rysuj() {std::cout<<"Rysuje figure za pomoca sterownika ekranu niskiej rozdzielczosci SENR\n";}
};

class SEWR {
public:
    void rysuj() {std::cout<<"Rysuje/D figure za pomoca sterownika ekranu/ wysokiej rozdzielczosci SEWr\n";}
};

class SDNR {
public:
    void drukuj() {std::cout<<"Drukuje figure za pomoca sterownika drukarki niskiej rozdzielczosciSDNR\n";}
};

class SDWR {
public:
    void drukuj() {std::cout<<"Drukuje figure za pomoca sterownika drukarki wyskokej rozdzielczosciSDWR\n";}
};

class SterEkmNisRozdz : public SterownikEkranu {
private:
    SENR senr;
public:
    void rysuj() override {senr.rysuj();}
};

class SterEkmWysRozdz : public SterownikEkranu {
private:
    SEWR sewr;
public:
    void rysuj() override {sewr.rysuj();}
};

class SterDrukNisRozdz : public SterownikDrukarki {
private:
    SDNR sdnr;
public:
    void drukuj() override {sdnr.drukuj();}
};

class SterDrukWysRozdz : public SterownikDrukarki {
    SDWR sdwr;
public:
    void drukuj() override {sdwr.drukuj();}
};

class FabrykaSter {
public:
    virtual SterownikEkranu* pobierzSterEkm() = 0;
    virtual SterownikDrukarki* pobierzSterDruk() = 0;
};

class FabrykaNisRozdz : public FabrykaSter {
public:
    virtual SterownikEkranu* pobierzSterEkm() override {
        return new SterEkmNisRozdz();
    }
    virtual SterownikDrukarki* pobierzSterDruk() override {
        return new SterDrukNisRozdz();
    }
};

class FabrykaWysRozdz : public FabrykaSter {
public:
    virtual SterownikEkranu* pobierzSterEkm() override {
        return new SterEkmWysRozdz();
    }
    virtual SterownikDrukarki* pobierzSterDruk() override {
        return new SterDrukWysRozdz();
    }
};

class Konfiguracja {
public:
    enum class Type {HIGH, LOW};
    static FabrykaSter* getFabryka(Type t) {
        if (t == Type::HIGH) {
            return new FabrykaWysRozdz();
        } else {
            return new FabrykaNisRozdz();
        }
    }
};

class ApNadzorujaca {
    FabrykaSter* m_conf;
public:
    ApNadzorujaca(Konfiguracja::Type t) {
        m_conf = Konfiguracja::getFabryka(t);
    }
    void doSomething() {
        m_conf->pobierzSterDruk()->drukuj();
        m_conf->pobierzSterEkm()->rysuj();
    }
};