#pragma once
#include "Table.hpp"
#include <string>
#include <fstream>
#include <filesystem>

class DataBase{
public:
    DataBase();
    DataBase(const std::string&);

    void CreateTable();
    void Read();
    void Save();

    void Print(size_t) const;

    void FindPassenger(size_t) const;

    ~DataBase();

private:
    std::string name;
    Vector<Table> tables;
};

#include "../src/DataBase.cpp"
