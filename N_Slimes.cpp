/*
        ॐ नमः शिवाय
    Author: Deependra Singh Shekhawat
    Handle: zoroxdp
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Being(Lazy)Human
#define INF 1e18
#define MOD 1000000007
#define int long long int
#define pii pair<int, int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define mp make_pair
#define pb push_back
#define endl "\n";
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

int dp[401][401];

int32_t main(){

    io;
    int n; cin>>n;
    vector<int> cost(n), prefix(n);
    for(int i = 0; i < n; i++) cin>>cost[i];
    prefix[0] = cost[0];
    for(int i = 1; i < n; i++) prefix[i] = cost[i]+prefix[i-1];
    for(int i = 0; i < n; i++) dp[i][i] = 0;
    for(int len = 2; len <= n; len++){
        for(int l = 0, r = len - 1; r < n; l++,r++){
            dp[l][r] = INF;
            for(int cut = l; cut < r; cut++){
                dp[l][r] = min(dp[l][r], dp[l][cut]+dp[cut+1][r]);
            }
            dp[l][r] = (dp[l][r] + (prefix[r] - (l==0?0:prefix[l-1])));
        }
    }
    cout<<dp[0][n-1]<<endl;
    

}