//
// Created by 陈鹏宇 on 2023/11/18.
//
#pragma once

#include "iostream"
#include "fstream"

using namespace std;

class readEng {
public:
    static void showAll(const int *array) {
        int max = 0;
        for (int i = 0; i < 26; ++i) {
            if (max < array[i])
                max = array[i];
        }
        for (int i = max; i >= 1; --i) {
            for (int j = 0; j < 26; ++j) {
                if (array[j] >= i) {
                    cout << '*' << ' ';
                } else {
                    cout << "  ";
                }
            }
            cout << '\n';
        }
        for (int i = 0; i < 26; ++i) {
            cout << char('A' + i) << ' ';
        }
        cout << '\n';
    }

    static void total() {
        int a[26];
        for (int &i: a) {
            i = 0;
        }
        ifstream ifs;
        ifs.open("file.txt", ios::in);
        if (!ifs.is_open()) {
            cout << "error" << endl;
            return;
        }
        string s;
        for (int i = 0; i < 4; ++i) {
            getline(ifs, s);
            for (const char &item: s) {
                if (item <= 'Z' && item >= 'A')
                    a[item - 'A']++;
            }
        }
        showAll(a);
        ifs.close();
    }
};