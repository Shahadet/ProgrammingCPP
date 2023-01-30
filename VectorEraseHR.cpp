#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,x,a,b,v;
    vector<int> vec;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        vec.push_back(v);
    }
    cin>>x;
    vec.erase(vec.begin()+(x-1));
    cin>>a>>b;
    vec.erase(vec.begin()+a-1,vec.begin()+b-1);
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        if(i==0)
            cout<<vec[i];
        else
            cout<<" "<<vec[i];
    }
        
    return 0;
}
