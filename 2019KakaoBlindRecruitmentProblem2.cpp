#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stayCnt(N + 1, 0);
    vector<int> NumReached(N + 1, 0);
    vector<double> failRate(N + 1, 0);
    vector<bool> check(N + 1, false);

    int size = stages.size();
    for (int i = 0; i < size; i++) {
        int stage = stages[i];
        if (stage == N + 1) {
            NumReached[N]++;
            continue;
        }
        stayCnt[stage]++;
    }

    NumReached[N] += stayCnt[N];
    for (int i = N - 1; i >= 1; i--) {
        NumReached[i] = NumReached[i + 1] + stayCnt[i];
    }

    for (int i = 1; i <= N; i++) {
        if (NumReached[i] == 0) {
            failRate[i] = 0;
            continue;
        }
        failRate[i] = (double)stayCnt[i] / (double)NumReached[i];
    }

    for (int i = 1; i <= N; i++) {
        double max = -1;
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            if (failRate[j] > max&& check[j] == false) {
                max = failRate[j];
                ans = j;
            }
        }
        check[ans] = true;
        answer.push_back(ans);
    }

    return answer;
}