#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define endl "\n"
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);


// Sort array using Recursion

void shiftarray(vector<int> &arr,int idx,int last)
{
    int temp = arr[last];
    for(int i=last-1;i>=idx;i--)
    {
        arr[i+1] = arr[i];
    }  
    arr[idx] = temp;
}

void sort_recursion(vector<int> &arr,int i)
{
    if(i==0)return ;
    if(i==1 && arr[0]>arr[1])
    {
        swap(arr[0],arr[1]);
        return;
    }

    sort_recursion(arr,i-1);

    for(int j=0;j<i;j++)
    {
        if(arr[j] > arr[i])
        {
            shiftarray(arr,j,i);
        }
    }

    return;
}
int main()
{
    int n;cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    sort_recursion(arr,n-1);

    for(int i : arr)cout<<i<<" ";
}
