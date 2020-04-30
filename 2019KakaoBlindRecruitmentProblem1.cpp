#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uidSeq;
    map<string, string> match;

    int size = record.size();
    for (int i = 0; i < size; i++) {
        string save[3]; //save[0] = "Enter" save[1] = "uid1234" save[2] = "Muzi"
        int saveIndex = 0;

        string token;
        int tokenIndex = 0;
        stringstream ss(record[i]);
        while (getline(ss, token, ' ')) {
            save[saveIndex++] = token;
        }

        if (save[0] == "Enter") {
            uidSeq.push_back(save[1]);
            match[save[1]] = save[2];
            answer.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        else if (save[0] == "Leave") {
            uidSeq.push_back(save[1]);
            answer.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
        else {
            match[save[1]] = save[2];
        }
    }

    int ansSize = answer.size();
    for (int i = 0; i < ansSize; i++) {
        answer[i] = match[uidSeq[i]] + answer[i];
    }

    return answer;
}