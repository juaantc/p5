#include "persons.h"
#include <string>
#include <iostream>

int main(){

//Creación de objetos para cada clase
    Person p;
    Cyclist c;
    Director d;
//===========================================================

//Creación de variables
    std::string name, team, cyclistid, ucilicenseid;
    int birthyear, directorsince;
//===========================================================

//Apartado para la clase PERSON
    std::cout << "=== SISTEMA DE REGISTROS DE PERSONAS ===" << std::endl;

    std::cout << "Introduce el Nombre: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Introduce el Ano de Nacimiento: " << std::endl;
    std::cin >> birthyear;
    std::cin.ignore();

    p.SetName(name);
    p.SetBirthYear(birthyear);
//===========================================================

//Apartado para la clase CYCLIST
    std::cout << "=== SISTEMA DE REGISTROS DE CICLISTAS ===" << std::endl;

    std::cout << "Introduce el Nombre: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Introduce el Ano de Nacimiento: " << std::endl;
    std::cin >> birthyear;
    std::cin.ignore();

    std::cout << "Introduce el Equipo: " << std::endl;
    std::getline(std::cin, team);

    std::cout << "Introduce el Id de ciclista: " << std::endl;
    std::getline(std::cin, cyclistid);

    c = Cyclist(name, birthyear, team, cyclistid);
//===========================================================

//Apartado para la clase DIRECTOR
    std::cout << "=== SISTEMA DE REGISTROS DE DIRECTORES ===" << std::endl;

    std::cout << "Introduce el Nombre: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Introduce el Ano de Nacimiento: " << std::endl;
    std::cin >> birthyear;
    std::cin.ignore();

    std::cout << "Introduce el Equipo: " << std::endl;
    std::getline(std::cin, team);

    std::cout << "Introduce el Id de licensia UCI: " << std::endl;
    std::getline(std::cin, ucilicenseid);

    std::cout << "Introduce el Ano de comienzo de director: " << std::endl;
    std::cin >> directorsince;
    std::cin.ignore();

    d = Director(name, birthyear, team, ucilicenseid, directorsince);
//===========================================================

//Apartado para mostrar RESULTADOS
    std::cout << "=== RESULTADOS ===" <<std::endl;

    std::cout << "Person -> " << p.GetName() << " (" << p.GetBirthYear() << ") " << std::endl;

    std::cout << "Cyclist -> " << c.GetName() << ", " << c.GetBirthYear() << ", " <<  c.GetTeam() << ", " << c.GetCyclistId() << std::endl;

    std::cout << "Director -> " << d.GetName() << ", " << d.GetBirthYear() << ", " <<  d.GetTeam() << ", " << d.GetUciLicenseId() << ", " << ", since " << d.GetDirectorSince() << std::endl;
//==========================================================

return 0;

}