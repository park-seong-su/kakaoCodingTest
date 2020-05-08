#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true) {
        vector<vector<bool>> check(m, vector<bool>(n));
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == ' ') continue;
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
                    check[i][j] = true; check[i][j + 1] = true; check[i + 1][j] = true; check[i + 1][j + 1] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == true) {
                    cnt++;
                }
            }
        }

        if (cnt == 0) break;
        answer += cnt;

        for (int j = 0; j < n; j++) {
            vector<char> temp;
            for (int i = m - 1; i >= 0; i--) {
                if (check[i][j] == false) {
                    temp.push_back(board[i][j]);
                }
                char spaceChar = ' ';
                board[i][j] = spaceChar;
            }

            int tempSize = temp.size();
            int boardi = m - 1;
            for (int i = 0; i < tempSize; i++) {
                board[boardi--][j] = temp[i];
            }
        }
    }
    return answer;
}