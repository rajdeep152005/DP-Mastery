//RECURSIVE CODE

bool subsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return true;
        
    if(n == 0)
        return false;

    if(arr[n-1] <= sum)
        return subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum);

    else
        return subsetSum(arr, n-1, sum);
}

//MEMOIZATION
#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

bool subsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return true;

    if(n == 0)
        return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(arr[n-1] <= sum)
        return dp[n][sum] = subsetSum(arr,n-1,sum-arr[n-1]) || subsetSum(arr,n-1,sum);

    else
        return dp[n][sum] = subsetSum(arr,n-1,sum);
}

int main()
{
    memset(dp,-1,sizeof(dp));

    int arr[] = {2,3,7,8,10};
    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << subsetSum(arr,n,sum);
}

// TOP-DOWN APPROACH
#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int j=1;j<=sum;j++)
        dp[0][j] = false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int arr[] = {2,3,7,8,10};
    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << subsetSum(arr,n,sum);
}


