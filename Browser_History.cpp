#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<string> route;
    string station;
    while (cin >> station)
    {
        if (station == "end")
        {
            break;
        }
        route.push_back(station);
    }
    // for(string st : route)
    // {
    //     cout << st << endl;
    // }
    auto currect_station = route.end();
    int query;
    cin >> query;
    while (query--)
    {
        string command;
        cin >> command;
        bool flag = false;
        if (command == "visit")
        {
            string find_st_name;
            cin >> find_st_name;
            for (auto it = route.begin(); it != route.end(); it++)
            {
                if (*it == find_st_name)
                {
                    cout << find_st_name << endl;
                    currect_station = it;
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            // next of current station
            if (currect_station == route.end() || next(currect_station) == route.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                cout << *next(currect_station) << endl;
                currect_station = next(currect_station);
            }
        }
        else if (command == "prev")
        {
            // previous of Currect station
            if (currect_station == route.begin() || currect_station == route.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                cout << *prev(currect_station) << endl;
                currect_station = prev(currect_station);

            }
        }
    }
    return 0;
}
//Input
// facebook google phitron youtube twitter end
// 12
// visit phitron
// prev
// prev
// prev
// prev
// next
// visit twitter
// next
// next
// prev
// visit django
// prev

//output
// phitron
// google
// facebook
// Not Available
// Not Available
// google
// twitter
// Not Available
// Not Available
// youtube
// Not Available
// phitron

