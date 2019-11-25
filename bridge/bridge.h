#pragma once

#include <iostream>

class Biblioteka {
public:
    virtual void rysujLinie() = 0;
    virtual void rysujOkrag() = 0; 
};

class BG1 {
public:
    void rysuj_linie() {
        std::cout<<"Rysuję linię/ za pomocą biblioteki graficznej BG1/\n";
    }
    void rysuj_okrag() {
        std::cout<<"Rysuję /okrąg za pomocą biblioteki graficznej BG1/\n";
    }
};

class BG2 {
public:
    void narysujLinie() {
        std::cout<<"Rysuję linię/ za pomocą biblioteki graficznej /BG2\n";
    }

    void narysujOkrag() {
        std::cout<<"Rysuję /okrąg za pomocą biblioteki graficznej /BG2\n";
    }
};

class BibliotekaV1 : public Biblioteka, private BG1{
public:
    virtual void rysujLinie() {
        rysuj_linie();
    }
    virtual void rysujOkrag() {
        rysuj_okrag();
    }
};

class BibliotekaV2 : public Biblioteka, private BG2 {
public:
    virtual void rysujLinie() {
        narysujLinie();
    }
    virtual void rysujOkrag() {
        narysujOkrag();
    }
};

class Figura {
protected:
    Biblioteka& bibl;
public:
    Figura(Biblioteka& b) : bibl(b) {}
    virtual void rysuj() = 0;
};

class Okrag : public Figura {
public:
    Okrag(Biblioteka& b) : Figura(b) {}
    virtual void rysuj() {bibl.rysujOkrag();}
};

class Linia : public Figura {
public:
    Linia(Biblioteka& b) : Figura(b) {}
    virtual void rysuj() {bibl.rysujLinie();}
};