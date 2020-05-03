#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    vector<bool> check(3001, false); check[0] = true; check[1] = true;
    for (int i = 2; i <= 1500; i++) {
        if (check[i] == false) {
            for (int j = i + i; j <= 3000; j += i) {
                check[j] = true;
            }
        }
    }

    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (check[sum] == false) answer++;
            }
        }
    }

    return answer;
}