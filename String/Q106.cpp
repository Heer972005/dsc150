//Find the first repeated word in string.
// CPP program for finding first repeated
// word in a string
#include <bits/stdc++.h>
using namespace std;

// returns first repeated word
string findFirstRepeated(string s)
{
    // break string into tokens
    // and then each string into set
    // if a word appeared before appears
    // again, return the word and break

    istringstream iss(s);
    string token;

    // hashmap for storing word and its count
    // in sentence
    unordered_map<string, int> setOfWords;

    // store all the words of string
    // and the count of word in hashmap

    while (getline(iss, token, ' ')) {
        if (setOfWords.find(token) != setOfWords.end())             
            setOfWords[token] += 1;  // word exists
        else 
            // insert new word to set
            setOfWords.insert(make_pair(token, 1));        
    }

    // traverse again from first word of string s
    // to check if count of word is greater than 1

    // either take a new stream or store the words 
    // in vector of strings in previous loop
    istringstream iss2(s);
    while (getline(iss2, token, ' ')) {
        int count = setOfWords[token];
        if (count > 1) {
            return token;
        }
    }

    return "NoRepetition";
}

// driver program
int main()
{
    string s("Ravi had been saying that he had been there");
    string firstWord = findFirstRepeated(s);
    if (firstWord != "NoRepetition")
        cout << "First repeated word :: " 
             << firstWord << endl;
    else
        cout << "No Repetitionn";
    return 0;
}