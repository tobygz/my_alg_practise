class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==""){
            return 0;
        }
        char *p = (char *) haystack.c_str();
        char *pd = (char *) needle.c_str();
        
        int idx = 0;
        while(true){
            
            int j=0, i=idx;
            while(true){
                if( *(pd+j) == 0 ){
                    return idx;
                }
                if( *(p+i) == 0 ){
                    return -1;
                }
                if( *(p+i++) != *(pd+j++) ){
                    break;                    
                }                
            }
            idx++;
            if( *(p+idx) == 0 ){
                return -1;
            }
        }
    }
};
