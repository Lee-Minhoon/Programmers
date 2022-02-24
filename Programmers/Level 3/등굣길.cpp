#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool water[101][101];
int DP[101][101];
int gm, gn;


// 아래, 오른쪽 x y
int direction[2][2] = {
    {0, 1}, {1, 0}
};

int DFS(int x, int y, vector<vector<int>>& puddles) {
    if (x == gm && y == gn) {
        return 1;
    }
    if (DP[x][y] == -1) {
        DP[x][y] = 0;
        for (int i = 0; i < 2; i++) {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (!water[nx][ny] && nx <= gm && ny <= gn) {
                DP[x][y] += DFS(nx, ny, puddles);
                DP[x][y] %= 1000000007;
            }
        }
    }
    return DP[x][y] %= 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(DP, -1, sizeof(DP));
    int answer = 0;
    gm = m, gn = n;
    for (auto a : puddles) {
        int x_noway = a[0]; int y_noway = a[1];
        water[x_noway][y_noway] = true;
    }
    answer = DFS(1, 1, puddles);
    return answer;
}

int main(void)
{
    cout << solution(4, 3, { {2, 2} });

    return 0;
}
