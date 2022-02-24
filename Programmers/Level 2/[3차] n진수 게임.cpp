#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<char> conv(int num, int n) {
    vector<char> ret;
    vector<int> v;
    while (true) {
        if (num == 0) break;
        v.push_back(num % n);
        num /= n;
    }
    for (vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); it++) {
        if (*it == 10) ret.push_back('A');
        if (*it == 11) ret.push_back('B');
        if (*it == 12) ret.push_back('C');
        if (*it == 13) ret.push_back('D');
        if (*it == 14) ret.push_back('E');
        if (*it == 15) ret.push_back('F');
        if (*it < 10) ret.push_back(*it + 48);
    }
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int i = 0;
    while (true) {
        if (i == 0) temp.push_back('0');
        else {
            vector<char> ret = conv(i, n);
            for (vector<char>::iterator it = ret.begin(); it < ret.end(); it++) {
                temp.push_back(*it);
            }
        }
        i++;
        if (temp.size() > t * m) break;
    }
    for (int i = 0; i < t * m; i++) {
        if ((i % m) == (p - 1)) answer.push_back(temp[i]);
    }
    return answer;
}

int main(void)
{
    cout << solution(16, 16, 2, 2);
    return 0;
}