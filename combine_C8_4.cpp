#include<vector>
#include<string.h>
#include<iostream>
using namespace std;

void CombinationCore(int* str, int len, vector<int> &rs, int nlen)
{
	if(len == 0)
	{
        if(rs.size() == nlen ){
            vector<int>::iterator it;
            for(it = rs.begin(); it < rs.end(); it++) {
                cout<<(*it) << ",";
            }
            cout<<endl;
        }
		return;
	}
	if(*str == '\0')
	return;
	rs.push_back(*str);
	CombinationCore(str + 1,len - 1,rs, nlen);
	rs.pop_back();
	CombinationCore(str + 1, len,rs, nlen);
}
void getCombination(int* str,int length, int nlen)
{
	if(!str ) {
        return;
    }
	vector<int> rs;
	for(int i = 1; i <= length; i++) {
        CombinationCore(str,i,rs, nlen);
    }
}
int main()
{
    int ary[] = {18, 16, 15, 14, 8, 7, 3, 1};
	getCombination(ary, 8, 4);
}
