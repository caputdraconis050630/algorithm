#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << "\n";
    }
}