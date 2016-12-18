#ifndef BIN2INS_H
#define BIN2INS_H
#include "pipe.h"
#include <bits/stdc++.h>
using namespace std;
struct ins {
    int addr;
    string code,content;
    ins(int a, string c, string content):addr(a), code(c), content(content) {}
};

string strip(const string &s);
pair<vector<ins>,map<int,int> > read_from_yo(const string &input);

#endif // BIN2INS_H
