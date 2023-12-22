//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_PATIENT_H
#define HOSPITAL_QUEUING_SYSTEM_PATIENT_H
#include "Tool.h"

class Patient {
private:
    string name;
    int age;
    string id;
public:
    Patient(string,int,string);
    Patient();
    friend ostream & operator<<(ostream &,Patient const &);
    friend Patient inputPatient();
};

Patient inputPatient();

#endif //HOSPITAL_QUEUING_SYSTEM_PATIENT_H
