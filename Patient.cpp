//
// Created by 沈嘉瑞 on 2023.10.15.
//

#include "Patient.h"

//构造函数
Patient::Patient(string n, int a, string i):name(n),age(a),id(i) {}

Patient::Patient():name(""),age(20),id("000000000000000000"){}
//输出重载
ostream & operator<<(ostream & out,Patient const & p){
    return out<<"姓名:"<<p.name<<"\n年龄:"<<p.age<<"\n身份证号:"<<p.id;
}

//输入重载
Patient inputPatient(){
    Patient p;
    cout<<"请输入姓名:";
    p.name = inputString();
    cout<<"请输入年龄:";
    int a = inputInt();
    if (a<=0 || a>=150){
        throw NumberException("年龄范围错误，输入失败。");
    } else{
        p.age = a;
    }
    cout<<"请输入身份证号:";
    p.id = inputString();//这里就不检查身份证号码了
    return p;
}
