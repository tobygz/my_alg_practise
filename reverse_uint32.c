class Solution {
public:
    int reverse(int x) {
        
        if(x >2147483647 || x <-2147483648){
            return 0;
        }
        bool bneg = false;
        if(x<0){
            bneg = true;
            x = x * -1;
        }
        
        int t = x;
        long ret = 0;
        int idx = 0;
        while(true){  
            ret =ret*10+ t % 10;            
            t = t /10;
            if(t==0)    {
                break;
            }
            idx++;
        }
        
        if(bneg){
            ret = -1*ret;
        }
        if(ret >2147483647 || ret <-2147483648){
            return 0;
        }
        return ret;
    }
};
