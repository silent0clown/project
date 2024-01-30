#include <stdio.h>
#include <string.h>

#define MAX_NEXT_LEN (20)

void getNext(char *pattern, int *next) {
    if (pattern == NULL || next == NULL) {
        printf("param is null\n");
        return;
    }
    int j = 0, k = -1;
    next[0] = -1;
    while (j < strlen(pattern)) {
        if (k == -1 || pattern[j] == pattern[k]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int kmpMatch(char *text, char *pattern) {
    if (text == NULL || pattern == NULL) {
        printf("PARAM IS NULL\n");
        return -2;
    }
    int i = 0, j = 0, next[MAX_NEXT_LEN];
    getNext(pattern, next);

    while (i < (int)strlen(text) && j < (int)strlen(pattern)) { 
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == strlen(pattern)) {
        return i - j;
    } else {
        return -1;
    }
}




// int main() 
// {
//     char S[maxsize],T[maxsize];
//     int target;
	
// 	strcpy(S,"AAAAAAAAAAttract");
// 	strcpy(T,"Attract");

// 	target=KMP(S,T);
// 	printf("Position is %d\n",target);
//     target = kmpMatch(S, T);
//     printf("Position is %d\n", target);
// 	return 0;
// }


int main(){
    char *sub = "caba";
    char *pattern = "abcababcdaba";
    int pos = 0;

    pos = kmpMatch(pattern, sub);  // first is 0
    printf("pos is %d\n", pos);
}