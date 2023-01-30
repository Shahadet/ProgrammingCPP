#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //ifstream in("input.txt");
    //streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    //cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    //ofstream out("out.txt");
    //streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    //cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int a,b;
    cin>>a>>b;
    string temp;
    getline(cin,temp);
    map<string,string> tags;
    string tagName="";
    for(int i=0;i<a;i++){
        int lastIndex=0;
        getline(cin,temp);
        if(temp[1] =='/'){
            if(tagName.find_last_of('.') == string::npos)
                tagName = "";
            else
                tagName=tagName.substr(0,tagName.find_last_of('.'));
        }
        else{
            string currentTag="";
            lastIndex = 1;
            while(temp[lastIndex] != ' ' && temp[lastIndex] != '>')
            {
                currentTag+=temp[lastIndex];
                lastIndex++;
            }
            if(tagName=="")
                tagName = currentTag;
            else{
                tagName = tagName+'.'+currentTag;
            }
            if(temp[lastIndex] == '>')
                continue;

            //cout<<tagName<<endl;
            while(temp[lastIndex] != '>'){
                string attributeName="";
                string attributeValue="";
                //Generate Attribute name
                while(temp[lastIndex]==' ')
                    lastIndex++;

                while(temp[lastIndex]!=' ' && temp[lastIndex] !='='){
                    attributeName+=temp[lastIndex];
                    lastIndex++;
                }
                //cout<<"Attr Name: "<<attributeName<<endl;
                //Generate Atrribute value
                while(temp[lastIndex]!='\"')    //find first quote 
                    lastIndex++;
                
                lastIndex++;
                while(temp[lastIndex]!='\"')    //find last quote 
                {
                    attributeValue+=temp[lastIndex];
                    lastIndex++;
                }
                lastIndex++;
                //cout<<"Attr value: "<<attributeValue<<endl;
                tags[tagName+"~"+attributeName] = attributeValue;
            }
        }
    }

    for(int i = 0;i<b;i++){
        getline(cin,temp);
        auto it = tags.find(temp); 
        if ( it == tags.end() ) {  
        // not found  
            cout<<"Not Found!"<<endl;  
        }   
        else {  
            // found  
            cout <<it->second<< endl;  
        } 
    }
     
    //cin.rdbuf(cinbuf);   //reset to standard input again
    //cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}