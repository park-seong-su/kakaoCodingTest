#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int index = -1;
    int size = words.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (words[i] == words[j]) {
                index = j;
            }
        }
    }

    if (index == -1) { //don't exist same element
        bool fail = false;
        for (int i = 0; i < size - 1; i++) {
            string s1 = words[i]; string s2 = words[i + 1];
            if (s1[s1.length() - 1] == s2[0]) continue;
            else {
                fail = true;
                index = i + 1;
                break;
            }
        }
        if (fail == false) {
            answer.push_back(0);
            answer.push_back(0);
        }
        else {
            int playerNum = index % n; playerNum++;
            int cnt = index / n; cnt++;
            answer.push_back(playerNum);
            answer.push_back(cnt);
        }
    }
    else { //exist same element
        int playerNum = index % n; playerNum++;
        int cnt = index / n; cnt++;
        answer.push_back(playerNum);
        answer.push_back(cnt);
    }

    return answer;
}