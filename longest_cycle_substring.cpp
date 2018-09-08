/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include <iostream>
#include <stack>

using namespace std;

string longestPalindrome(string s) {
    int size = s.size();
    if(size<=1){
        return s;
    }
    stack<char> ms;
    stack<char> bkStack;
    string ret;
    int maxv=0;

    const char *p = (const char*)s.c_str();
    for(int i=0; i<size; i++ ){
        char c = *(p+i);
        if(ms.empty()){
            ms.push( c );
            continue;
        }
        char c1,c2;
        bool type_both = false;
        int type=-1;

both_loop:
        int j=i;
        int k=0;
        if(type_both){
            type_both = false;
        }
        while(true){                

            if(ms.empty()){
                break;
            }
            if(j+k>=size){
                break;
            }
            c1 = *(p+j+k);
            if( j+k+1 < size ){
                c2 = *(p+j+k+1);   
            }
            if(type == -1){
                if(j+k+1 < size && c2 == ms.top() ){
                    if(c1 == ms.top() ){
                        type_both = true;
                    }
                    type = 1;                    
                }else if ( c1 == ms.top() ){
                    type = 0;                 
                }else{
                    break;
                }
            }else{
                if(type == 0 ){                        
                    if( c1 != ms.top() ){
                        break;
                    }
                }else if( type == 1){
                    if(j+k+1 < size){
                        if(c2!=ms.top()){
                            break;
                        }
                    }else{
                        break;
                    }
                }                    
            }
            k++;
             
            bkStack.push(ms.top()); 
            ms.pop();           
        }


        if(k!=0){
            while(bkStack.empty()==false){
                ms.push( bkStack.top() );
                bkStack.pop();
            }
            int nowsize = 2*k+type;                
            if (maxv<=nowsize){
                maxv = nowsize;
                string tmp(p+i-k,nowsize);
                ret.assign(tmp);
            }
            string tmpa(p+i-k-type,nowsize);                
        }
        if(type_both){
            type = 0;
            goto both_loop;
        }

        ms.push(c);

    }
    if( ret.size() == 0){
        ret = *(p+size-1);
    }
    return ret;
}

int main(){
    const int size = 10;
    string val[] = {"","a","aa","aab","abba","abcba","abbacabba", "cddddc","caba","bananas"};
    for(int i=0;i<size;i++){
        string ret = longestPalindrome(val[i]);
        cout <<"input:"<<val[i]<< ", out ret:"<<ret<<endl;
    }

    return 0;
}
