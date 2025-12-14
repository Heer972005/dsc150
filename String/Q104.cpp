//Longest Common Prefix
// C++ program to find the longest common prefix
// using Sorting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string>& arr) {

    // Sort the vector of strings
    sort(arr.begin(), arr.end());

    // Compare the first and last strings
    // in the sorted list
    string first = arr.front();
    string last = arr.back();
    int minLength = min(first.size(), last.size());

    int i = 0;
  
    // Find the common prefix between the first
    // and last strings
    while (i < minLength && first[i] == last[i]) {
        i++;
    }

    // Return the common prefix
    return first.substr(0, i);
}

int main() {
    vector<string> arr = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
    cout << longestCommonPrefix(arr) << endl;

    return 0;
}