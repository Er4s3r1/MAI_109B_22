#include "../include/DataBase.hpp"

double abs(double x){
    if(x >= 0) return x;
    return -x;
}

DataBase::DataBase(): DataBase("DataBase"){}

DataBase::DataBase(const std::string& name){
    this->name = name;

    if(std::filesystem::exists(this->name)){
        this->Read();
    }
    else{
        this->CreateTable();
        this->Save();
    }
}

void DataBase::CreateTable(){
    this->tables.emplace_back();
}

void DataBase::Read(){
    std::ifstream file;
    file.open(this->name);

    size_t size;
    file >> size;
    
    for(size_t currentTable = 0; currentTable < size; ++currentTable){
        size_t rows;
        size_t collumns;
        file >> rows >> collumns;

        Vector<std::string> names(collumns);
        for(size_t currentCollumn = 0; currentCollumn < collumns; ++currentCollumn){
            file >> names[currentCollumn];
        }
        this->tables.emplace_back(names);

        for(size_t currentRow = 0; currentRow < rows; ++currentRow){
            this->tables[currentTable].table.emplace_back(collumns, "None");
            for(size_t currentColumn = 0; currentColumn < collumns; ++currentColumn){
                file >> this->tables[currentTable].table[currentRow][currentColumn];
            }
        }
        
    }
    file.close();
}

void DataBase::Save(){
    std::ofstream file;
    file.open(this->name);

    file << this->tables.size() << ' ';

    for(size_t currentTable = 0; currentTable < this->tables.size(); ++currentTable){
        file << this->tables[currentTable].table.size() << ' ' << this->tables[currentTable].columns.size() << ' ';

        for(size_t currentColumn = 0; currentColumn < this->tables[currentTable].columns.size(); ++currentColumn){
                file << this->tables[currentTable].columns[currentColumn] << ' ';
        }

        for(size_t currentRow = 0; currentRow < this->tables[currentTable].table.size(); ++currentRow){
            for(size_t currentColumn = 0; currentColumn < this->tables[currentTable].columns.size(); ++currentColumn){
                file << this->tables[currentTable].table[currentRow][currentColumn] << ' ';
            }
        }
    }

    file.close();
}

void DataBase::Print(size_t index) const{
    for(size_t currentCollumn = 0; currentCollumn < this->tables[index].columns.size(); ++currentCollumn){
        std::cout << this->tables[index].columns[currentCollumn] << ' ';
    }
    std::cout << std::endl;

    for(size_t currentRow = 0; currentRow < this->tables[index].table.size(); ++currentRow){
        for(size_t currentColumn = 0; currentColumn < this->tables[index].columns.size(); ++currentColumn){
            std::cout << this->tables[index].table[currentRow][currentColumn] << ' ';
        }
        std::cout << std::endl;
    }

}

void DataBase::FindPassenger(size_t p) const{
    Vector<std::string> courses;
    Vector<double> weghts;
    Vector<int64_t> amount;
    if(this->tables[0].table.size() > 0){
        courses.push_back(this->tables[0].table[0][4]);
        weghts.push_back(std::stod(this->tables[0].table[0][3]));
        amount.push_back(1);
    }

    for(size_t currentRow = 1; currentRow < this->tables[0].table.size(); ++currentRow){
        size_t currentDestination = 0;
        while(currentDestination < courses.size()){
            if(courses[currentDestination] == this->tables[0].table[currentRow][4]){
                weghts[currentDestination] += std::stod(this->tables[0].table[currentRow][3]);
                ++amount[currentDestination];
                break;
            }
            ++currentDestination;
        }
        if(currentDestination >= courses.size()){
            courses.push_back(this->tables[0].table[currentRow][4]);
            weghts.push_back(std::stod(this->tables[0].table[currentRow][3]));
            amount.push_back(1);
        }
    }

    for(size_t currentRow = 0; currentRow < this->tables[0].table.size(); ++currentRow){
        size_t currentDestination = 0;
        while(currentDestination < courses.size()){
            if(abs(std::stod(this->tables[0].table[currentRow][3]) - weghts[currentDestination]/amount[currentDestination]) > p){
                break;
            }
            ++currentDestination;
        }
        if(currentDestination >= courses.size()){
            std::cout << this->tables[0].table[currentRow][0] << this->tables[0].table[currentRow][1] << std::endl;
            return;
        }
    }
    std::cout << "None" << std::endl;
}

DataBase::~DataBase(){
    this->Save();
}
