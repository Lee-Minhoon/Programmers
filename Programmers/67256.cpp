#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> keypad[12] = {
    {3, 1}, {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2},
    {3, 0}, {3, 2}
};

int dis(pair<int, int> a, pair<int, int> b)
{
    int y1 = a.first; int y2 = b.first;
    int x1 = a.second; int x2 = b.second;
    return abs(y1 - y2) + abs(x1 - x2);
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int leftLoc = 10;
    int rightLoc = 11;

    for (auto i : numbers) {
        string res;
        // 누르는 번호가 1, 4, 7이라면..
        if (i == 1 || i == 4 || i == 7) res = "left";
        // 누르는 번호가 3, 6, 9라면..
        else if (i == 3 || i == 6 || i == 9) res = "right";
        // 누르는 번호가 2, 5, 8, 0이라면..
        else {
            int leftDis = dis(keypad[leftLoc], keypad[i]);
            int rightDis = dis(keypad[rightLoc], keypad[i]);
            // 거리를 따져본다.
            if (leftDis < rightDis) res = "left";
            else if (rightDis < leftDis) res = "right";
            else {
                if (hand == "left") res = "left";
                else res = "right";
            }
        }
        if (res == "left") {
            leftLoc = i;
            answer += 'L';
        }
        else {
            rightLoc = i;
            answer += 'R';
        }
    }

    return answer;
}

int main(void)
{
    pair<string, vector<int>> numbers[3] = {
        {"right", {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}},
        {"left", {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}},
        {"right", {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}}
    };

    for (int i = 0; i < 3; i++) {
        cout << solution(numbers[i].second, numbers[i].first) << endl;
    }

    return 0;
}