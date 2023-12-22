//
// Created by 沈嘉瑞 on 2023.10.15.
//

#include "Tool.h"

double inputDouble(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return doubleNumberTest(tmp);
}

int inputInt(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return intNumberTest(tmp);
}

string inputString(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return tmp;
}

//double转换
double doubleNumberTest(string num){
    double tempDouble = 0;
    std::istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw NumberException("在需要输入小数的地方输入的不是一个数字，操作失败！");
    }
};

int intNumberTest(string num){
    int tempDouble = 0;
    std::istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw NumberException("在需要输入整数的地方输入的不是一个数字，操作失败！");
    }
}

void exitTest(string s){
    if (s == "q"){
        throw ExitException("已手动退出进程。");
    }
}