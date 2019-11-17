#pragma once

class Singleton {
    static Singleton* instance;
public:
    Singleton();
    ~Singleton();
    Singleton* getInstance();
};