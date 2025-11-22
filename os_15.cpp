#include <stdio.h>
#include <string.h>

int main() {
    char dir[10][20];
    int n=0, choice;
    char filename[20];

    while(1) {
        printf("\n1.Create 2.Display 3.Search 4.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter filename: "); scanf("%s",filename);
            strcpy(dir[n++],filename);
        } else if(choice==2){
            printf("Files:\n");
            for(int i=0;i<n;i++) printf("%s\n",dir[i]);
        } else if(choice==3){
            printf("Enter filename to search: "); scanf("%s",filename);
            int found=0;
            for(int i=0;i<n;i++) if(strcmp(dir[i],filename)==0){found=1; break;}
            printf(found?"File Found\n":"File Not Found\n");
        } else break;
    }
    return 0;
}

