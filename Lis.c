
int lengthOfLIS(int* arr, int l) {
    if(l==0)
        return 0;
    int dp[l];
    int i, j;
    dp[0] = 1;
    int maxans = 1;
    for (int i = 1; i < l; i++) {
        int maxval = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                maxval = max(maxval, dp[j]);
            }
        }
        dp[i] = maxval + 1;
        maxans = max(maxans, dp[i]);
    }
    return maxans;
}

int max(int a, int b){
    return (a>b)?a:b;
}