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
        // �����̸����� ��� �ҹ��ڷ� ��ȯ
        transform(i.begin(), i.end(), i.begin(), ::tolower);
        // ĳ�ÿ��� ���ø� ã�´�.
        auto it = find(cache.begin(), cache.end(), i);
        // ĳ�ÿ� ���� ������ ����Ѵ�.
        int free = cacheSize - cache.size();
        // ã�� ���ߴٸ�..
        if (it == cache.end()) {
            // ĳ�ÿ� ���� ������ ���ٸ� ù ���Ҹ� �����Ѵ�.
            if (free == 0) cache.erase(cache.begin());
            answer += 5;
        }
        // ã�Ҵٸ�..
        else {
            // ĳ�ÿ� ���� ������ ���ٸ� ã�� ���Ҹ� �����Ѵ�.
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