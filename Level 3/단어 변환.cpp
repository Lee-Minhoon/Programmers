#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
bool visited[51];
int depth = 0;

void DFS(string begin, string target, vector<string>& words)
{
    if (answer == 0 && begin == target) {
        answer = depth;
    }
    if (begin == target) {
        answer = min(answer, depth);
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i]) {
            int check = begin.size();
            for (int j = 0; j < begin.size(); j++) {
                if (begin[j] != words[i][j]) check--;
            }
            if (check + 1 == begin.size()) {
                visited[i] = true;
                depth++;
                DFS(words[i], target, words);
                visited[i] = false;
                depth--;
            }
        }
    }

    return;
}


int solution(string begin, string target, vector<string> words) {
    DFS(begin, target, words);
    return answer;
}

int main(void)
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
    return 0;
}
