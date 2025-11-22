#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, dir;
    scanf("%d",&n);
    int r[n];
    for(int i=0;i<n;i++) scanf("%d",&r[i]);
    scanf("%d %d %d",&size,&head,&dir);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(r[j] > r[j+1]){
                int t=r[j]; r[j]=r[j+1]; r[j+1]=t;
            }

    int t=0;

    if(dir){ 
        for(int i=0;i<n;i++)
            if(r[i] >= head){ t+=abs(r[i]-head); head=r[i]; }
        t+=abs((size-1)-head); head=size-1;
        for(int i=n-1;i>=0;i--)
            if(r[i] < head){ t+=abs(r[i]-head); head=r[i]; }
    }
    else{
        for(int i=n-1;i>=0;i--)
            if(r[i] <= head){ t+=abs(r[i]-head); head=r[i]; }
        t+=abs(head-0); head=0;
        for(int i=0;i<n;i++)
            if(r[i] > head){ t+=abs(r[i]-head); head=r[i]; }
    }

    printf("%d", t);
}

