#include <iostream>

const int T = 3;

using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        if (n % 2 == 0) n /= 2;
        else {
            n--;
            ans++;
        }
    }

    return ans;
}

int main(void)
{
    int testCase[T] = { 5, 6, 5000 };

    for (int i = 0; i < T; i++) {
        cout << solution(testCase[i]) << endl;
    }

    return 0;
}