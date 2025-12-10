#ifndef PERSONS_H
#define PERSONS_H

#include <string>

class Person{

    private:
            std::string name_;
            int birth_year_;

    public:
            Person();
            Person(std::string name, int birth_year);
            
            std::string GetName()const {return name_;}
            int GetBirthYear()const {return birth_year_;}

            void SetName(std::string name){name_ = name;};
            void SetBirthYear(int birth_year){birth_year_ = birth_year;};

};

class Cyclist:public Person{

    private:
            std::string team_;
            std::string cyclist_id_;

    public:
            Cyclist();
            Cyclist(std::string name, int birth_year, std::string team, std::string cyclist_id); /////

            std::string GetTeam()const {return team_;}
            std::string GetCyclistId()const {return cyclist_id_;}

            void SetTeam(std::string team){team_ = team;};
            void SetCyclistId(std::string cyclist_id){cyclist_id_ = cyclist_id;};

};

class Director:public Person{

    private:
            std::string team_;
            std::string uci_license_id_;
            int director_since_;
    
    public:
            Director();
            Director(std::string name, int birth_year, std::string team, std::string uci_license_id, int director_since); ///////

            std::string GetTeam()const {return team_;}
            std::string GetUciLicenseId()const {return uci_license_id_;}
            int GetDirectorSince()const {return director_since_;}

            void SetTeam(std::string team){team_ = team;};
            void SetUciLicenseId(std::string uci_license_id){uci_license_id_ = uci_license_id;};
            void SetDirectorSince(int director_since){director_since_ = director_since;};

};

#endif