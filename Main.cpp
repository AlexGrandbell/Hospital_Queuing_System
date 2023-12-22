#include "QueueSystem.h"

int main() {
    QueueSystem queueSystem;
    cout << "\n欢迎进入医生挂号系统" << endl;
    cout<<"你可以随时输入'q'来退出当前操作。"<<endl;
    cout<<"注意，循环队列和链式队列是两个独立的队列。"<<endl;
    cout<<"----------任意输入以开始----------"<<endl;
    string tmp;
    cin>>tmp;
    cout<<endl;

    queueSystem.choiceMode();//选择队列模式

    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    //不断循环，执行操作
    do {
        //界面与输入
        queueSystem.outPutMenu();//界面
        fflush(stdin);//清除输入流缓存
        nSelection = -1;
        try {
            nSelection = inputInt();

            //根据输入选择行为
            switch (nSelection) {
                case 0: {
                    queueSystem.ExitApp();
                    return 0;
                }//再见
                case 1: {
                    queueSystem.Register();
                    break;
                }//挂号
                case 2: {
                    queueSystem.Receive();
                    break;
                }//接待
                case 3: {
                    queueSystem.CloseOffice(nSelection);
                    break;
                }//下班
                case 4:
                    queueSystem.changeMode();
                    break;
                default: {
                    printf("您输入的菜单序号错误,");
                    break;
                }//错误
            }//完成
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
        if (nSelection != 0) {
            printf("继续操作请按1，关闭程序请按0:");
            fflush(stdin);//清除输入流缓存
            nSelection = -1;
            try {
                nSelection = inputInt();
                if (nSelection == 0) {
                    queueSystem.ExitApp();
                }
            }catch  (const exception& e){
                cerr<<e.what()<<endl;
            }
        }
    } while (nSelection != 0);
    return 0;
}

