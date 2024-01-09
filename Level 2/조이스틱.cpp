#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool b[21];

int solution(string name) {
    int answer = 0;

    for (int i = 0; i < name.size(); i++) {
        char c = name[i];
        if (c != 65) b[i] = true;
        answer += min(c - 65, 91 - c);
    }

    if (name = 1)

        return answer;
}

int main(void)
{
    cout << solution("JEROEN");
    return 0;
}
