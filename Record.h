//
// Created by 沈嘉瑞 on 2023.10.16.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_RECORD_H
#define HOSPITAL_QUEUING_SYSTEM_RECORD_H
#include "Patient.h"

class Record {
private:
    Patient patient;
    int num;
public:
    Record(Patient,int);
    Record(){};
    int getNum();
    Patient getPatient();
};


#endif //HOSPITAL_QUEUING_SYSTEM_RECORD_H
