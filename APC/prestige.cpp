#include <bits/stdc++.h>

using namespace std;

void flip1(int *a, int *b, int l, int r)
{
    l -= 1;
    r -= 1;
    int p = 0, q = 0, temp;
    // cout << l << r << endl;
    for (int i = l; i <= r; i++)
    {
        temp = a[i];
        a[i] = b[r - p];
        b[r - p] = temp;
        p++;
    }
}

void flip2(int *a, int *b, int k, int n)
{
    int r = k - 1;
    int temp;
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        temp = a[i];
        a[i] = b[r - p];
        b[r - p] = temp;
        p++;
    }
}

int step3(int *fu, int *su, int a, int b, int c, int d)
{
    a--;
    // b--;
    c--;
    // d--;
    int times = d - c;
    int counter = 0;
    while(times--)
    {
        counter += fu[c] * su[a];
        c++;
        a++;
    }
    return counter;
}

int main()
{
    int n, m, l, r, a, b, c, d, k;
    int step;
    cin >> n >> m;
    int *firstU = new int[n];
    int *firstD = new int[n];
    int *secondU = new int[n];
    int *secondD = new int[n];
    for (int i = 0; i < n; i++)
        cin >> secondU[i];
    for (int i = 0; i < n; i++)
    {
        cin >> secondD[i];
        firstU[i] = 1;
        firstD[i] = -1;
    }
    while (m--)
    {
        cin >> step;

        switch (step)
        {
        case 1:
            // cout << step;
            cin >> l >> r;
            flip1(secondU, secondD, l, r);
            break;
        case 2:
            // cout << step;
            cin >> k;
            flip2(firstU, firstD, k, n);
            // for (int i = 0; i < n; i++)
            //     cout << firstU[i] << " " << firstD[i] << endl;
            break;
        case 3:
            // cout << step;
            cin >> a >> b >> c >> d;
            cout << step3(firstU, secondU, a, b, c, d) << endl;
            break;
        default:
            break;
        }
    }
    // flip2(firstU, firstD, 4, n);
    // for (int i = 0; i < n; i++)
    //     cout << secondU[i] << " " << secondD[i] << endl;

    // for (int i = 0; i < n; i++)
    //     cout << firstU[i] << " " << firstD[i] << endl;

    return 0;
}

// 7 2
// 3 5 0 2 5 7 4
// 2 8 4 4 0 1 6

// 7 9
// 3 5 0 2 5 7 4
// 2 8 4 4 0 1 6
// 3 1 3 3 5
// 2 1
// 1 2 6
// 1 2 7
// 2 3
// 3 1 5 3 7
// 3 1 7 1 7
// 1 1 6
// 3 1 7 1 7 



// 8 16 10 21