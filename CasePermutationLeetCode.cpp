
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<string> allString2;
    void letterPermutation(string s,int i) {
        if(s.length() == i){
            //cout<<"Adding: "<<s<<endl;
            allString2.push_back(s);
            return;
        }
        if(s[i]>='0' && s[i]<= '9'){
            while(s[i]>='0' && s[i]<= '9'){
                i++;
            }
            letterPermutation(s,i);
        }
        else{
            i++;
            letterPermutation(s,i);
            if(isupper(s[i-1])){
                s[i-1] = tolower(s[i-1]);

            }
            else{
                s[i-1] = toupper(s[i-1]);
            }
            letterPermutation(s,i);
        }
        return;

    }
    vector<string> letterCasePermutation(string s) {
        Solution::letterPermutation(s,0);
        return allString2;
    }
};


int main() {
   Solution s;
   vector<string> allString2 = s.letterCasePermutation("a1b1c");
   for(string strng : allString2){
    cout<<strng;
   }
   return 0;
}