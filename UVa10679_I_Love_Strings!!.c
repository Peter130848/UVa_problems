#include <stdio.h>
#include <string.h>

char str[100005];
char subStr[1005];
char *hasSub;
int main(void){
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%s", str);
        int testCase;
        scanf("%d", &testCase);
        while (testCase--) {
            scanf("%s", subStr);
            hasSub = strstr(str, subStr);
            if(hasSub){
                printf("y\n");
            } else {
                printf("n\n");
            }
        }
    }
    return 0;
}
