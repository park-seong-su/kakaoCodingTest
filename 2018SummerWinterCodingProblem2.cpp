#include <string>
#include <cstring>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool check[11][11][11][11];
    memset(check, false, sizeof(check));
    int r = 5; int c = 5;
    for (auto dir : dirs) {
        int nr = r; int nc = c;
        switch (dir) {
        case 'U':
            nr++; break;
        case 'D':
            nr--; break;
        case 'R':
            nc++; break;
        case 'L':
            nc--;
        }
        if (0 <= nr && nr < 11 && 0 <= nc && nc < 11) {
            if (check[r][c][nr][nc] == false) {
                check[r][c][nr][nc] = true;
                check[nr][nc][r][c] = true;
                answer++;
            }
            r = nr; c = nc;
        }
        else continue;
    }
    return answer;
}