#include <string>
#include <vector>

using namespace std;

void sum(vector<int>& ret, vector<int> v1, vector<int> v2,
    vector<int> v3, vector<int> v4) {
    for (int i = 0; i < 2; i++) {
        ret[i] = v1[i] + v2[i] + v3[i] + v4[i];
    }
}

vector<int> quad(int x, int y, int len, vector<vector<int>>& arr)
{
    vector<int> ret = { 0, 0 };
    
    // 압축 가능한지 검사
    int value = 0;
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (arr[i][j] == 1) value++;
        }
    }

    if (value == len * len) { // 압축
        return { 0, 1 };
    }
    else if (value == 0) { // 압축
        return { 1, 0 };
    }
    else { // 분할
        int half = len / 2;
        sum(ret, quad(x, y, half, arr), quad(x + half, y, half, arr),
            quad(x, y + half, half, arr), quad(x + half, y + half, half, arr));
    }
    return ret;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer = quad(0, 0, arr.size(), arr);
    return answer;
}

int main(void)
{
    vector<vector<int>> arr = { {1, 1, 0, 0},{1, 0, 0, 0},{1, 0, 0, 1},{1, 1, 1, 1} };
    vector<int> answer = solution(arr);
    printf("%d, %d", answer[0], answer[1]);

    return 0;
}