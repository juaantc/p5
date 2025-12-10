#include "gclist.h"
#include <algorithm>
#include <sstream>

/*Recibe un catálogo, itera sobre sus datos y crea una entrada
para cada ciclista con delay inicial de 0*/
GCList::GCList(CyclistCatalog& catalog){

    for(const auto& c : catalog.Data()){
        GCEntry entry;

        // Asigna la dirección del ciclista del catálogo
        entry.cyclist_ptr = &c;
        entry.total_delay = 0; // Delay inicial de 0
        gc_.push_back(entry);
    }
}

void GCList::ApplyStage(const Stage& stage){

    /* Obtenemos una copia (o referencia constante si fuera posible, pero 
    es más simple copiar o manejar) del mapa de retrasos de la etapa.*/
    const std::map <std::string,int> stage_delays = stage.GetDelays();

    // 1. Actualiza el delay total de cada corredor
    for(auto& entry : gc_){
        std::string cyclist_id = entry.cyclist_ptr->GetCyclistId();

        // Buscar el delay del ciclista en el mapa de la etapa
        auto it = stage_delays.find(cyclist_id);

        int stage_delay = 0;
        if(it != stage_delays.end()){
            stage_delay = it->second; // Obtener el delay si el ID está presente
        }

        // Suma el delay de la etapa al delay total
        entry.total_delay += stage_delay;
    }

    // 2. Ordena la lista de menor a mayor delay
    gc_.sort(CompareGCEntries);
}

std::string GCList::GetClassification(int num){
    int position = 1;
    std::stringstream ss;

    // Iteramos sobre la lista, pero solo hasta el número 'num'
    for(auto& entry : gc_){
        if(position > num){
            break;
        }
        else{
            ss << position << ". "
            << entry.cyclist_ptr->GetName() << "," 
            << entry.cyclist_ptr->GetCyclistId() << ","
            << entry.total_delay << "\n";

            position++;
        }

    }

    return ss.str(); //Se devuelve el contenido acumulado como un único std::string
}