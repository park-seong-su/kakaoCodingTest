#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left, right;
    left.first = 3; left.second = 0;
    right.first = 3; right.second = 2;
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            if (num == 1) {
                left.first = 0; left.second = 0;
            }
            else if (num == 4) {
                left.first = 1; left.second = 0;
            }
            else {
                left.first = 2; left.second = 0;
            }
            answer += 'L';
        }
        else if (num == 3 || num == 6 || num == 9) {
            if (num == 3) {
                right.first = 0; right.second = 2;
            }
            else if (num == 6) {
                right.first = 1; right.second = 2;
            }
            else {
                right.first = 2; right.second = 2;
            }
            answer += 'R';
        }
        else {
            int distFromLeft = 0, distFromRight = 0;
            pair<int, int> pos;
            if (num == 2) { pos.first = 0; pos.second = 1; }
            else if (num == 5) { pos.first = 1; pos.second = 1; }
            else if (num == 8) { pos.first = 2; pos.second = 1; }
            else { pos.first = 3; pos.second = 1; }

            distFromLeft = abs(left.first - pos.first) + abs(left.second - pos.second);
            distFromRight = abs(right.first - pos.first) + abs(right.second - pos.second);
            if (distFromLeft > distFromRight) {
                right.first = pos.first; right.second = pos.second;
                answer += 'R';
            }
            else if (distFromLeft < distFromRight) {
                left.first = pos.first; left.second = pos.second;
                answer += 'L';
            }
            else {
                if (hand == "right") {
                    right.first = pos.first; right.second = pos.second;
                    answer += 'R';
                }
                else {
                    left.first = pos.first; left.second = pos.second;
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}