//
// Created by 陈鹏宇 on 2023/11/18.
//
#pragma once

#include "iostream"

using namespace std;

class BAW {
public:
    static void show(int *array) {
        for (int i = 0; i < 7; ++i) {
            cout << array[i] << ' ';
        }
        cout << '\n';
    }

    static bool isOver(const int *array) {
        return array[0] == 2 &&
               array[1] == 2 &&
               array[2] == 2 &&
               array[3] == 0 &&
               array[4] == 1 &&
               array[5] == 1 &&
               array[6] == 1;
    }

    static void total() {
        int all[7] = {1, 1, 1, 0, 2, 2, 2}; //白1 黑2 空0
        show(all);
        int count = 0;
        while (!isOver(all)) {
            bool flag = true;
            for (int i = 0; i < 5 && flag; ++i) {
                if (all[i] == 1 && all[i + 1] == 2 && all[i + 2] == 0) {
                    swap(all[i], all[i + 2]);
                    show(all);
                    flag = false;
                    count++;
                }
            }
            for (int i = 0; i < 5; ++i) {
                if (all[i] == 0 && all[i + 1] == 1 && all[i + 2] == 2) {
                    swap(all[i], all[i + 2]);
                    show(all);
                    flag = false;
                    count++;
                }
            }
            for (int i = 0; i < 6 && flag; ++i) {
                if (all[i] == 1 && all[i + 1] == 0 && (i == 0 || all[i - 1] != all[i + 2])) {
                    swap(all[i], all[i + 1]);
                    show(all);
                    flag = false;
                    count++;
                }
            }
            for (int i = 0; i < 6 && flag; ++i) {
                if (all[i] == 0 && all[i + 1] == 2 && (i == 5 || all[i - 1] != all[i + 2])) {
                    swap(all[i], all[i + 1]);
                    show(all);
                    flag = false;
                    count++;
                }
            }
        }
        cout<<count;
    }
};