#include "stage.h"
#include "../persons/persons.h"
#include <vector>
#include <map>
#include <string>
#include <random> 


/* Y para generar cada número sucesivamente llamaremos a: 5 dist(gen)*/
Stage::Stage(int hard){

    if(hard < 1){
        hard_ = 1;
    }
    else if (hard > 5){
        hard_ = 5;
    }
    else{
        hard_ = hard;
    }
}

void Stage::Simulate(const std::vector <Cyclist>& cyclist){

    delay_.clear();  //Limpio los resultados previos

    if(cyclist.empty()){  //Si no hay ciclistas, no hay nada que simular
        return;
    }

    //Defino el retraso máximo para los no ganadores
    const int max_delay = hard_ * 400;

    //=== Configuración del generador aleatorio ===
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(0, max_delay);

    // Elegir un ganador aleatoriamente 
    // Se crea una distribución para elegir un índice del vector
    std::uniform_int_distribution<int> winner_dist(0, cyclist.size()-1);
    int winner_index = winner_dist(gen); //Indice del ganador

    //Recorro el vector de ciclistas para asignar delays
    for(int i = 0; i < cyclist.size(); i++){
        const Cyclist& c = cyclist[i];
        int delay = 0;
    
        if(i != winner_index){
            // Se crea una distribución para el resto
            std::uniform_int_distribution<int> delay_dist(1, max_delay);
            delay = delay_dist(gen);   // No es el ganador, se le asigna un delay aleatorio
        }
        
        delay_[c.GetCyclistId()] = delay;
    }
}