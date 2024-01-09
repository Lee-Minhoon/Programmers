#include<vector>
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int solution(int no, vector<int> works)
{
    int answer = 0;

    // �ִ���
    priority_queue<int, vector<int>> heap;

    // ���� �� �ִ���
    for (auto i : works) {
        heap.push(i);
    }

    for (int i = 0; i < no; i++) {
        // ���� ���� ���� �۾������� 1��ŭ ó��
        int max = heap.top();
        if (max == 0) {
            return 0;
        }
        max--;
        heap.pop();
        // �۾��� ����
        heap.push(max);
    }

    // ��� ��� ���
    while (!heap.empty()) {
        int cost = heap.top();
        answer += pow(cost, 2);
        heap.pop();
    }

    return answer;
}

int main(void)
{
    cout << solution(2, { 3,3,3 });

    return 0;
}