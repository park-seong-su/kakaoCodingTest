#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> save(3);
    int saveIndex = 0;
    int dSize = dartResult.size();
    for (int i = 0; i < dSize; i++) {
        char d = dartResult[i];
        if (48 <= (int)d && (int)d <= 57) {
            if (d == '1') {
                if (dartResult[i + 1] == '0') {
                    save[saveIndex] = 10;
                    i++;
                }
                else {
                    save[saveIndex] = (int)d - 48;
                }
            }
            else {
                save[saveIndex] = (int)d - 48;
            }
            saveIndex++;
        }
        else if (d == 'D') {
            save[saveIndex - 1] = save[saveIndex - 1] * save[saveIndex - 1];
        }
        else if (d == 'T') {
            save[saveIndex - 1] = save[saveIndex - 1] * save[saveIndex - 1] * save[saveIndex - 1];
        }
        else if (d == '*') {
            if (saveIndex == 1) {
                save[saveIndex - 1] *= 2;
            }
            else {
                save[saveIndex - 2] *= 2;
                save[saveIndex - 1] *= 2;
            }
        }
        else if (d == '#') {
            save[saveIndex - 1] *= -1;
        }
    }

    answer = save[0] + save[1] + save[2];
    return answer;
}