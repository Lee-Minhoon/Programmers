#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int> lostSet(lost.size() + reserve.size());
    auto it = set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), lostSet.begin());
    lostSet.erase(it, lostSet.end());

    int answer = n - lostSet.size();

    vector<int> reserveSet(lost.size() + reserve.size());
    it = set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), reserveSet.begin());
    reserveSet.erase(it, reserveSet.end());

    vector<int>::iterator re = reserveSet.begin();
    for (it = lostSet.begin(); it < lostSet.end(); it++) {
        for (re; re < reserveSet.end(); re++) {
            if (*it + 1 < *re) break;
            if (*it - 1 == *re || *it + 1 == *re) {
                answer++;
                re++;
                break;
            }
        }
    }

    return answer;
}

int main(void)
{
    cout << solution(12, { 1,2,7,8,9 }, { 1,4,5,6,8,9,10 });
    return 0;
}