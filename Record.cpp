//
// Created by 沈嘉瑞 on 2023.10.16.
//

#include "Record.h"

//构造函数
Record::Record(Patient p, int n) {
    patient = p;
    num = n;
}

//返回排名
int Record::getNum() {
    return num;
}

//返回病人
Patient Record::getPatient() {
    return patient;
}