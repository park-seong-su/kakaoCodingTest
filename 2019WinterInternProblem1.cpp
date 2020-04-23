#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board[0].size();
    int movesSize = moves.size();
    stack<int> s;
    for (int m = 0; m < movesSize; m++) {
        int move = moves[m];
        for (int i = 0; i < n; i++) {
            if (board[i][move - 1] == 0) continue;
            if (m == 0) {
                s.push(board[i][move - 1]);
            }
            else {
                if (!s.empty()) {
                    if (s.top() == board[i][move - 1]) {
                        s.pop();
                        answer += 2;
                    }
                    else {
                        s.push(board[i][move - 1]);
                    }
                }
                else {
                    s.push(board[i][move - 1]);
                }
            }
            board[i][move - 1] = 0;
            break;
        }
    }
    return answer;
}