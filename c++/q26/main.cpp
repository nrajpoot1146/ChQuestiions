//#include "pch.h"
#include <deque>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

deque<int> josephusDQ(int n, int k)
{
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
        dq.push_back(i);
    int kill = 0;
    while (dq.size() >= k)
    {
        kill++;
        int front = dq.front();
        dq.pop_front();
        if (kill == k)
            kill = 0;
        else
            dq.push_back(front);
    }
    return dq;
}

int josephusR(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (josephusR(n - 1, k) + k) % n;
}

vector<int> josephusQ(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int kill = 0;
    while (q.size() >= k)
    {
        kill++;
        int front = q.front();
        q.pop();
        if (kill == k)
            kill = 0;
        else
            q.push(front);
    }
    vector<int> v;
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

int main()
{
    vector<int> survivorsR;
    for (int k = 1; k <= 41; ++k)
        survivorsR.push_back(k);
    int survivorR = josephusR(41, 3);
    vector<int> survivorsQ = josephusQ(41, 3);
    deque<int> survivorsDQ = josephusDQ(41, 3);
    cout << survivorsR[survivorR] << endl;
    copy(survivorsQ.begin(), survivorsQ.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(survivorsDQ.begin(), survivorsDQ.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
