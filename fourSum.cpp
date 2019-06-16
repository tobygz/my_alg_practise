class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()<4){
            return res;
        }
        std::sort(nums.begin(), nums.end());
        int ss = nums.size();
        for(int i=0;i<nums.size()-3;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target){
                break;
            }
            if(nums[ss-4]+nums[ss-3]+nums[ss-2]+nums[ss-1] <target){
                break;
            }
            if(nums[i] + nums[ss-3] + nums[ss-2]+nums[ss-1] < target){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){  
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target){
                    break;
                }
                if(nums[i]+nums[j]+nums[ss-2] + nums[ss-1] < target){
                    continue;
                }
                int nowval = nums[i]+nums[j];
                int ntarget = target - nowval;
                //find the pair
                int r = j+1, l=nums.size()-1;
                int sum = 0;
                while(r<l){
                    sum = nums[r] + nums[l];
                    if( sum == ntarget){
                        vector<int> add;
                        add.push_back(nums[i]);
                        add.push_back(nums[j]);
                        add.push_back(nums[r]);
                        add.push_back(nums[l]);
                        res.push_back({nums[i], nums[j],nums[r],nums[l]});
                        while(r<l && nums[r]==add[2]) r++;
                        while(r<l && nums[l]==add[3]) l--;
                    }else if(sum < ntarget) {
                        r++;
                    }else{
                        l--;
                    }
                }
                while(j<ss-1&&nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<ss-1&&nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};

/*
执行用时 : 8 ms , 在所有C++提交中击败了 99.96% 的用户
内存消耗 : 9.4 MB , 在所有C++提交中击败了 74.24% 的用
*/
