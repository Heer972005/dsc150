//Check if all levels of two trees are anagrams or not.
/* Iterative program to check if two trees are level
  by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int data;
};

// function to get nodes at each level
void EachLevel(Node* root,
               unordered_map<int, vector<int> >& mm,
               int level)
{
    // base case
    if (!root)
        return;

    // adding node to its level
    mm[level].push_back(root->data);

    // increasing level
    level++;

    // moving left
    EachLevel(root->left, mm, level);

    // moving right
    EachLevel(root->right, mm, level);
}

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(unordered_map<int, vector<int> > mm1,
                 unordered_map<int, vector<int> > mm2)
{
    // map to help in checking anagram
    unordered_map<int, int> temp;

    // iterating each level of tree1
    for (auto x : mm1) {
        // storing node for current level
        for (auto y : x.second) {
            temp[y]++;
        }

        // checking if tree1 have node same as tree2
        // level or not
        for (auto y : mm2[x.first]) {
            if (!temp[y])
                return false;
            temp[y]--;
        }
    }

    // clearing map to check level of
    // tree2 as like tree1
    temp.clear();

    // iterating over tree2 levels
    for (auto x : mm2) {
        // storing each level nodes
        for (auto y : x.second) {
            temp[y]++;
        }

        // checking if tree2 have nodes at current
        // level as tree1
        for (auto y : mm1[x.first]) {
            if (!temp[y])
                return false;
            temp[y]--;
        }
    }

    return true;
}

// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // maps for both trees
    unordered_map<int, vector<int> > mm1, mm2;

    EachLevel(root1, mm1, 0);
    EachLevel(root2, mm2, 0);

    if (areAnagrams(mm1, mm2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

// This code is contributed by shubhamrajput6156.