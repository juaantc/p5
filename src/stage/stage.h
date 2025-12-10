#ifndef STAGE_H
#define STAGE_H

#include "../persons/persons.h"
#include <vector>
#include <map>
#include <string>

class Stage{

    private:
            std::map <std::string,int> delay_;
            int hard_;
    
    public:
            void Simulate(const std::vector <Cyclist>& cyclist);
            Stage(int hard);
            int GetHard() const {return hard_;}
            std::map <std::string,int> GetDelays() const {return delay_;}

};

#endif