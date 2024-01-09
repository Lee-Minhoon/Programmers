#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 201

bool visited[MAX];
int answer = 0;

void DFS(int node, int n, vector<vector<int>>& computers)
{
    visited[node] = true;
    for (int i = 0; i < computers[node].size(); i++) {
        if (node == i) continue;
        int next = i;
        if (!visited[i] && computers[node][i]) DFS(next, n, computers);
    }

    return;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n, computers);
            answer++;
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> computers = { {1,1,0}, {1,1,1}, {0,1,1} };
    cout << solution(3, computers);
    return 0;
}
