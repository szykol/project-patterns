#pragma once

#include <iostream>
#include <memory>

class FileState {
public:
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Read() = 0;
    virtual void Write() = 0;
};

class FileOpened : public FileState{
public:
    virtual void Open() {
        std::cout<<"Otwieram plik\n";
    }
    virtual void Close() {
        std::cout<<"Zamykam plik\n";
    }
    virtual void Read() {
        std::cout<<"Czytam plik\n";
    }
    virtual void Write() {
        std::cout<<"Pisze do pliku\n";
    }
};

class FileClosed : public FileState {
public:
    virtual void Open() {
        std::cout<<"Otwieram plik\n";
    }
    virtual void Close() {
        std::cout<<"Plik juz zamkniety\n";
    }
    virtual void Read() {
        std::cout<<"Plik zamkniety | Odczyt niemozliwy\n";
    }
    virtual void Write() {
        std::cout<<"Plik zamkniety | Zapis niemozliwy\n";
    }
};

class File {
private:
    std::unique_ptr<FileState> m_state = std::make_unique<FileClosed>();
public:
    void Open() {
        m_state->Open();
        m_state = std::make_unique<FileOpened>();
    }
    void Close() {
        m_state->Close();
        m_state = std::make_unique<FileClosed>();
    }
    void Read() {
        m_state->Read();
    }
    void Write() {
        m_state->Write();
    }
};