#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAlmostEqual(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0, j = 0;
    if(len1 != len2)
        return false;
    int * counter1 = (int *) malloc(sizeof(int) * 26);
    int * counter2 = (int *) malloc(sizeof(int) * 26);
    for(i = 0; i < 26; i++) {
        counter1[i] = 0;
        counter2[i] = 0;
    }
    int aInt = (int)'a';
    for(i = 0; i < len1; i++) {
        counter1[s1[i]-aInt]++;
        counter2[s2[i]-aInt]++;
    }
    for(i = 0; i < 26; i++) {
        if(counter1[i] != counter2[i])
            return false;
    }
    
    int count = 0;
    for(i = 0; i < len1; i++) {
        if(s1[i] != s2[i])
            count++;
        if(count > 2)
            return false;
    }
    return true;
}

int main()
{
    printf("\n%d", areAlmostEqual("bank", "kanb"));
    printf("\n%d", areAlmostEqual("caa", "aab"));
    return 0;
}
