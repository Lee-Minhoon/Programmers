#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP[501][501];
int height;

int solution(vector<vector<int>> triangle) {
    height = triangle.size();

    int answer = 0;
    DP[0][0] = triangle[0][0];
    for (int i = 1; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) DP[i][j] = DP[i - 1][j];
            else if (j == i) DP[i][j] = DP[i - 1][j - 1];
            else DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
            DP[i][j] += triangle[i][j];
        }
    }
    for (int i = 0; i < height; i++) {
        answer = max(answer, DP[height - 1][i]);
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

    cout << solution(triangle) << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
