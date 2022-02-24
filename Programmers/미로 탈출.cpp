#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000;

bool adj[1000][1000];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps)
{
    int answer = 0;

    vector<vector<pair<int, int>>> con(n + 1);
    for (auto i : roads) {
        adj[i[0]][i[1]] = true;
        con[i[0]].push_back({ i[1], i[2] });
        con[i[1]].push_back({ i[0], i[2] });
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    pq.push({ 0, 1 });

    // 다익스트라 알고리즘
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        cout << node << ' ' << cost << endl;

        // 현재 노드에서 갈수 있는 노드를 탐색
        for (auto i : con[node]) {
            int nextNode = i.first;
            int nextCost = i.second;

            for (int x = 1; x <= n; x++) {
                cout << adj[node][x] << ' ';
            }
            cout << endl;

            if (adj[node][nextNode]) {
                if (dist[node] + nextCost < dist[nextNode]) {
                    dist[nextNode] = dist[node] + nextCost;
                    pq.push({ -nextCost, nextNode });
                }
                if (find(traps.begin(), traps.end(), nextNode) != traps.end()) {
                    for (auto j : con[nextNode]) {
                        adj[j.first][nextNode] = !adj[j.first][nextNode];
                        adj[nextNode][j.first] = !adj[nextNode][j.first];
                    }
                }
            }
        }
    }

    return dist[end];
}

int main(void)
{
    vector<vector<int>> road[2] = {
        {{1, 2, 2}, {3, 2, 3}},
        {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}}
    };
    vector<int> traps[2] = {
        {2}, {2, 3}
    };

    for (int i = 0; i < 2; i++) {
        cout << solution(i + 3, 1, i + 3, road[i], traps[i]) << endl << endl;
        memset(adj, false, sizeof(adj));
    }

    return 0;
}