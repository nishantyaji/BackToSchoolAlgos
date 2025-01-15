#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int count1bits(int num) {
    long long numLong = (long long) num;
    int count = 0;
    while(numLong > 0) {
        if(numLong & 1 > 0) count++;
        numLong >>= 1;
    }
    return count;
}

int minimizeXor(int num1, int num2) {
    int len1 = 1 + (int) log2(num1);
    long long base = (long long) pow(2, len1-1);
    long long newBase = (long long) pow(2, len1);
    int ones = count1bits(num2);
    long long * stack = (long long *) malloc(sizeof(long long) * len1);
    int i = 0, ans = 0, idx = 0;

    while(i < ones && base >= 1) {
        if((base & num1) > 0) { // > is of higher priority than &. Therefore braces
            ans = ans | base;
            i++;
        } else {
            stack[idx] = base;
            idx++;
        }
        base >>= 1;
    }

    while(i < ones) {
        if(idx > 0) {
            ans |= stack[idx-1];
            idx--;
        } else{
            ans = ans |newBase;
            newBase <<= 1;
        }
        i++;
    }
    return ans;
}

int main()
{
    printf("\n%d", minimizeXor(1, 536870911)); // 536870911
    printf("\n%d", minimizeXor(25, 72));   //  24

    printf("\n%d", minimizeXor(3, 5));
    printf("\n%d", minimizeXor(1, 12));
    return 0;
}
