//https://leetcode-cn.com/problems/valid-parentheses/description/
class Solution {
public:
    bool isMatch(char c1, char c2){
        if(c1 == '(' && c2 == ')'){
            return true;
        }
        if(c1 == '[' && c2 == ']'){
            return true;
        }
        if(c1 == '{' && c2 == '}'){
            return true;
        }        
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        char *p = (char *)s.c_str();
        while(*p){            
            if(*p == '(' || *p == '[' || *p == '{') {
                st.push(*p);
            }else{ 
                if(st.empty()){
                    return false;
                }                
                if(isMatch(st.top(),*p)){
                    st.pop();
                }else{
                    return false;
                }
            }
            p++;
        }
        if(st.empty()==false){
            return false;
        }
        return true;
    }
};
