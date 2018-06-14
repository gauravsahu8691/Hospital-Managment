#ifndef PATIENT_INFO_H
#define PATIENT_INFO_H

#include <iostream>
#include <string>

class Patient_info {

    private:
            std::string  pId;
            std::string  address;
            std::string  dDescription;
            int          age;
            char         sex;
    protected:
            static int   roomNo;
            int          room;
            std::string  name;
            std::string  service;

            void    putPatientId(std::string);
            void    putAddress(std::string);
            void    putAge(int);
            void    putSex(char);
            void    putDescription(std::string);
            void    putName(std::string);
            void    putServiceProvided(std::string);
    public:


            std::string  getPatientName(){ return this->name; };
            int     getPatientRoomNo(){ return this->room; };
            char    getPatientSex(){ return  this->sex; };
            int     getPatientAge(){ return this->age; };
            void    newPatient();
            void    showPatientRecord();
};

int Patient_info::roomNo = 1;

void Patient_info::putPatientId(std::string pId) {this->pId = pId;}

void Patient_info::putAddress(std::string address) {this->address = address;}

void Patient_info::putAge(int age) {this->age = age;}

void Patient_info::putSex(char sex) {this->sex = sex;}

void Patient_info::putDescription(std::string dDescription) {this->dDescription = dDescription;}

void Patient_info::putName(std::string name) {this->name = name;}

void Patient_info::putServiceProvided(std::string service) {this->service = service;}


void Patient_info::newPatient() {

    std::string  name;
    std::string  service;
    std::string  address;
    int     age;
    char    sex;
    std::string  pId;
    std::string  dDescription;

    try {
        std::cin.ignore(1);
        std::cout<<"Enter Name                 : ";
            getline(std::cin, name);
            //if (name.size() < 3)    throw "Name Too Short";
           // if (isnum(name))        throw "Name cannot be a Number";

        std::cout<<"Enter Patient Id           : ";
            getline(std::cin, pId);
            //if (pId.size() != 8)    throw "Please Enter Valid Patient Id";

        std::cout<<"Enter Age                  : ";
            std::cin>>age;
            //if (age > 90)           throw "Patient Age Above 90 is not allowed";

        std::cout<<"Enter Sex(M/F/O)           : ";
            std::cin>>sex;
            //if (toupper(sex) != 'M' || toupper(sex) != 'F' || toupper(sex) != 'O') throw "Invalid Entry";

        std::cin.ignore(1);
        std::cout<<"Enter Disease Description  : ";
            getline(std::cin, dDescription);
            //if (dDescription.size() < 10)   throw "Please Describe the Problem properly";

        std::cout<<"Enter address              : ";
            getline(std::cin, address);
            //if (address.size() > 5)         throw "Please provide full address";

        std::cout<<"Enter Service                 : ";
            getline(std::cin, service);
            //if(toupper(service)!="EMERGENCY" || toupper(service)!="GENRAL") throw "Please Enter Valid SERVICE";

        this->room = roomNo;
        std::cout<<"Room : "<<room<<std::endl;
        std::cout<<"Room No. : "<<roomNo;

    }catch(const std::string msg) {
        std::cout<<msg;
        return;
    }

    roomNo++;

    putAddress(address);
    putAge(age);
    putDescription(dDescription);
    putName(name);
    putPatientId(pId);
    putServiceProvided(service);
    putSex(sex);
}

void Patient_info::showPatientRecord() {

    std::cout<<"Patient Name        :   "<<this->name<<std::endl;
    //std::cout<<"Patient Room Number :   "<<this->roomNo<<std::endl;

    if (this->service == "EMERGENCY")
        std::cout<<"Patient is in Emergency Ward";
    else
        std::cout<<"Patient is in Genral Ward";
}


#endif // PATIENT_INFO_H

