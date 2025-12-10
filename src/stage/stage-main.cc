#include "stage.h"
#include "catalog.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(){

    CyclistCatalog cc;

    if(cc.Load("../data/cyclists.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de ciclistas" << std::endl;
        return 1;
    }

    std::cout << "Catalogo de Ciclistas cargado: " << std::endl;
    std::vector <Cyclist> vec_cyclist = cc.Data();

    if(vec_cyclist.empty()){
        std::cout << "ERROR: no se pudo cargar los ciclistas" << std::endl;
        return 1;
    }

    //=== Simulación de la etapa  ===

    int dureza_etapa = 3;
    /*std::cout << "Introduce la dureza de la etapa: " << std::endl;
    std::cin >> dureza_etapa;
    std::cin.ignore();

    if(dureza_etapa < 1 || dureza_etapa > 5){
        std::cout << "ERROR, la dureza solo permite valores enteros entre el 1 y el 5" << std::endl;
        return 1;
    }*/

    std::cout << "Simulando etapa con dureza " << dureza_etapa << "..." << std::endl;

    //1. Crear un objeto Stage
    Stage etapa(dureza_etapa);

    //2. Simular la etapa con el vector de ciclistas
    etapa.Simulate(vec_cyclist);

    //3. Obtener el mapa de resultados (retrasos)
    std::map <std::string,int> resultados = etapa.GetDelays();

    //4. Mostrar resultados en pantalla
    std::cout << "=== Resultados de la Etapa (Dureza: " << etapa.GetHard() << ") ===" << std::endl;
    std::cout << "Nombre, ID, Delay(s)" << std::endl;

    //Recorremos el mapa de resultados
    for(const auto& r : resultados){

        std::string cyclist_id = r.first;
        int delay = r.second;
        std::string cyclist_name = "UNKNOWN";

        // Buscamos el nombre del ciclista en el vector original usando su ID
        for(const auto& c : vec_cyclist){
            if(c.GetCyclistId() == cyclist_id){
                cyclist_name = c.GetName();
                break; // Encontrado, salimos del bucle interior
            }
        }

        std::cout << cyclist_name << "," << cyclist_id << "," << delay << std::endl;
    }

    std::cout << "=== PROGRAMA FINALIZADO ===" << std::endl;

return 0;
}
