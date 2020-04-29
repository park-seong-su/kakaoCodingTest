#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void go(vector<string>& user_id, vector<string>& banned_id, bool check[], vector<int>& temp, set<string>& s, int cnt, int bIndex) {
    if (cnt == banned_id.size()) {
        int tempSize = temp.size();
        string save;
        for (int i = 0; i < tempSize; i++) {
            save += to_string(temp[i]);
        }
        sort(save.begin(), save.end());
        s.insert(save);
        return;
    }

    int bLen = banned_id[bIndex].size();
    int totalUserSize = user_id.size();
    for (int i = 0; i < totalUserSize; i++) {
        if (check[i] == true) continue;
        bool same = true;
        int uLen = user_id[i].size();
        if (uLen != bLen) continue;
        for (int j = 0; j < uLen; j++) {
            if (banned_id[bIndex][j] == '*') continue;
            if (user_id[i][j] != banned_id[bIndex][j]) {
                same = false;
                break;
            }
        }
        if (same == false) continue;
        check[i] = true;
        temp.push_back(i);
        go(user_id, banned_id, check, temp, s, cnt + 1, bIndex + 1);
        temp.erase(temp.end() - 1);
        check[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int n = user_id.size();
    bool* check = new bool[n];
    for (int i = 0; i < n; i++) check[i] = false;
    vector<int> temp;
    set<string> s;
    go(user_id, banned_id, check, temp, s, 0, 0);
    answer = s.size();
    return answer;
}