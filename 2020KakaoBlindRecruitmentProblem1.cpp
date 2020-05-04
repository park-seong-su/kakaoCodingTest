#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    int min = 1001;
    for (int k = 1; k <= len / 2; k++) {
        string temp;
        for (int i = 0; i < len; i++) {
            string cur = s.substr(i, k);
            int cnt = 1; int j = 0;
            for (j = i + k; j < len; j += k) {
                string next = s.substr(j, k);
                if (cur != next) break;
                cnt++;
            }
            i = j - 1;
            if (cnt == 1) temp += cur;
            else temp += to_string(cnt) + cur;
        }
        if (min > temp.length()) min = temp.length();
    }
    if (len == 1) min = 1;
    answer = min;
    return answer;
}