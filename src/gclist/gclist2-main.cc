#include "gclist.h"
#include "stage.h"
#include "catalog.h"
#include "persons.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

/*Función auxiliar para mostrar los delays (ya que Stage no tiene un método DisplayDelays)
Muestra el id de cada ciclista y su delay en esa etap*/
void DisplayStageDelays(const Stage& s){
    const std::map <std::string,int> delays = s.GetDelays();

    for(const auto& pair : delays){
        std::cout << " ID: " << pair.first << ", Delay: " << pair.second << "s\n" << std::endl;
    }
}


int main(){

    CyclistCatalog catalog;

    if(catalog.Load("../data/cyclists.csv") == false){

        std::cout << "ERROR: no se pudo cargar el archivo de ciclistas" << std::endl;
        return 1;
    }

    std::cout << "Catalogo de ciclistas cargado desde CSV. Total: " << catalog.Size() << "ciclistas.\n" << std::endl;

    Stage s1(2);
    s1.Simulate(catalog.Data());

    std::cout << "\n=== Etapa 1 (s1) === Con Dureza " << s1.GetHard() << "===" << std::endl;
    std::cout << "Retrasos de la etapa 1:\n" << std::endl;
    DisplayStageDelays(s1);

    GCList gc(catalog);
    gc.ApplyStage(s1);
    std::cout << "Etapa 1 aplicada a la Clasificación General.\n" << std::endl;

    Stage s2(4);
    s2.Simulate(catalog.Data());

    std::cout << "\n=== Etapa 2 (s2) === Con Dureza " << s2.GetHard() << "===" << std::endl;
    std::cout << "Retrasos de la etapa 2:\n" << std::endl;
    DisplayStageDelays(s2);
    
    gc.ApplyStage(s2);
    std::cout << "Etapa 2 aplicada a la Clasificación General.\n" << std::endl;

    std::cout << "=== Clasificación General (Top 10) ===" << std::endl;
    std::cout << gc.GetClassification(10);

    return 0;
}