#include <stdio.h>

int future(int p[], int n, int i, int x) {
    for(int k=i+1;k<n;k++)
        if(p[k]==x) return k;
    return 9999;
}

int main() {
    int n,f;
    scanf("%d",&n);
    int p[n];
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    scanf("%d",&f);

    int fr[f], faults=0;
    for(int i=0;i<f;i++) fr[i]=-1;

    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++)
            if(fr[j]==p[i]) hit=1;

        if(!hit){
            int pos=0, far=-1;
            for(int j=0;j<f;j++){
                int nx = future(p,n,i,fr[j]);
                if(fr[j]==-1){ pos=j; break; }
                if(nx > far){ far=nx; pos=j; }
            }
            fr[pos]=p[i];
            faults++;
        }

        for(int j=0;j<f;j++) printf("%d ", fr[j]);
        printf("\n");
    }

    printf("Faults=%d", faults);
    return 0;
}

