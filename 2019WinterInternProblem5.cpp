#include <string>
#include <vector>
using namespace std;

bool isPossible(vector<int>& stones, int x, int k) { //false->fail to cross, true->can cross
    int size = stones.size();
    int zeroCnt = 0;
    for (int i = 0; i < size; i++) { //go x
        int y = (stones[i] - (x - 1) < 0) ? 0 : (stones[i] - (x - 1)); //current stat -> x-1 go
        if (y == 0) zeroCnt++;
        else zeroCnt = 0;
        if (zeroCnt == k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int min = 200000001; int max = 0;
    int size = stones.size();
    for (int i = 0; i < size; i++) {
        if (min > stones[i]) min = stones[i];
        if (stones[i] > max) max = stones[i];
    }

    int left = min;
    int right = max;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(stones, mid, k) == false) { //fail to cross
            right = mid - 1;
        }
        else { //can cross
            answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}