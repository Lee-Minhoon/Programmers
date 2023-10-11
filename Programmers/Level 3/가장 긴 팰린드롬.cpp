#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 2501;

int cache[MAX][MAX];

/*
bool isPalindrom(int start, int end, string s)
{
    // 서로 맞닿은 상태에서 팰린드롬이거나 자기 자신인 경우 기저 사례
    if (cache[start][end] != -1) {
        return cache[start][end];
    }
    // 팰린드롬 탐색 계속 진행
    if (s[start] == s[end]) {
        // 탐색 범위 좁혀서 탐색
        return cache[start][end] = isPalindrom(start + 1, end - 1, s);
    }
    else {
        // 팰린드롬 아님
        return cache[start][end] = 0;
    }
}
*/

int solution(string s)
{
    int answer = 0;

    /*
    memset(cache, -1, sizeof(cache));
    cache[0][0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        cache[i][i] = 1;
        if (s[i] == s[i - 1]) {
            cache[i - 1][i] = 1;
        }
        else {
            cache[i - 1][i] = 0;
        }
    }
    */

    if (s.length() == 1) return 1;

    // i 길이에 해당하는 팰린드롬 탐색
    for (int i = s.length(); i > 0; i--) {
        // 인덱스위치 옮겨가며 해당 길이만큼의 문자열이 팰린드롬인지?
        for (int j = 0; j + i <= s.length(); j++) {
            /*
            if (isPalindrom(j, j + i - 1, s)) {
                return i;
            }
            */
            int start = j; int end = j + i - 1;
            while (start <= end) {
                if (s[start] != s[end]) break;
                // 가장 먼저 발견된 팰린드롬이 가장 긴 팰린드롬
                if ((start + 1 == end || start == end) && s[start] == s[end]) {
                    return i;
                }
                start++; end--;
            }
        }
    }

    return answer;
}

int main(void)
{
    cout << solution("a");

    return 0;
}