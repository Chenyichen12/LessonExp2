//
// Created by 陈鹏宇 on 2023/11/18.
//
#pragma once

#include "iostream"

using namespace std;

class MoveNumber {
public:
    static int get(int row, int col, int direction) {
        int a[] = {0, 1, 2, 12, 22, 21, 20, 10};
        int i;
        for (i = 0; i < 8; i++)
            if (a[i] == row * 10 + col)
                return a[(i + direction + 8) % 8];
        return -1;
    }


    static int getData(int a[3][3], int data) {
        int i, j;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (a[i][j] == data)
                    return i * 10 + j;
        return -1;
    }

    static void show(int a[3][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }

    static void total() {
        unsigned seed = time(nullptr);
        srand(seed);
        int tep[8];
        for (int i = 0; i < 8; ++i) {
            tep[i] = i + 1;
        }
        for (int i = 7; i >= 0; --i) {
            swap(tep[i], tep[rand() % (i + 1)]);
        }
        int a[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1)
                    a[i][j] = 0;
                else if (i * 3 + j > 4)
                    a[i][j] = tep[i * 3 + j - 1];
                else
                    a[i][j] = tep[i * 3 + j];
            }
        }

        int i, pos;

        int row, col;

        int count = 0;

        cout << "移动前的数据:\n";

        show(a);

        for (i = 2; i <= 8; i++) {

            pos = getData(a, i);//查找数值i的坐标

            row = pos / 10;//i的坐标

            col = pos % 10;//i的坐标

            a[1][1] = i;

            a[row][col] = 0;
            cout << '\n';
            show(a);
            pos = get(row, col, -1);//查找数值i的前一个数的坐标

            while (a[pos / 10][pos % 10] != i - 1) {

                a[row][col] = a[pos / 10][pos % 10]; //前一个数放在数据0位置

                a[pos / 10][pos % 10] = 0;//前一个数改成0

                row = pos / 10;
                col = pos % 10;

                pos = get(pos / 10, pos % 10, -1);//查找下一个

                count++;
                cout << '\n';
                show(a);

            }
            a[row][col] = i;
            a[1][1] = 0;
        }
        cout << "移动后的数据:\n";
        show(a);
        cout << "移动次数" << count << endl;

    }


};