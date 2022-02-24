#include <string>
#include <vector>
#include <iostream>
#include <map>

const int T = 3;

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> cache;
    int len = words.size();
    // ���� �ܾ��� �����ڸ� ����� ����
    // �ʱⰪ�� ù �ܾ��� ���� �չ��ڷ� ����
    char temp = words[0].front();
    
    for (int i = 0; i < len; i++) {
        // 1. �̹� ���� �ܾ�� �� ������ �ܾ �ִ��� Ȯ��
        // 2. ���� �ܾ��� �����ڿ� �̹� �ܾ��� �չ��ڰ� ������ Ȯ��
        if (!cache[words[i]] && words[i].front() == temp) {
            temp = words[i].back();
            cache[words[i]] = true;
        }
        // ������� ��ȣ�� ���ʸ� ��Ÿ��
        else return { i % n + 1, i / n + 1 };
    }

    return { 0, 0 };
}

int main(void)
{
    vector<string> words[T] = {
        {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"},
        {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"},
        {"hello", "one", "even", "never", "now", "world", "draw"}
    };
    pair<int, vector<string>> testCase[T] = {
        {3, words[0]},
        {5, words[1]},
        {2, words[2]}
    };

    for (int i = 0; i < T; i++) {
        vector<int> temp = solution(testCase[i].first, testCase[i].second);
        for (int j = 0; j < 2; j++) {
            cout << temp[j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> cache[50];
    int idx = 1;
    char temp = words[0].front();
    for (auto i : words) {
        int len = i.length();
        auto it = find(cache[len].begin(), cache[len].end(), i);
        if (it == cache[len].end() && i.front() == temp) {
            cache[len].push_back(i);
            temp = i.back();
            idx++;
        }
        else {
            answer.push_back((idx - 1) % n + 1);
            answer.push_back((idx - 1) / n + 1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
*/