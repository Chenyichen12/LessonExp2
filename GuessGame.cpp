//
// Created by 陈鹏宇 on 2023/11/18.
//
#pragma once

#include "iostream"
#include <ctime>

using namespace std;

class GuessGame {
public:
    static void guess() {
        cout << "猜个数字" << '\n';
        unsigned seed = time(nullptr);
        srand(seed);
        int num = rand() % 9000 + 1000;
        string s = to_string(num);
        while(true){
            string userNum;
            cin>>userNum;
            if(userNum == s)
                break;
            int count1 = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if(userNum[i] == s[j]){
                        count1++;
                        break;
                    }
                }
            }
            int count2 = 0;
            for (int i = 0; i < 3; ++i) {
                if(userNum[i] == s[i]){
                    count2++;
                }
            }
            cout<<"有"<<count1<<"个数字猜对了，其中有"<<count2<<"个数字位置也是对的\n";
        }
        cout<<"恭喜你猜对了\n";
    }
};