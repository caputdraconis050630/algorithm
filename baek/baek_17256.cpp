#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int a_x, a_y, a_z;
    int c_x, c_y, c_z;
    cin >> a_x >> a_y >> a_z;
    cin >> c_x >> c_y >> c_z;

    cout << c_x - a_z << " " << c_y / a_y << " " << c_z - a_x << "\n";
}