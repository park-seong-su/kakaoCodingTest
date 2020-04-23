#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.length();
    int n = 0;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '}') n++;
    }
    string* temp = new string[n];
    vector<int>* a = new vector<int>[n];
    int* sum = new int[n];
    int k = 0;
    for (int i = 1; i < len - 1; i++) {
        if (s[i] == '{') {
            int j = 0;
            for (j = i + 1; s[j] != '}'; j++) {
                //if (s[j] == ',') continue;
                temp[k] += s[j];
            }
            k++;
            i = j;
        }
    }

    for (int i = 0; i < n; i++) {
        string token;
        stringstream ss(temp[i]);
        while (getline(ss, token, ',')) {
            a[i].push_back(atoi(token.c_str()));
        }
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        int aSize = a[i].size();
        sum[i] = 0;
        for (int j = 0; j < aSize; j++) {
            sum[i] += a[i][j];
        }
    }

    answer.push_back(sum[0]);
    for (int i = 1; i < n; i++) {
        answer.push_back(sum[i] - sum[i - 1]);
    }
    return answer;
}