#include "bits/stdc++.h"
using namespace std;

int possible(int N, bool is_broken[])
{
    int len = 0;
    do
    {
        if (is_broken[N % 10])
        {
            return 0;
        }
        len++;
        N /= 10;
    } while (N);
 
    return len;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int NOW = 100;
    const int MAX = 1'000'000;
 
    // 입력
    int N, M;
    cin >> N >> M;
    bool is_broken[10] = { 0, };
    
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        is_broken[tmp] = true;
    }
 
    // 현재 채널에서 +/- 버튼만으로 이동하는 횟수
    int cnt = abs(N - NOW);
 
    for (int i = 0; i <= MAX; i++)
    {
        // i를 이루는 숫자 중 고장난 버튼이 없으면, 숫자길이 반환
        int len = possible(i, is_broken);
        if (len)
        {
            // 버튼 누르는 횟수가 더 작으면
            if (cnt > abs(N - i) + len)
            {
                cnt = abs(N - i) + len;
            }
        }
    }
 
    cout << cnt;
 
    return 0;
}