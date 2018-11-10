#include <stdio.h>

void quick_sort(int *ary, int s, int e);
void maop_sort(int *ary, int e) {

int main(){
    int ary[] = {6,2,7,3,8,9};
    //quick_sort(ary, 0, 5);
    maop_sort(ary, 5);

    int ii =0;
    for(ii=0;ii<=5;ii++){
        printf("%d\t", ary[ii] );
    }
    return 0;
}


void quick_sort(int *ary, int s, int e){
    if(s>=e){
        return;
    }
    int i=s, j=e, key = ary[s];

    while(i<j){
        while(i<j&&key<ary[j]){
            j--;
        }
        ary[i] = ary[j];

        while(i<j&&key>ary[i]){
            i++;
        }
        ary[j] = ary[i];
    }
    ary[i] = key;

    quick_sort(ary, s, i-1 );
    quick_sort(ary, i+1, e );
}

void maop_sort(int *ary, int e) {
    int i=0,j=0,tmp=0;
    for(i=0;i<=e;i++){
        for(j=i+1;j<=e;j++){
            if(ary[i]>ary[j]){
                tmp = ary[j];
                ary[j]= ary[i];
                ary[i]= tmp;
            }
        }
    }
}
