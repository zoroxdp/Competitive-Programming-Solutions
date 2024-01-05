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
#define MOD 1000000007
#define ll long long int
#define pii pair<ll, ll>
#define mii map<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define pqb priority_queue<ll>
#define pqs priority_queue<ll,vi,greater<ll>>
#define mp make_pair
#define pb push_back
#define endl "\n";
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 




int main(){

    io;
    ll n,w; cin>>n>>w;
    vector<ll> val(n),wgt(n);
    for(int i = 0; i < n; i++){
        cin>>wgt[i];
        cin>>val[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll> (w+1));
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= w; j++){
            if(j == 0 || i == 0){
                dp[i][j] = 0;
            }
            else if(wgt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wgt[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;

}