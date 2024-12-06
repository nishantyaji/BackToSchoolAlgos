int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    int * flags = (int *)malloc(sizeof(int) * n);
    memset(flags, 0, n * sizeof(flags[0]));
    int i = 0;
    for(i = 0; i < bannedSize; i++) {
        if(banned[i] <= n) flags[banned[i] - 1] = 1;
    }
    int total = 0, count = 0;
    for(i = 1; i <= n; i++) {
        if(flags[i-1] == 1) continue;
        total += i;
        if(total > maxSum) break;
        count++;
    }
    return count;
}
