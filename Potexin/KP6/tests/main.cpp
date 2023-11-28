#include "../include/DataBase.hpp"

int main(){

    DataBase database("ok");
    database.Print(0);
    database.FindPassenger(5);

    return 0;
}
