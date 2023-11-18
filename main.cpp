#include <iostream>
#include "GuessGame.cpp"
#include "AutoPaper.cpp"
#include "MoveNumber.cpp"
#include "MoveBlackAndWhite.cpp"
#include "ReadFile.cpp"
int main() {

    while(true){
        cout<<"选择程序"<<endl;
        cout<<"[1] 猜数游戏"<<endl;
        cout<<"[2] 自动发牌"<<endl;
        cout<<"[3] 数字移动"<<endl;
        cout<<"[4] 黑白子"<<endl;
        cout<<"[5] 读取字符"<<endl;
        cout<<"[6] 退出"<<endl;
        int mode;
        cin>>mode;
        switch (mode) {
            case 1:
                GuessGame::guess();
                break;
            case 2:
                AutoPaper::autoPok();
                break;
            case 3:
                MoveNumber::total();
                break;
            case 4:
                BAW::total();
                break;
            case 5:
                readEng::total();
                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
}
