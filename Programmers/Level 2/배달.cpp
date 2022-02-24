#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    vector<vector<pair<int, int>>> con(N + 1);
    for (auto i : road) {
        con[i[0]].push_back({ i[1], i[2] });
        con[i[1]].push_back({ i[0], i[2] });
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    pq.push({ 0, 1 });

    // 다익스트라 알고리즘
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // 갱신된 최소 거리보다 비용이 크다면 탐색할 필요 없음.
        if (cost > dist[node]) continue;

        // 현재 노드에서 갈수 있는 노드를 탐색
        for (auto i : con[node]) {
            int nextNode = i.first;
            int nextCost = i.second;
            // 최소 거리를 갱신한다.
            if (dist[node] + nextCost < dist[nextNode]) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({ -nextCost, nextNode });
            }
        }
    }
    
    for (auto i : dist) {
        if (i <= K) answer++;
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> road[2] = {
        {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}},
        {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}
    };

    for (int i = 0; i < 2; i++) {
        cout << solution(road[i].size(), road[i], i + 3) << endl;
    }

    return 0;
}