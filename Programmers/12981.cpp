#include <string>
#include <vector>
#include <iostream>
#include <map>

const int T = 3;

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> cache;
    int len = words.size();
    // 이전 단어의 끝문자를 기록할 변수
    // 초기값은 첫 단어의 제일 앞문자로 지정
    char temp = words[0].front();
    
    for (int i = 0; i < len; i++) {
        // 1. 이미 나온 단어들 중 동일한 단어가 있는지 확인
        // 2. 이전 단어의 끝문자와 이번 단어의 앞문자가 같은지 확인
        if (!cache[words[i]] && words[i].front() == temp) {
            temp = words[i].back();
            cache[words[i]] = true;
        }
        // 순서대로 번호와 차례를 나타냄
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