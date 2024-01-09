#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

bool possible[101];

void DFS(int y, int n, vector<vector<int> >& signs)
{
    // 갈 수있는 정류장을 다 들린다.
    for (int x = 0; x < n; x++) {
        // 자기정류장 제외 && 갈 수있는 정류장만 && 이미 갈수 있다고 판명한 정류장 제외
        if (y != x && signs[y][x] && !possible[x]) {
            possible[x] = true;
            DFS(x, n, signs);
        }
    }

    return;
}

vector<vector<int> > solution(int n, vector<vector<int> > signs)
{
    vector<vector<int> > answer(n, vector<int>(n, 0));

    // 각 출발 버스 정류장
    for (int y = 0; y < n; y++) {
        memset(possible, false, 101 * sizeof(bool));
        DFS(y, n, signs);

        // 갈 수 있었던 정류장 체크해줌
        for (int i = 0; i < n; i++) {
            if (possible[i]) {
                answer[y][i] = 1;
            }
        }
        cout << endl;
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> answer = solution(3, { {0,0,1},{0,0,1},{0,1,0} });

    for (auto i : answer) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
