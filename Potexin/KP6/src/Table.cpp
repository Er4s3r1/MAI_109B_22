#include "../include/Table.hpp"

Table::Table(){
    this->columns = Vector<std::string>{"surname", "initials", "baggage amount", 
                                        "baggage weight", "destination", "time", 
                                        "transfer", "kids"};
}

Table::Table(const Vector<std::string>& names){
    this->columns = names;
}
