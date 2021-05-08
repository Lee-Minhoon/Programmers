#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    unordered_map<string, int> cnt;
    set<string> kinds(gems.begin(), gems.end());
    int min, start = 0, end = 0;

    // 모든 보석을 찾을 때 까지 탐색
    for (auto& i : gems) {
        cnt[i]++;
        if (cnt.size() == kinds.size()) break;
        end++;
    }
    min = end - start;
    answer = { start + 1, end + 1 };

    while (end < gems.size()) {
        string cur = gems[start];
        cnt[cur]--; start++;
        
        if (cnt[cur] == 0) {
            end++;
            while (end < gems.size()) {
                cnt[gems[end]]++;
                if (cur == gems[end]) break;
                end++;
            }
        }

        if (end - start < min) {
            answer = { start + 1, end + 1 };
            min = end - start;
        }
    }

    return answer;
}

int main(void)
{
    vector<string> gems[4] = {
        {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"},
        {"AA", "AB", "AC", "AA", "AC"},
        {"XYZ", "XYZ", "XYZ"},
        {"ZZZ", "YYY", "NNNN", "YYY", "BBB"}
    };

    for (int i = 0; i < 4; i++) {
        vector<int> answer = solution(gems[i]);
        for (auto j : answer) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}