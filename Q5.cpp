// Move all negative numbers to beginning and positive to end with constant extra space
#include <bits/stdc++.h>
using namespace std;

vector<int> move(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}