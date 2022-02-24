#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool visited[100000];
vector<string> answer;
int depth = 0;

void DFS(string begin, vector<vector<string>>& tickets)
{
    if (depth == tickets.size()) {
        answer.push_back(begin);
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (begin == tickets[i][0] && !visited[i]) {
            depth++;
            answer.push_back(begin);
            visited[i] = true;
            DFS(tickets[i][1], tickets);
            if (answer.size() == tickets.size() + 1) {
                return;
            }
            answer.pop_back();
            depth--;
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets);
    return answer;
}

int main(void)
{
    /*
    vector<vector<string>> tickets = {
        {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}
    };
    */

    vector<vector<string>> tickets = {
        {"ICN", "A"}, {"B", "ICN"}, {"ICN", "B"}
    };

    for (auto i : solution(tickets)) {
        cout << i << " ";
    }

    return 0;
}
