#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MAX = 6;

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int len = cities.size();

    if (cacheSize == 0) return 5 * len;
    vector<string> cache;

    for (auto i : cities) {
        // 도시이름들을 모두 소문자로 변환
        transform(i.begin(), i.end(), i.begin(), ::tolower);
        // 캐시에서 도시를 찾는다.
        auto it = find(cache.begin(), cache.end(), i);
        // 캐시에 남은 공간을 계산한다.
        int free = cacheSize - cache.size();
        // 찾지 못했다면..
        if (it == cache.end()) {
            // 캐시에 남은 공간이 없다면 첫 원소를 제거한다.
            if (free == 0) cache.erase(cache.begin());
            answer += 5;
        }
        // 찾았다면..
        else {
            // 캐시에 남은 공간이 없다면 찾은 원소를 제거한다.
            if (free == 0) cache.erase(it);
            cache.push_back(i);
            answer++;
        }
    }

    return answer;
}

int main(void)
{
    vector<string> cities[MAX] = {
        { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" },
        { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" },
        { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" },
        { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" },
        { "Jeju", "Pangyo", "NewYork", "newyork" },
        { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }
    };
    pair<int, vector<string>> testCase[MAX] = {
        { 3, cities[0] },
        { 3, cities[1] },
        { 2, cities[2] },
        { 5, cities[3] },
        { 2, cities[4] },
        { 0, cities[5] }
    };

    for (int i = 0; i < MAX; i++) {
        cout << solution(testCase[i].first, testCase[i].second) << endl;
    }

    return 0;
}