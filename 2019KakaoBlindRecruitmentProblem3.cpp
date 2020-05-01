#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(string& s1, string& s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    else return s1 < s2;
}

void listCheck(vector<vector<string>>& relation, vector<bool>& checkInGoFunc, int setSize, set<string>& save) {
    int attributeSize = relation[0].size();
    int listSize = relation.size();
    vector<string> temp(listSize);

    for (int j = 0; j < attributeSize; j++) {
        if (checkInGoFunc[j] == false) continue;
        for (int i = 0; i < listSize; i++) {
            temp[i] += relation[i][j];
        }
    }

    for (int i = 0; i < listSize; i++) {
        for (int j = i + 1; j < listSize; j++) {
            if (temp[i] != temp[j]) continue;
            else return;
        }
    }

    string s;
    for (int j = 0; j < attributeSize; j++) {
        if (checkInGoFunc[j] == false) continue;
        s += to_string(j);
    }
    save.insert(s);
}

void go(vector<vector<string>>& relation, vector<bool>& checkInGoFunc, int setSize, int cnt, set<string>& save) {
    if (setSize == cnt) {
        listCheck(relation, checkInGoFunc, setSize, save);
        return;
    }

    int attributeSize = relation[0].size();
    for (int i = 0; i < attributeSize; i++) {
        if (checkInGoFunc[i] == true) continue;
        checkInGoFunc[i] = true;
        go(relation, checkInGoFunc, setSize, cnt + 1, save);
        checkInGoFunc[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int attributeSize = relation[0].size();
    set<string> save;
    for (int setSize = 1; setSize <= attributeSize; setSize++) {
        vector<bool> checkInGoFunc(attributeSize, false);
        go(relation, checkInGoFunc, setSize, 0, save);
    }

    vector<string> uniqueness(save.size());
    vector<bool> check(save.size(), false);
    int index = 0;
    set<string>::iterator iter;
    for (iter = save.begin(); iter != save.end(); iter++) {
        uniqueness[index++] = *iter;
    }
    sort(uniqueness.begin(), uniqueness.end(), cmp);

    int uSize = uniqueness.size();
    for (int i = 0; i < uSize; i++) {
        if (check[i] == true) continue;
        answer++;
        string elements = uniqueness[i];
        for (int j = i + 1; j < uSize; j++) {
            if (check[j] == true) continue;
            bool allCheck = true;
            for (auto element : elements) {
                if (uniqueness[j].find(element) == string::npos) { //don't find
                    allCheck = false;
                    break;
                }
                //if(find) allCheck = true
            }
            if (allCheck == true) {
                check[j] = true;
            }
        }
    }

    return answer;
}