#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<unordered_set<int>> DP(9);

int concat(int N, int v) {
    int ret = N;
    for (int i = 1; i < v; i++) {
        ret += (N * pow(10, i));
    }
    return ret;
}

int solution(int N, int number) {
    if (N == number) return 1;

    DP[1].insert(N);
    for (int i = 2; i <= 8; i++) {
        DP[i].insert(concat(N, i));
        for (int j = 1; j < i; j++) {
            for (auto a : DP[j]) {
                for (auto b : DP[i - j]) {
                    DP[i].insert(a + b);
                    if (a - b > 0) DP[i].insert(a - b);
                    DP[i].insert(a * b);
                    if (a / b > 0) DP[i].insert(a / b);
                }
            }
        }
        if (DP[i].count(number)) return i;
    }
    return -1;
}

int main(void)
{
    cout << solution(2, 11) << endl;
    for (int i = 1; i <= 8; i++) {
        for (auto a : DP[i]) {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
