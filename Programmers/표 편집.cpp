#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<bool> v(n, true);
    vector<int> stack;

    int pos = k;
    int end = n - 1;
    for (auto i : cmd) {
        cout << i << endl;
        if (i[0] == 'U') {
            int x = stoi(i.substr(2, i.size() - 2));
            while (x != 0) {
                auto p = find(v.rbegin() - (pos - n), v.rend(), true);
                pos = abs(p - v.rend() + 1);
                x--;
            }
        }
        else if (i[0] == 'D') {
            int x = stoi(i.substr(2, i.size() - 2));
            while (x != 0) {
                auto p = find(v.begin() + pos + 1, v.end(), true);
                pos = abs(v.begin() - p);
                x--;
            }
        }
        else if (i[0] == 'C') {
            stack.push_back(pos);
            v[pos] = false;
            if (pos == end) {
                auto p = find(v.rbegin(), v.rend(), true);
                end = abs(p - v.rend() + 1);
                pos = abs(p - v.rend() + 1);
            }
            else {
                auto p = find(v.begin() + pos, v.end(), true);
                pos = abs(v.begin() - p);
            }
            
        }
        else {
            if (stack.back() >= end) end = stack.back();
            v[stack.back()] = true;
            stack.pop_back();
        }
        cout << pos << ' ' << end << endl;
        vector<string> tmp = { "무지", "콘", "어피치", "제이지", "프로도", "네오", "튜브", "라이언" };
        int t = 0;
        for (auto i : v) {
            if (i) {
                cout << tmp[t] << endl;
            }
            t++;
        }
        cout << endl;
    }


    for (auto i : v) {
        if (i) answer += "O";
        else answer += "X";
    }

    return answer;
}

int main(void)
{
    cout << solution(8, 0, { "D 6", "C", "U 1", "C", "C", "C", "Z", "Z" }) << endl;
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" }) << endl;
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });
    return 0;
}