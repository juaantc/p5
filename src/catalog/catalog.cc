#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "persons.h"
#include "catalog.h"

bool CyclistCatalog::Load(const std::string& path) {
    Cyclist c;
    std::string name, birth_s, cyclist_id, team;
    int birthyear = 0;

    cyclists_.clear(); // Elimina todos los elementos si hubiera

    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }

    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line); // Define un stream de lectura a partir de line

        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, cyclist_id, ',')) continue;
        if (!std::getline(iss, team)) continue;

        birthyear = std::stoi(birth_s);

        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.SetCyclistId(cyclist_id);
        c.SetTeam(team);

        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}

bool DirectorCatalog::Load(const std::string& path){
    Director d;
    std::string name, birth_s, director_id, team, director_since_s;
    int birthyear = 0, directorsince = 0;
    
    directors_.clear(); // Elimina todos los elementos si hubiera

    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }

    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line); // Define un stream de lectura a partir de line

        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, director_id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, director_since_s)) continue;

        birthyear = std::stoi(birth_s);
        directorsince = std::stoi(director_since_s);

        d.SetName(name);
        d.SetBirthYear(birthyear);
        d.SetUciLicenseId(director_id);
        d.SetTeam(team);
        d.SetDirectorSince(directorsince);
        
        directors_.push_back(d); // se hace una copia al final del vector
    
    }
    return !directors_.empty();
}

std::string CyclistCatalog::GetTeam(std::string cyclist_id){

    for(const auto& c : cyclists_){
        if (c.GetCyclistId() == cyclist_id){
            return c.GetTeam();
        }
    }

return ""; //Devuelve cadena vacía si no encuentra el ID
}

std::vector <Cyclist> CyclistCatalog::GetByTeam(std::string team){

    std::vector <Cyclist> team_cyclists;

    for(const auto& c : cyclists_){
        if(c.GetTeam() == team){
            team_cyclists.push_back(c);
        }
    }

return team_cyclists;
}

std::vector <Cyclist> CyclistCatalog::GetYoungest(){

    std::vector <Cyclist> youngest_cyclists;

    if(cyclists_.empty()){
        return youngest_cyclists; //Devuelve el vector vacío si el catálogo está vacío
    }

    int max_birth_year = 0;

    //El año de nacimiento más alto corresponde al ciclista más joven
    for(const auto& c : cyclists_){
        if(c.GetBirthYear() > max_birth_year){
            max_birth_year = c.GetBirthYear();
        }
    }

    //Recorre de nuevo para encontrar a todos los que tienen esa año
    for(const auto& c : cyclists_){
        if(c.GetBirthYear() == max_birth_year){
            youngest_cyclists.push_back(c);
        }
    }

return youngest_cyclists;
}

void CyclistCatalog::Add(Cyclist c){
    cyclists_.push_back(c);
}