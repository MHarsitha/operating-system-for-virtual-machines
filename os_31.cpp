#include <stdio.h>

int main() {
    int pages, frames;
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages];
    printf("Enter page reference string: ");
    for(int i=0;i<pages;i++)
        scanf("%d",&page[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    int f[frames];
    for(int i=0;i<frames;i++)
        f[i]=-1;

    int index=0, faults=0;

    for(int i=0;i<pages;i++){
        int found=0;
        for(int j=0;j<frames;j++){
            if(f[j]==page[i]){
                found=1;
                break;
            }
        }

        if(!found){
            f[index] = page[i];
            index = (index+1)%frames;
            faults++;
        }

        for(int j=0;j<frames;j++)
            printf("%d ", f[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}

