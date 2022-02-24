#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;

    string delim[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 0; i < 10; i++) {
        while (s.find(delim[i]) != string::npos) {
            s.replace(s.find(delim[i]), delim[i].length(), to_string(i));
        }
    }
    
    answer = stoi(s);

    return answer;
}

int main(void)
{
    string s[4] = {
        "one4seveneight", "23four5six7", "2three45sixseven", "123"
    };

    for (int i = 0; i < 4; i++) {
        cout << solution(s[i]) << endl;
    }

    return 0;
}