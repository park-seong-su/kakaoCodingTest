#include <string>
#include <vector>

using namespace std;

void moveRight(vector<vector<int>>& key) {
    int len = key[0].size();
    vector<vector<int>> temp(len, vector<int>(len));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            temp[i][j] = key[i][j];
        }
    }
    int tempj = 0;
    for (int i = 0; i < len; i++) {
        int tempi = len - 1;
        for (int j = 0; j < len; j++) {
            key[i][j] = temp[tempi--][tempj];
        }
        tempj++;
    }
}

bool check(vector<vector<int>>& key, vector<vector<int>>& lock) {
    int m = key[0].size(); int n = lock[0].size();
    int k = n + 2 * m - 2;
    vector<vector<int>> map(k, vector<int>(k));

    for (int starti = 0; starti < m + n - 1; starti++) {
        for (int startj = 0; startj < m + n - 1; startj++) {
            int r = 0;
            for (int i = m - 1; i < m + n - 1; i++) {
                int c = 0;
                for (int j = m - 1; j < m + n - 1; j++) {
                    map[i][j] = lock[r][c++];
                }
                r++;
            }

            bool c = true;
            int keyi = 0;
            for (int i = starti; i < starti + m; i++) {
                int keyj = 0;
                for (int j = startj; j < startj + m; j++) {
                    if (m - 1 <= i && i < m + n - 1 && m - 1 <= j && j < m + n - 1) {
                        if (map[i][j] == 1 && key[keyi][keyj] == 1) {
                            c = false;
                            break;
                        }
                    }
                    map[i][j] = (map[i][j] | key[keyi][keyj++]);
                }
                if (c == false) break;
                keyi++;
            }
            if (c == false) continue;

            for (int i = m - 1; i < m + n - 1; i++) {
                for (int j = m - 1; j < m + n - 1; j++) {
                    if (map[i][j] == 0) {
                        c = false;
                        break;
                    }
                }
            }
            if (c == true) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    bool temp = check(key, lock);
    if (temp == false) {
        moveRight(key);
        temp = check(key, lock);
        if (temp == false) {
            moveRight(key);
            temp = check(key, lock);
            if (temp == false) {
                moveRight(key);
                temp = check(key, lock);
                if (temp == false) answer = false;
            }
        }
    }

    return answer;
}