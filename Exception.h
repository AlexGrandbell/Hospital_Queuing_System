//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_EXCEPTION_H
#define HOSPITAL_QUEUING_SYSTEM_EXCEPTION_H
#include <stdexcept> // 包含stdexcept头文件以使用标准异常类
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//异常父类
class MyException:public exception{
public:
    explicit MyException(const char* message):errorMessage(message){}
    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//手动退出
class ExitException:public MyException{
public:
    ExitException(const char* message): MyException(message){}
};

//数字输入字符异常
class NumberException:public MyException{
public:
    NumberException(const char* message): MyException(message){}
};


//循环队列满异常
class QueueFullException:public MyException{
public:
    QueueFullException(const char* message): MyException(message){}
};

//循环队列空异常
class QueueEmptyException:public MyException{
public:
    QueueEmptyException(const char* message): MyException(message){}
};

//链式队列空异常
class ListQueueEmptyException:public MyException{
public:
    ListQueueEmptyException(const char* message): MyException(message){}
};

#endif //HOSPITAL_QUEUING_SYSTEM_EXCEPTION_H
