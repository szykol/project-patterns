#pragma once

class Singleton {
    static Singleton* instance;
    Singleton();
public:
    static Singleton* getInstance();
};