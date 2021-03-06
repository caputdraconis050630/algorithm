#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    while (!progresses.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses.at(i) += speeds.at(i);
        }

        if (progresses.at(0) >= 100)
        {
            int cnt = 0;
            bool flag = true;
            while (flag)
            {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt++;

                if (progresses.empty())
                {
                    flag = false;
                }
                else if (progresses.at(0) < 100)
                {
                    flag = false;
                }
            }

            answer.push_back(cnt);
        }
    }

    return answer;
}