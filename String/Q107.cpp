//Minimum number of swaps for bracket balancing.
#include <iostream>
#include <string>
using namespace std;

int  swapCount(string &s) {
    int countLeft = 0, countRight = 0; 
    
    // swap stores the number of swaps 
    // required imbalance maintains 
    int swap = 0 , imbalance = 0; 
     
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '['){
            countLeft++; 
            if (imbalance > 0){
                
                // swaps count is last swap count + total 
                // number imbalanced brackets
                swap += imbalance; 
                
                // imbalance decremented by 1 as it solved
                // only one imbalance of Left and Right
                imbalance--;     
            }
        } 
        else if(s[i] == ']' ){
            countRight++; 
            
            // imbalance is reset to current difference 
            // between Left and Right brackets
            imbalance = (countRight - countLeft); 
        }
    }
    return swap;
}
int main(){
    string s = "[]][][";
    cout << swapCount(s) << endl;
    return 0;
}