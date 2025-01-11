#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* s, int k) {
    if(strlen(s) < k) return false;
    int mp[26];
    char aChar = 'a';
    int i = 0;
    int aInt = (int) aChar;
    int odds = 0;
    for(i = 0; i < 26; i++) {
        mp[i] = 0;
    }
    for(i = 0; i < strlen(s); i++) {
        mp[s[i] - aInt]++;
        if(mp[s[i] - aInt] % 2 == 1) {
            odds++;
        } else{
            odds--;
        }
    }
    if(odds > k) return false;
    return true;
}

int main()
{
    char * test = "annabelle";
    printf("%d", canConstruct(test, 2));
    return 0;
}
