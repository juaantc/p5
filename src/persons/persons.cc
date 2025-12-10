#include "persons.h"
#include <string> 

Person::Person(){
    name_ = "UNKNOWN";
    birth_year_ = -1;
}

Person::Person(std::string name, int birth_year){
    name_ = name;
    birth_year_ = birth_year;
}

Cyclist::Cyclist(){
    team_ = "UNKNOWN";
    cyclist_id_ = "UNKNOWN";
}

Cyclist::Cyclist(std::string name, int birth_year, std::string team, std::string cyclist_id)
    :Person(name, birth_year){

        team_ = team;
        cyclist_id_ = cyclist_id;
}

Director::Director(){
    team_ = "UNKNOWN";
    uci_license_id_ = "UNKNOWN";
    director_since_ = -1;
}

Director::Director(std::string name, int birth_year, std::string team, std::string uci_license_id, int director_since)
    :Person(name, birth_year){
        team_ = team;
        uci_license_id_ = uci_license_id;
        director_since_ = director_since;
}
