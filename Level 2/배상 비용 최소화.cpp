#include<vector>
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int solution(int no, vector<int> works)
{
    int answer = 0;

    // 최대힙
    priority_queue<int, vector<int>> heap;

    // 벡터 → 최대힙
    for (auto i : works) {
        heap.push(i);
    }

    for (int i = 0; i < no; i++) {
        // 제일 많이 남은 작업량부터 1만큼 처리
        int max = heap.top();
        if (max == 0) {
            return 0;
        }
        max--;
        heap.pop();
        // 작업량 갱신
        heap.push(max);
    }

    // 배상 비용 계산
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