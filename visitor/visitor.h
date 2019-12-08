#pragma once

#include <vector>
#include <iostream>

class Visitor;

class Zwierze {
    bool zdrowe = true;
    int cena;
public:
    Zwierze(int cena, bool zdrowe=true) : cena(cena), zdrowe(zdrowe) {}
    int getCena() const { return cena; }
    bool isZdrowy() const { return zdrowe; }
    virtual void Accept(Visitor* v) = 0;
};

class Ssak;
class Ptak;
class Ryba;
class Gad;

class Visitor {
public:
    virtual void visitSsak(const Ssak& el) = 0;
    virtual void visitPtak(const Ptak& el) = 0;
    virtual void visitRyba(const Ryba& el) = 0;
    virtual void visitGad(const Gad& el) = 0;
    virtual void visitZwierzeta(const std::vector<Zwierze*> &zwierzeta) = 0;
};

class Ssak : public Zwierze {
public:
    Ssak(int cena, bool zdrowe=true) : Zwierze(cena, zdrowe) {}
    virtual void Accept(Visitor* v) {
        v->visitSsak(*this);
    }
};

class Ptak : public Zwierze {
    int m_cenaCzarnoRynkowa;
public:
    Ptak(int cena, int cenaCzarnorynkowa, bool zdrowe=true) : Zwierze(cena, zdrowe), m_cenaCzarnoRynkowa(cenaCzarnorynkowa) {}
    virtual void Accept(Visitor* v) {
        v->visitPtak(*this);
    }
};

class Ryba : public Zwierze {
public:
    Ryba(int cena, bool zdrowe=true) : Zwierze(cena, zdrowe) {}
    virtual void Accept(Visitor* v) {
        v->visitRyba(*this);
    }
};

class Gad : public Zwierze {
public:
    Gad(int cena, bool zdrowe=true) : Zwierze(cena, zdrowe) {}
    virtual void Accept(Visitor* v) {
        v->visitGad(*this);
    }
};


class OficjalneCeny : public Visitor{
private:
    int m_sum = 0;
public:
    virtual void visitSsak(const Ssak& el) {
        m_sum += el.getCena();
    }
    virtual void visitPtak(const Ptak& el) {
        m_sum += el.getCena();
    }
    virtual void visitRyba(const Ryba& el) {
        m_sum += el.getCena();
    }
    virtual void visitGad(const Gad& el) {
        m_sum += el.getCena();
    }
    virtual void visitZwierzeta(const std::vector<Zwierze*> &zwierzeta) {
        for(auto z: zwierzeta) {
            z->Accept(this);
        }

        std::cout<<"Oficjalne ceny: "<<m_sum<<std::endl;
    }
};



