#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int skillSize = skill.size();
    int skillTreesSize = skill_trees.size();
    for (int i = 0; i < skillTreesSize; i++) {
        string skillTree = skill_trees[i];
        int skillTreeSize = skillTree.size();
        queue<char> q;
        for (int j = 0; j < skillTreeSize; j++) {
            char c = skillTree[j];
            for (int k = 0; k < skillSize; k++) {
                if (c != skill[k]) continue;
                q.push(c);
            }
        }

        bool check = true;
        int skillIndex = 0;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            if (c == skill[skillIndex]) {
                skillIndex++;
                continue;
            }
            check = false;
            break;
        }

        if (check == true) answer++;
    }
    return answer;
}