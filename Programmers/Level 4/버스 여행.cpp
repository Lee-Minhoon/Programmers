#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

bool possible[101];

void DFS(int y, int n, vector<vector<int> >& signs)
{
    // �� ���ִ� �������� �� �鸰��.
    for (int x = 0; x < n; x++) {
        // �ڱ������� ���� && �� ���ִ� �����常 && �̹� ���� �ִٰ� �Ǹ��� ������ ����
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

    // �� ��� ���� ������
    for (int y = 0; y < n; y++) {
        memset(possible, false, 101 * sizeof(bool));
        DFS(y, n, signs);

        // �� �� �־��� ������ üũ����
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
