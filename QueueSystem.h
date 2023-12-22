//
// Created by 沈嘉瑞 on 2023.10.16.
//

#ifndef HOSPITAL_QUEUING_SYSTEM_QUEUESYSTEM_H
#define HOSPITAL_QUEUING_SYSTEM_QUEUESYSTEM_H
#include "SqQueue.h"
#include "LinkQueue.h"

class QueueSystem {
private:
    SqQueue<Record> sqQueue;
    LinkQueue<Record> linkQueue;
    int mode;//0-循环队列,1-链式队列
    int numNext;//下一个要挂号的号码
    int numNow;//正在看病的号码
public:
    QueueSystem();

    void outPutMenu();
    void choiceMode();

    void Register();
    void Receive();
    void changeMode();
    void CloseOffice(int &);

    void ExitApp();
};

#endif //HOSPITAL_QUEUING_SYSTEM_QUEUESYSTEM_H