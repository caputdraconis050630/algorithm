#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1002];
int mod = 10007;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        d[i] = (d[i - 2] + d[i - 1]) % mod;
    }

    cout << d[n] % 10007 << "\n";
    return 0;
}