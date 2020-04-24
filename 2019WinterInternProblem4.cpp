//테스트 케이스 all clear, 효율성 zore
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> temp;
    answer.push_back(room_number[0]);
    temp.push_back(room_number[0]);
    int rnSize = room_number.size();
    for (int i = 1; i < rnSize; i++) {
        int rn = room_number[i];
        int left = 0;
        int right = temp.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rn < temp[mid]) {
                right = mid - 1;
            }
            else if (temp[mid] < rn) {
                left = mid + 1;
            }
            else {
                rn++;
                left = 0;
                right = temp.size() - 1;
                continue;
            }
        }
        answer.push_back(rn);
        temp.push_back(rn);
        if (rn < temp[temp.size() - 2]) {
            sort(temp.begin(), temp.end());
        }
    }
    return answer;
}