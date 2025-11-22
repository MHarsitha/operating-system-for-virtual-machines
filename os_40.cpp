#include <stdio.h>

int main() {
    int permissions[3][3] = {
        {1,1,1}, 
        {1,0,1}, 
        {1,0,0}  
    };

    printf("Owner Read: %s\n", permissions[0][0]?"Yes":"No");
    printf("Group Write: %s\n", permissions[1][1]?"Yes":"No");
    printf("Others Execute: %s\n", permissions[2][2]?"Yes":"No");

    return 0;
}

