// reverse the an array
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr)
{
    for (int i = arr.size(); i > 0; i--)
    {
        cout << i << " ";
    }
}
int main()
{
    int n;
    cout << "enter the size:";
    cin >> n;
    cout << "enter the elements:\n";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        arr.push_back(vl);
    }
    reverse(arr);
    return 0;
}