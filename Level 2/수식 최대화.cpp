#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(vector<long long> numbers, vector<char> symbols, const vector<char>& order)
{
    for (int i = 0; i < 3; i++) {
        auto p = find(symbols.begin(), symbols.end(), order[i]);
        while (p != symbols.end()) {
            int l = p - symbols.begin();
            if (order[i] == '*') numbers[l] = numbers[l] * numbers[l + 1];
            else if (order[i] == '+') numbers[l] = numbers[l] + numbers[l + 1];
            else numbers[l] = numbers[l] - numbers[l + 1];
            numbers.erase(numbers.begin() + l + 1);
            symbols.erase(p);
            p = find(symbols.begin(), symbols.end(), order[i]);
        }
    }
    
    return abs(numbers[0]);
}

long long solution(string expression)
{
    long long answer = 0;

    int len = expression.length();

    vector<long long> numbers;
    vector<char> symbols;
    int pre = 0;
    // 문자열(수식) 탐색
    for (int i = 0; i < len; i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            numbers.push_back(stoi(expression.substr(pre, i - pre)));
            symbols.push_back(expression[i]);
            pre = i + 1;
        }
    }
    numbers.push_back(stoi(expression.substr(pre, len)));

    vector<char> order = { '*', '+', '-' };
    do {
        answer = max(answer, calc(numbers, symbols, order));
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}

int main(void)
{
    string expression[2] = { "100-200*300-500+20", "5Z0*6-3*2" };

    cout << solution(expression[0]) << endl;
    cout << solution(expression[1]) << endl;
        
    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(vector<long long> numbers, vector<char> symbols, const char* order)
{
    for (int i = 0; i < 3; i++) {
        auto p = find(symbols.begin(), symbols.end(), order[i]);
        while (p != symbols.end()) {
            int l = p - symbols.begin();
            if (order[i] == '*') numbers[l] = numbers[l] * numbers[l + 1];
            else if (order[i] == '+') numbers[l] = numbers[l] + numbers[l + 1];
            else numbers[l] = numbers[l] - numbers[l + 1];
            numbers.erase(numbers.begin() + l + 1);
            symbols.erase(p);
            p = find(symbols.begin(), symbols.end(), order[i]);
        }
    }

    return abs(numbers[0]);
}

long long solution(string expression)
{
    long long answer = 0;

    int len = expression.length();

    vector<long long> numbers;
    vector<char> symbols;
    int pre = 0;
    for (int i = 0; i < len; i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            numbers.push_back(stoi(expression.substr(pre, i - pre)));
            symbols.push_back(expression[i]);
            pre = i + 1;
        }
    }
    numbers.push_back(stoi(expression.substr(pre, len)));

    char order[6][3] = {
        { '*', '+', '-' },
        { '*', '-', '+' },
        { '+', '*', '-' },
        { '+', '-', '*' },
        { '-', '*', '+' },
        { '-', '+', '*' }
    };
    for (int i = 0; i < 6; i++) {
        answer = max(answer, calc(numbers, symbols, order[i]));
    }

    return answer;
}
*/