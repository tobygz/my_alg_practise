#include <iostream>
#include <map>

using namespace std;

int min(int a, int b, int c) {
    int minv = 0;
    if(a<b){
        minv = a;
    }else{
        minv = b;
    }
    if(minv > c ){
        minv = c;
    }
    return minv;
}

int minDist(int i,int j, const string& s1, const string& s2) {
    if(i==-1){
        return j+1;
    }
    if(j==-1){
        return i+1;
    }
    if(s1[i] == s2[j]){
        return minDist(i-1,j-1,s1,s2);
    }
    return min( minDist(i,j-1,s1,s2), minDist(i-1,j,s1,s2), minDist(i-1,j-1,s1,s2) ) + 1;
}

int main(){
    string s1 = "horse";
    string s2 = "roe";
        int ret = minDist( s1.length(), s2.length(), s1, s2 );
        cout <<"ret:"<<ret<<endl;
        return 0;
}
