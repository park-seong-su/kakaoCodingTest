#include <string>
#include <vector>
#include <map>
using namespace std;

long long Find(map<long long, long long>& parent, long long x) {
    if (parent[x] == 0) {
        return x;
    }
    else {
        return parent[x] = Find(parent, parent[x]);
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int rnSize = room_number.size();
    map<long long, long long> parent;

    for (int i = 0; i < rnSize; i++) {
        long long rn = room_number[i];
        long long emptyRoom = Find(parent, rn);
        answer.push_back(emptyRoom);
        parent[emptyRoom] = emptyRoom + 1; //Union
    }
    return answer;
}


/*
//testcase all clear, efficiency zore
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
*/