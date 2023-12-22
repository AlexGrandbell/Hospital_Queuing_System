//
// Created by 沈嘉瑞 on 2023.10.16.
//

#include "QueueSystem.h"

QueueSystem::QueueSystem(): mode(1),numNext(1),numNow(0){}

//显示菜单
void QueueSystem::outPutMenu(){
    cout<<"\n ----------菜单----------"<<endl;
    cout<<" |1.挂号                |"<<endl;
    cout<<" |2.接待                |"<<endl;
    cout<<" |3.下班                |"<<endl;
//    cout<<" |4.切换队列            |"<<endl;暂时不可切换
    cout<<" |0.退出程序            |"<<endl;
    cout<<" ------------------------"<<endl;
    //输出提示选择编号
    cout<<"请选择菜单项编号(0-3):";
}

//选择实现队列模式：0-数组循环队列，1-链式队列
void QueueSystem::choiceMode() {
    cout << "--------选择队列模式--------" << endl;
    try {
        int choice = 1;
        cout<<"请选择实现队列模式(0-循环队列,1-链式队列):";
        choice = inputInt();
        switch (choice) {
            case 0:
                cout<<"已选择循环队列模式。"<<endl;
                break;
            case 1:
                cout<<"已选择链式队列模式。"<<endl;
                break;
            default:
                throw NumberException("无效选择。");
        }
        mode = choice;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "----------------------------" << endl;
}

//挂号
void QueueSystem::Register() {
    cout << "------------挂号------------" << endl;
    try {
        cout<<"请输入就诊信息:"<< endl;
        Patient p;
        p = inputPatient();
        Record record = Record(p, numNext++);
        int numRest = 0;
        switch (mode) {
            case 0:
                sqQueue.push(record);
                numRest = sqQueue.size()-1;
                break;
            case 1:
                linkQueue.push(record);
                numRest = linkQueue.size()-1;
                break;
            default:
                throw NumberException("队列错误，挂号失败。");
        }
        if (numNext == 2){
            cout << "\n挂号成功！就诊信息如下:\n" << p << "\n您是第一位，可以直接进入就诊。" << endl;
        } else {
            cout << "\n挂号成功！就诊信息如下:\n" << p << "\n排队号码:" << record.getNum() << "\n您之前还有"
                 << numRest << "位正在排队，预计需要时间" << (numRest) * 3 + 1.5 << "分钟。"
                 << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "----------------------------" << endl;
}

//接待
void QueueSystem::Receive() {
    cout << "------------接待------------" << endl;
    try {

        if (numNow == 0){
            cout<<"您确定要开始接待吗?(1-是,0-否):";
        } else{
            cout<<"您确定要结束当前接待，并接待新的病人吗？(1-是,0-否):";
        }
        int choice = inputInt();
        switch (choice) {
            case 0:
                throw ExitException("已终止新的接待。");
            case 1:
                break;
            default:
                throw NumberException("选择无效，已终止新的接待。");
        }
        int numRest = 0;
        switch (mode) {
            case 0:
                if (sqQueue.empty()){
                    throw QueueEmptyException("当前队列无人排队，无需接待，当前接待已结束。");
                }
                cout<<"接待成功！新的病人信息如下:\n"<<sqQueue.pop().getPatient()<<endl;
                numRest = sqQueue.size();
                break;
            case 1:
                if (linkQueue.empty()){
                    throw QueueEmptyException("当前队列无人排队，无需接待，当前接待已结束。");
                }
                cout<<"接待成功！新的病人信息如下:\n"<<linkQueue.pop().getPatient()<<endl;
                numRest = linkQueue.size();
                break;
            default:
                throw NumberException("队列错误，挂号失败。");
        }
        numNow++;
        cout<<"还有" << numRest << "位正在排队。"<<endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "----------------------------" << endl;
}

//下班
void QueueSystem::CloseOffice(int & select) {
    cout << "------------下班------------" << endl;
    try {
        if (numNow == 0){
            cout<<"您刚刚上班，确定要下班吗?(1-是,0-否):";
        } else if (numNext - numNow - 1 == 0){
            cout<<"目前无人排队了，您确定要结束当前接待，并下班吗？(1-是,0-否):";
        } else if (numNext - numNow - 1 > 0){
            cout<<"目前仍有人排队，您确定要结束当前接待，并下班吗？(1-是,0-否):";
        } else{
            throw NumberException("排队人数错误，下班终止！");
        }
        int choice = inputInt();
        switch (choice) {
            case 0:
                throw ExitException("下班取消。");
            case 1:
                break;
            default:
                throw NumberException("选择无效，下班取消。");
        }
        cout<<"当前排队的信息为:";
        switch (mode) {
            case 0:
                cout<<"还有"<<sqQueue.size()<<"人排队"<<endl;
                while (!sqQueue.empty()){
                    cout<<"\n"<<sqQueue.pop().getPatient()<<endl;
                }
                break;
            case 1:
                cout<<"还有"<<linkQueue.size()<<"人排队"<<endl;
                while (!linkQueue.empty()){
                    cout<<"\n"<<linkQueue.pop().getPatient()<<endl;
                }
                break;
            default:
                throw NumberException("队列模式错误，操作失败。");
        }
        select = 0;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "----------------------------" << endl;
    if (select == 0){
        cout<<"\n欢迎再次使用，再见。"<<endl;
    }
}

//切换模式
void QueueSystem::changeMode() {
    choiceMode();
}

//退出程序
void QueueSystem::ExitApp(){
    cout<<"\n欢迎再次使用，再见。"<<endl;
}