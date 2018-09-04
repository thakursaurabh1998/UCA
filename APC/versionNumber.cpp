#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void trimZero(vector<string> *o)
{
    for (int i = 0; i < o->size(); i++)
    {
        for (int j = 0; (j < o->at(i).size()) && (o->at(i).size() > 1); j++)
        {
            if (o->at(i)[j] == '0')
            {
                // cout << "ok" << i << j;
                o->at(i) = o->at(i).substr(1);
                // cout << o->at(i) << endl;
                j = -1;
            }
            else
                break;
        }
    }
}

int versionCompare(string s1, string s2)
{
    vector<string> v1;
    vector<string> v2;
    int pos = 0;
    int len = -1;
    int n = s1.length();
    while (len < n)
    {
        int found = s1.find('.', len + 1);
        if (found >= 0)
        {
            v1.push_back(s1.substr(len + 1, found - len - 1));
            len = found;
        }
        else
        {
            v1.push_back(s1.substr(len + 1, n - len));
            len = n;
        }
    }
    n = s2.length();
    len = -1;
    while (len < n)
    {
        int found = s2.find('.', len + 1);
        if (found >= 0)
        {
            v2.push_back(s2.substr(len + 1, found - len - 1));
            len = found;
        }
        else
        {
            v2.push_back(s2.substr(len + 1, n - len));
            len = n;
        }
    }

    trimZero(&v1);
    trimZero(&v2);

    for (string i : v1)
        cout << i << endl;

    cout << endl;

    for (string i : v2)
        cout << i << endl;

    cout << endl;

    n = min(v1.size(), v2.size());
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (v1.at(i).length() > v2.at(i).length())
            return 1;
        else if (v1.at(i).length() < v2.at(i).length())
            return -1;
        int size = min(v1.at(i).length(), v2.at(i).length());
        for (j = 0; j < size; j++)
        {
            if (v1.at(i)[j] > v2.at(i)[j])
                return 1;
            else if (v1.at(i)[j] < v2.at(i)[j])
                return -1;
        }
        if (v1.at(i).length() > v2.at(i).length())
            return 1;
        else if (v1.at(i).length() < v2.at(i).length())
            return -1;
    }

    if (v1.size() > v2.size())
    {
        for (i; i < v1.size(); i++)
        {
            if (v1.at(i) != "0")
                return 1;
        }
        return 0;
    }
    else if (v1.size() < v2.size())
    {
        for (i; i < v2.size(); i++)
        {
            if (v2.at(i) != "0")
                return -1;
        }
        return 0;
    }

    return 0;
}

int main()
{
    vector<string> s = {"4444371174137455", "5.168", "1.9.0.0", "1.456.0.0", "1.00.13.0400.00504.321.4567.0965.345.23", "1.13.4"};
    // for (string i : s)
    //     cout << i << endl;
    // Solution *obj = new Solution();
    cout << versionCompare(s.at(2), s.at(3));

    return 0;
}
