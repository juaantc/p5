#ifndef GCLIST_H
#define GCLIST_H

#include "../persons/persons.h"
#include "../stage/stage.h"
#include "../catalog/catalog.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>

// Estructura para cada entrada en la Clasificación General
struct GCEntry{
    const Cyclist* cyclist_ptr;
    int total_delay;
};

// Comparador estático para ordenar la lista por total_delay (el menor primero)
// Se usará con std::list::sort()
static bool CompareGCEntries(const GCEntry& a, const GCEntry& b){
    return a.total_delay < b.total_delay;
}

class GCList{

    private:
            std::list <GCEntry> gc_;
    
    public:
            GCList(CyclistCatalog& catalog);
            void ApplyStage(const Stage& stage);
            std::size_t Size() {return gc_.size();}
            std::string GetClassification(int num);
            const std::list <GCEntry>& GetClassification() {return gc_;}

};

#endif