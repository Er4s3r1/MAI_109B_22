#pragma once
#include <string>
#include "../../KP7/include/Vector.hpp"

class DataBase;

class Table{
friend class DataBase;
public:
    Table();
    Table(const Vector<std::string>&);
private:
    Vector<std::string> columns;
    Vector<Vector<std::string>> table;
};

#include "../src/Table.cpp"
