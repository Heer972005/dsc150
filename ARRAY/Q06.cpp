// Find the Union and Intersection of the two sorted arrays.
// union with duplicates
#include <iostream>
#include <vector>
using namespace std;
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }

        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i])
        {
            res.push_back(b[j]);
            j++;
        }
        else
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        res.push_back(a[i]);
        i++;
    }

    while (j < m)
    {
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }
        res.push_back(b[j]);
        j++;
    }
    return res;
}
// intersection
vector<int> intersection(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int m = a.size();
    int n = b.size();

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res;
}
int main()
{
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
    vector<int> res = findUnion(a, b);
    vector<int> res1 = intersection(a, b);
    cout << "Union:";
    for (int x : res)
    {
        cout << x << " ";
    }
    cout << "\nintersection:";
    for (int i : res1)
        cout << i << " ";
    return 0;
}