#include <iostream>
#include <conio.h>
#include <fstream>
#include "Patient_info.h"


struct patientTempData {

    std::string  name;
    int     age;
    int     roomNo;
    char    sex;
};

struct patientTempData  searchByRoomNo(int);
struct patientTempData  searchByName(std::string);
void  Options();
// TODO (user#1#06/12/18): Add Login Feature on Delete patient account option

int main(void) {

    int choice;
    Patient_info  patient;
    std::ofstream  patientInfo;

    std::cout<<"Press Any Key : ";
    while (true) {

        Options();
main_menu:
        std::cin>>choice;
        switch(choice) {

            case 1:
                patientInfo.open("PatientData.dat", std::ios::app);
                patient.newPatient();
                patientInfo.write((char*)&patient, sizeof(patient));
                patientInfo.close();
                break;
            case 2:
                {
                    short ch;
                    std::cout<<"Enter\n1>Search by Room Number\n2>Search by Name\n3>GO BACK\n";
                        std::cin>>ch;
                    switch (ch) {

                    case 1:
                        {
                            int roomNo;
                            std::cout<<"Enter Room Number : ";
                                std::cin>>roomNo;
                            patientTempData tempData = searchByRoomNo(roomNo);
                            if (tempData.name == " ")
                                std::cout<<"No Record Found";
                            else {
                                std::cout<<"Room Number       :  "<<tempData.roomNo<<std::endl;
                                std::cout<<"Sex               :  "<<tempData.sex<<std::endl;
                                std::cout<<"Name              :  "<<tempData.name<<std::endl;
                                std::cout<<"Age               :  "<<tempData.age<<std::endl;
                            }
                        }
                        break;
                    case 2:
                        {
                            struct patientTempData  tempData;
                            std::string name;
                            std::cin.ignore(1);
                            std::cout<<"Enter Patient Name : ";
                                getline(std::cin, name);
                            tempData = searchByName(name);
                            if (tempData.name == " ")
                                std::cout<<"No Record Found";
                            else{
                                std::cout<<"Name           :  "<<tempData.name<<std::endl;
                                std::cout<<"Age            :  "<<tempData.age<<std::endl;
                                std::cout<<"Room Number    :  "<<tempData.roomNo<<std::endl;
                                std::cout<<"Sex            :  "<<tempData.sex<<std::endl;
                            }
                        }
                        break;
                    case 3:
                        goto main_menu;
                    default:
                        std::cout<<"In-valid Entry";
                    }
                }
                break;
            case 5:
                exit(0);
        }
    }
}

void    Options() {

    getch();
    system("cls");
    std::cout<<"Enter\n1>New Patient\n2>Search Patient\n3>Patient Record"<<std::endl;
    std::cout<<"4>Delete Patient Record\n5>Exit"<<std::endl;
}

struct patientTempData  searchByRoomNo(int roomNo) {

    patientTempData  info; // TO Store Name, Age and Sex of the Patient
    std::ifstream  tempFile;
    tempFile.open("PatientData.dat", std::ios::in);
    Patient_info  patientData;

    while (!tempFile.eof()) {

        tempFile.read((char*)&patientData, sizeof(patientData));

        if (patientData.getPatientRoomNo() == roomNo){
            info.name = patientData.getPatientName();
            info.age = patientData.getPatientAge();
            info.sex = patientData.getPatientSex();
            info.roomNo = roomNo;
            tempFile.close();
            return info; // End of Function
        }
    }

    tempFile.close();
    info.age = 0;
    info.roomNo = 0;
    info.sex = '$';
    info.name = " ";
    return info;
}

struct patientTempData  searchByName(std::string name) {

    patientTempData  info; // TO Store Name, Age and Sex of the Patient
    std::ifstream  tempFile;
    tempFile.open("PatientData.dat", std::ios::in);
    Patient_info  patientData;

    while (!tempFile.eof()) {

        tempFile.read((char*)&patientData, sizeof(patientData));

        if (patientData.getPatientName() == name){
            info.name = name;
            info.age = patientData.getPatientAge();
            info.sex = patientData.getPatientSex();
            info.roomNo = patientData.getPatientRoomNo();
            tempFile.close();
            return info; // End of Function
        }
    }

    tempFile.close();
    info.age = 0;
    info.roomNo = 0;
    info.sex = '$';
    info.name = " ";
    return info;
}
