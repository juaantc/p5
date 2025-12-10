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

    Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
    Cyclist c2{"Xabier Mikel Azparren", 1999, "Q36.5 Pro Cycling Team", "d1a1b002"};
    Cyclist c3{"Enekoitz Azparren", 2002, "Q36.5 Pro Cycling Team", "d1a1b003"};
    Cyclist c4{"Marcel Camprubí", 2001, "Q36.5 Pro Cycling Team", "d1a1b004"};
    Cyclist c5{"Damien Howson", 1992, "Q36.5 Pro Cycling Team", "d1a1b005"};

    catalog.Add(c1);
    catalog.Add(c2);
    catalog.Add(c3);
    catalog.Add(c4);
    catalog.Add(c5);

    Cyclist c6{"Ibai Llanos", 2004, "Audi Cycling Team", "d1x1b069"};
    Cyclist c7{"David Canovas", 2006, "Audi Cycling Team", "d1z1b666"};

    catalog.Add(c6);
    catalog.Add(c7);

    std::cout << "Catalogo de ciclistas creado. Total: " << catalog.Size() << "ciclistas.\n" << std::endl;

    Stage s1(3);
    s1.Simulate(catalog.Data());

    std::cout << "\n=== Etapa 1 (s1) === Con Dureza " << s1.GetHard() << "===" << std::endl;
    std::cout << "Retrasos de la etapa 1:\n" << std::endl;
    DisplayStageDelays(s1);

    GCList gc(catalog);
    gc.ApplyStage(s1);
    std::cout << "Etapa 1 aplicada a la Clasificación General.\n" << std::endl;

    Stage s2(5);
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