#include "catalog.h"
#include <iostream>

int main(){

//Creación de objetos

    CyclistCatalog cc;
    DirectorCatalog dc;

//======================================================

std::cout << "Carga de los archivos cyclists.csv y directors.csv: " << std::endl;

//Apartado para CYCLISTCATALOG

    if(cc.Load("../data/cyclists.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de ciclistas" << std::endl;
        return 1;
    }

//======================================================

//Apartado para DIRECTORCATALOG

    if(dc.Load("../data/directors.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de directores" << std::endl;
        return 1;
    }

//======================================================

//Apartado para IMPRIMIR ambos FICHEROS.CSV

    std::cout << "=== Se cargaron los archivos .csv ===" << std::endl;

    std::cout << "Catalogo de Ciclistas cargado: " << std::endl;
    std::vector <Cyclist> vec_cyclist = cc.Data();

    //Recorro cyclist.csv con un bucle for

    for(size_t i = 0; i < vec_cyclist.size(); i++){

        std::cout << "Ciclista " << i+1 << ". "
                  << vec_cyclist[i].GetName() << ", nacido el " << vec_cyclist[i].GetBirthYear() << ", es miembro de "
                  << vec_cyclist[i].GetTeam() << " y su id de ciclista es " << vec_cyclist[i].GetCyclistId() << std::endl;
        
    }

    std::cout << "Catalogo de Directores cargado: " << std::endl;
    std::vector <Director> vec_directors = dc.Data();

    //Recorro directors.csv con un auto range for

    for(auto &f: vec_directors){

        std::cout << "Director llamado " << f.GetName() << ", nacido el " << f.GetBirthYear() 
        << ", con direccion en " << f.GetTeam() << ", su id de licencia UCI es " << f.GetUciLicenseId() 
        << " y lleva siendo director desde " << f.GetDirectorSince() << std::endl;
           
    }

//======================================================

//Apartado para las NUEVAS PETICIONES que se solicita en PRACTICA 3

    //Conocer ciclistas de un equipo pedido

std::cout << " === CONSULTAS ADICIONALES === " << std::endl;
std::cout << "Introduce el nombre de un equipo para conocer todos sus ciclistas:  " << std::endl;

std::string team_name;

std::getline(std::cin, team_name);

std::vector <Cyclist> team_members = cc.GetByTeam(team_name);

if(team_members.empty()){
    std::cout << "No se encontraron ciclistas en el equipo" << team_name << std::endl;

} else{ 
        std::cout << "Ciclistas del equipo" << team_name << ": " << std::endl;
        for(const auto& c : team_members){
            std::cout << "- " << c.GetName() << ", ID: " << c.GetCyclistId() << ", nacido el " << c.GetBirthYear() << std::endl;
        }
}

    //Ciclistas más jovenes

std::vector <Cyclist> youngests_cyclists = cc.GetYoungest();

if(youngests_cyclists.empty()){
    std::cout << "El catalogo de ciclistas esta vacio"<< std::endl;

} else{ 
        std::cout << "El(Los) ciclista(s) de menor edad nacido(s) en"<< youngests_cyclists[0].GetBirthYear() <<"es(son): " << std::endl;
        for(const auto& c : youngests_cyclists){
            std::cout << "- " << c.GetName() << ", componente de "<< c.GetTeam() << "y con ID: " << c.GetCyclistId() << std::endl;
        }
}

//======================================================

std::cout << "----- PROGRAMA FINALIZADO -----";
return 0;

}
