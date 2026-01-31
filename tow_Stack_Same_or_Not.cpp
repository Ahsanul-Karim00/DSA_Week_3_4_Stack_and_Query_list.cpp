#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    list<int> l;
    void push(int val)
    {
        // if(l.size()>=100000)
        // {
        //     return;
        // }
        l.push_back(val);
    }
    void pop()
    {
        if (!l.empty())
        {
            l.pop_back();
        }
    }
    int top()
    {
        if (!l.empty())
        {
            return l.back();
        }
        return -1;
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
    }
};
int main()
{
    Stack s1, s2;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s1.push(val);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        s2.push(val);
    }
    if (n != m)
    {
        cout << "NO" << endl;
    }
    else
    {
        bool flag = true;
        while(n--)
        // while(!s1.empty() && !s2.empty())
        // while(s1.empty() == false && s2.empty() == false )
        // while (s1.size() > 0 && s2.size() > 0)
        {
            if (s1.top() != s2.top())
            {
                flag = false;
                break;
            }
            s1.pop();
            s2.pop();
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

// Input 
// 5
// 10 20 30 40 50
// 5
// 10 20 30 40 50 
// output 
// YES
