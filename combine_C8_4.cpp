#include<vector>
#include<string.h>
#include<iostream>
using namespace std;


void swap(vector<int> &vec, int i, int j){
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

void all_permute(vector<int> vec, int start, vector< vector<int> >& res){
    if(start == vec.size()-1){
        res.push_back(vec);
        return;
    }

    for(int i=start;i<vec.size();++i){
        swap(vec, i, start);
        all_permute(vec, start+1, res );
        swap(vec, i, start);
    }
}

void combine(vector<int> vec, const vector<int>& arr, int start,int len, vector< vector<int> >& res){
    if(vec.size() == len){
        res.push_back(vec);
        for(int i=0;i<vec.size(); i++){
            if(i!=0){ cout <<","; }
            cout << vec[i] ;
        }
        cout << endl;
        return;
    }

    for(int i=start;i<arr.size();++i){
        vec.push_back( arr[i] );
        combine(vec, arr, i+1, len, res );
        vec.pop_back();
    }
}

void test_permute(int _num){
    vector<int> vec;
    vector< vector<int> > res;
    for(int i=0;i<_num;i++){
        vec.push_back(i);
    }
    all_permute(vec,0, res);
    cout <<"res size:" << res.size() <<endl;
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            if(j!=0){
                cout <<",";
            }
            cout << res[i][j];
        }
        cout << endl;
    }
}

void test_combine(int _num){
    vector<int> arr;
    for(int i=0;i<_num;i++){
        arr.push_back(i);
    }

    vector<int> vec;
    vector< vector<int> > res;
    combine(vec, arr, 0, _num/2, res );

}

int main()
{
    //test_permute(3);
    test_combine(4);
}

/*
   res size:6
   0,1,2
   0,2,1
   1,0,2
   1,2,0
   2,1,0
   2,0,1
   */
