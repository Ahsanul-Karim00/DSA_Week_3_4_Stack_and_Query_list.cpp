#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    queue<int> q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    if (n != m)
    {
        cout << "NO" << endl;
    }
    else
    {
        bool flag = true;
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
            {
                flag = false;
                break;
            }
            st.pop();
            q.pop();
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
// /Input
// 5 5
// 10 20 30 40 50
// 50 40 30 20 10

// output 
// YES
// Input
// 4 4
// 10 20 30 40
// 10 20 30 40


// output 
// NO