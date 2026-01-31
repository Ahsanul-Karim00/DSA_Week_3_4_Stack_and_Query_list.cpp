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
class myqueue
{
    public:
    list<int> l2;

    void push(int val)    // O(1)
    {
        l2.push_back(val);
    }
    void pop()         // O(1)
    {
        if (!l2.empty())
        {
            l2.pop_front();
        }
    }
    int front()         // O(1)
    {
        if(!empty())
        {
            return l2.front();

        }
        return -1;
    }
    
    int size()         // O(1)
    {
        return l2.size();
    }
    bool empty()       // O(1)
    {
        return l2.empty();
    }

};

int main()
{
    Stack s1;
    myqueue q2;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s1.push(val);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q2.push(val);
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
            if (s1.top() != q2.front())
            {
                flag = false;
                break;
            }
            s1.pop();
            q2.pop();
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

//Input
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

