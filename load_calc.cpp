#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include<map>
using namespace std;


int print_all(float floan, int iyear, float frate, map<int,int>& mp) {
	float fMonthRate = frate / 12 / 100;
	int iMonth = iyear * 12;
	float monthPay = floan * fMonthRate * pow(1+fMonthRate, iMonth) / (pow(1+fMonthRate,iMonth) - 1) ;
	float fpaidBase = 0;
	float fratePaid = 0;
	int i=1;
	for(;i<=iMonth;i++){
		float monthRate = (floan - fpaidBase) * fMonthRate;
		fratePaid += monthRate;
		float monthPaidBase = monthPay - monthRate; 
		fpaidBase += monthPaidBase;
		//printf("month %d ratepaid: %f basepaid: %f leftbase: %f\n", i, fratePaid, fpaidBase, floan -  fpaidBase);

		auto iter = mp.find(i);
		if(iter != mp.end()){
			printf("\nmonth i: %d from base: %f cut base : %d \n", i, floan-fpaidBase, iter->second);
			fpaidBase += iter->second;
		}
		if(fpaidBase >= floan) {
			break;
		}
	}

	printf("rate paid total: %f paid month: %d\n", fratePaid, i-1);
	return 0;
}


int main()
{
	map<int,int> mp;
	printf("origin case:\n"); 
	print_all(300*10000,30,5.15, mp);

	mp[24] = 30 * 10000;
	print_all(300*10000,30,5.15, mp);

	mp[24] = 0;
	mp[48] = 60*10000;
	print_all(300*10000,30,5.15, mp);

	mp[24] = 30 * 10000;
	mp[48] = 30*10000;
	mp[48+24] = 30*10000;
	print_all(300*10000,30,5.15, mp);

	return 0;
}



/*

origin case:
rate paid total: 2897073.250000 paid month: 359

month i: 24 from base: 2911574.250000 cut base : 300000 
rate paid total: 2102288.250000 paid month: 293

month i: 24 from base: 2911574.250000 cut base : 0 

month i: 48 from base: 2813576.750000 cut base : 600000 
rate paid total: 1704019.125000 paid month: 250

month i: 24 from base: 2911574.250000 cut base : 300000 

month i: 48 from base: 2481102.750000 cut base : 300000 

month i: 72 from base: 2004033.625000 cut base : 300000 
rate paid total: 1341552.875000 paid month: 210

*/
