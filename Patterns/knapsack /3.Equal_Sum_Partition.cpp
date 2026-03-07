// Recursion Approach

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return true;

    if(n == 0)
        return false;

    if(arr[n-1] <= sum)
        return subsetSum(arr, n-1, sum-arr[n-1]) ||
               subsetSum(arr, n-1, sum);
    else
        return subsetSum(arr, n-1, sum);
}

bool equalPartition(int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += arr[i];

    if(sum % 2 != 0)
        return false;

    return subsetSum(arr, n, sum/2);
}

int main()
{
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(equalPartition(arr,n))
        cout<<"Equal Partition Possible";
    else
        cout<<"Not Possible";

    return 0;
}
// Memoization Approach

#include <bits/stdc++.h>
using namespace std;

int dp[101][1001];

bool subsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return true;

    if(n == 0)
        return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(arr[n-1] <= sum)
        return dp[n][sum] =
        subsetSum(arr,n-1,sum-arr[n-1]) ||
        subsetSum(arr,n-1,sum);

    else
        return dp[n][sum] =
        subsetSum(arr,n-1,sum);
}

bool equalPartition(int arr[], int n)
{
    int sum = 0;

    for(int i=0;i<n;i++)
        sum += arr[i];

    if(sum % 2 != 0)
        return false;

    memset(dp,-1,sizeof(dp));

    return subsetSum(arr,n,sum/2);
}

int main()
{
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(equalPartition(arr,n))
        cout<<"Equal Partition Possible";
    else
        cout<<"Not Possible";

    return 0;
}
