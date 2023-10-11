#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 2501;

int cache[MAX][MAX];

/*
bool isPalindrom(int start, int end, string s)
{
    // ���� �´��� ���¿��� �Ӹ�����̰ų� �ڱ� �ڽ��� ��� ���� ���
    if (cache[start][end] != -1) {
        return cache[start][end];
    }
    // �Ӹ���� Ž�� ��� ����
    if (s[start] == s[end]) {
        // Ž�� ���� ������ Ž��
        return cache[start][end] = isPalindrom(start + 1, end - 1, s);
    }
    else {
        // �Ӹ���� �ƴ�
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

    // i ���̿� �ش��ϴ� �Ӹ���� Ž��
    for (int i = s.length(); i > 0; i--) {
        // �ε�����ġ �Űܰ��� �ش� ���̸�ŭ�� ���ڿ��� �Ӹ��������?
        for (int j = 0; j + i <= s.length(); j++) {
            /*
            if (isPalindrom(j, j + i - 1, s)) {
                return i;
            }
            */
            int start = j; int end = j + i - 1;
            while (start <= end) {
                if (s[start] != s[end]) break;
                // ���� ���� �߰ߵ� �Ӹ������ ���� �� �Ӹ����
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