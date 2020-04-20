#include<vector>
#include<string.h>
#include<iostream>
using namespace std;


void swap(vector<int> &vec, int i, int j){
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

void permute(vector<int>& vec, int start){
    if(start == vec.size()-1){
        for(int i=0;i<vec.size();++i){
            cout << vec[i] <<",";
        }
        cout<<endl;
        return;
    }

    for(int i=start;i<vec.size();++i){
        swap(vec, i, start);
        getComb(vec, i+1 );
        swap(vec, i, start);
    }
}

int main()
{
    vector<int> vec;
    for(int i=0;i<5;i++){
        vec.push_back(i);
    }
    permute(vec,0);
}
