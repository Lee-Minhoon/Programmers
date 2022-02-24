#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 21

int answer = 0;
int value = 0;

void DFS(int node, vector<int>& numbers, int target)
{
    if (node == numbers.size()) {
        if (value == target) {
            answer++;
        }
        return;
    }

    value += numbers[node];
    DFS(node + 1, numbers, target);
    value -= numbers[node];

    value -= numbers[node];
    DFS(node + 1, numbers, target);
    value += numbers[node];

    return;
}

int solution(vector<int> numbers, int target) {
    DFS(0, numbers, target);
    return answer;
}

int main(void)
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    cout << solution(numbers, 3);
    return 0;
}
