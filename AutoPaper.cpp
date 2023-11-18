//
// Created by 陈鹏宇 on 2023/11/18.
//
#pragma once

#include "iostream"
#include <ctime>

using namespace std;


class AutoPaper {
public:
    static void autoPok() {
        string number[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        char color[4] = {'S', 'H', 'D', 'C'};
        int total[52];
        //第一个13个牌为黑桃，依次类推
        for (int i = 0; i < 52; ++i) {
            total[i] = i;
        }
        //洗牌
        unsigned seed = time(nullptr);
        srand(seed);
        for (int i = 51; i >= 0; --i) {
            swap(total[i], total[rand() % (i + 1)]);
        }
        for (int i = 0; i < 4; ++i) {
            cout << "发给第" << i + 1 << "个人的牌为\n";
            for (int j = 13 * i; j < 13 * i + 13; ++j) {
                int num = total[j];
                cout << color[num / 13] << number[num % 13] << ' ';
            }
            cout << '\n';
        }
    }
};