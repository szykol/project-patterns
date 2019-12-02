#pragma once

#include <iostream>

enum class SQLType {SQLServer, Oracle};

class BazaDanych {
public:
    virtual std::string formatujConnect(const std::string& nazwaBD) = 0;
    virtual std::string formatujSelect(const std::string& specZapyt) = 0;
};


class ZapytanieSQLServer : public BazaDanych {
public:
    virtual std::string formatujConnect(const std::string& nazwaBD) {
        return nazwaBD;
    }
    virtual std::string formatujSelect(const std::string& specZapyt) {
        return specZapyt;
    }
};

class ZapytanieOracle : public BazaDanych {
public:
    virtual std::string formatujConnect(const std::string& nazwaBD) {
        return nazwaBD + ";";
    }
    virtual std::string formatujSelect(const std::string& specZapyt) {
        return specZapyt + ";";
    }
};

class SzablonZapytania {
public:
    virtual void wykonajZapytanie(const std::string& nazwaBD, const std::string& specZapyt, BazaDanych* BD) {
        std::cout<<BD->formatujConnect(nazwaBD)<<"\n"<<BD->formatujSelect(specZapyt)<<"\n";
    }
    BazaDanych* utworzBD(SQLType type) {
        if (type == SQLType::SQLServer) {
            return new ZapytanieSQLServer();
        } else {
            return new ZapytanieOracle();
        }
    }
};
