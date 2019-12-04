#pragma once

#include <iostream>

class SzablonZapytania {
public:
    virtual void wykonajZapytanie(const std::string& nazwaBD, const std::string& specZapyt) {
        std::cout<<formatujConnect(nazwaBD)<<"\n"<<formatujSelect(specZapyt)<<"\n";
    }
    virtual std::string formatujConnect(const std::string& nazwaBD) = 0;
    virtual std::string formatujSelect(const std::string& specZapyt) = 0;
};

class ZapytanieSQLServer : public SzablonZapytania {
public:
    virtual std::string formatujConnect(const std::string& nazwaBD) {
        return nazwaBD;
    }
    virtual std::string formatujSelect(const std::string& specZapyt) {
        return specZapyt;
    }
};

class ZapytanieOracle : public SzablonZapytania {
public:
    virtual std::string formatujConnect(const std::string& nazwaBD) {
        return nazwaBD + ";";
    }
    virtual std::string formatujSelect(const std::string& specZapyt) {
        return specZapyt + ";";
    }
};