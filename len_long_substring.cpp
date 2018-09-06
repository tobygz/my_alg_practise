#include <iostream>
#include <map>
using namespace std;

map<char,int> mark;
bool has(char c) {
    map<char,int>::iterator it = mark.find(c);
    if( it == mark.end() ){
        return false;
    }
    return true;
}

void rm(char c){
    map<char,int>::iterator it = mark.find(c);
    if(it==mark.end()){
        return;
    }
    cout <<" rm " << it->first << endl;
    mark.erase(it);

}

int lengthOfLongestSubstring(string s) {
    char *p = (char *)s.c_str();
    char *pf = p; 
    int maxv = 0;
    int size = s.size();
    for(int i=0;i<size;i++){                        
        if( has(*(p+i)) ){
            if(mark.size()>maxv){ 
                maxv = mark.size();
            } 
            while(true){                    
                rm(*pf);                                        
                if( *pf == *(p+i) ){
                    break;
                }
                pf++;
            }
            pf++;
        }
        mark[*(p+i)] = true;            
    }
    if( mark.size() > maxv ){ maxv = mark.size(); }

    return maxv;
}

int main(){
    //string str = "aabaab!bb";
    //string str = "aab";
    //string str = "aabaabc";
    string str = "aabaab!bb";
    int ret = lengthOfLongestSubstring(str);
    cout << "return :"<<ret<<endl;
    return 0;
}
