#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define endl "\n"
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

// Sort a stack using recursion

void insert(stack<int> &s , int temp)
{
    if(s.size()==0 || s.top()<=temp)
    {
        s.push(temp);
        return;
    } 

    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}

void sort_stack(stack<int> &s)
{
    if(s.size()<=1)return;

    int temp = s.top();
    s.pop();

    sort_stack(s);

    insert(s,temp);
    
    return;
}

int main()
{
    int n;cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        int a ;cin>>a;
        s.push(a);
    }

    sort_stack(s);
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
