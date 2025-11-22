#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for(int i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);
    int frame[f];
    for(int i=0;i<f;i++) frame[i]=-1;

    int faults=0, next=0;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++) if(frame[j]==pages[i]) found=1;
        if(!found){
            frame[next]=pages[i];
            next=(next+1)%f;
            faults++;
        }
        for(int j=0;j<f;j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}

