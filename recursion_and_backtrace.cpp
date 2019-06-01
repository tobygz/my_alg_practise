#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//全排列
void gene_permute(int n,vector<int>& nums, vector<vector<int> >& ret){
	if(n==nums.size()){
		ret.push_back(nums);
	}else{
		for(int i=n;i<nums.size();i++){
			int tmp=nums[i];nums[i]=nums[n];nums[n]=tmp;
			gene_permute(n+1,nums,ret);
			tmp=nums[i];nums[i]=nums[n];nums[n]=tmp;
		}
	}
}
vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<int> > ret;
	gene_permute(0,nums,ret);
	return ret;
}

void permute_test(int num){
	vector<int> nums;
	for(int i=0;i<num;i++){
		nums.push_back(i);
	}
	vector<vector<int> > ret = permute(nums);

	printf("size of %d's permute is : %ld\n",num, ret.size());
	printf("--------------------------\n");
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			printf("%d,", ret[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
}

//求子集方法1
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<int> tmp;
	vector<vector<int> > ret;
	set< vector<int> > dupSet;
	ret.push_back(tmp);
	std::sort(nums.begin(), nums.end());
	geneSubsets(0,tmp,nums,ret, dupSet);
	return ret;
}

void geneSubsets(int n,vector<int>& tmp,vector<int>& nums, vector<vector<int> >& ret,set<vector<int> >& dupSet){
	if(n>=nums.size()){
		return;
	}
	tmp.push_back(nums[n]);
	if(dupSet.find(tmp)==dupSet.end()){
		ret.push_back(tmp);
		dupSet.insert(tmp);
	}
	geneSubsets(n+1,tmp,nums,ret,dupSet);
	tmp.pop_back();
	geneSubsets(n+1,tmp,nums,ret,dupSet);
}

void subset_test(int num){
	vector<int> nums;
	for(int i=0;i<num;i++){
		nums.push_back(i);
	}
	auto ret = subsetsWithDup(nums);
	printf("\n--------------------------\n");
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			printf("%d,", ret[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n\n");
}
//求子集方法2
vector<vector<int>> subsetsWithDup_vbetter(vector<int>& nums) {
	vector<int> tmp;
	vector<vector<int> > ret;
	ret.push_back(tmp);
	std::sort(nums.begin(), nums.end());
	for(int i=1;i<=nums.size();i++){
		geneSubset_vbetter(i,0,nums,tmp,ret);
	}
	return ret;
}
void geneSubset_vbetter(int k,int start,vector<int>& nums,vector<int>& tmp, vector<vector<int> >& ret){
	if(tmp.size()>=k){
		ret.push_back(tmp);
		return;
	}
	for(int i=start;i<nums.size();i++){
		if(i!=start&& nums[i]==nums[i-1]){
			continue;
		}
		tmp.push_back(nums[i]);
		geneSubset_vbetter(k,i+1,nums,tmp,ret);
		tmp.pop_back();
	}
}

int main(){
	//permute_test(3);
	subset_test(3);
	return 0;
}
