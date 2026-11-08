//problem link : https://codeforces.com/gym/101532/problem/J


#include <bits/stdc++.h>
using namespace std;

bool multicases_=true;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template<class  T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
#define int long long//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<??
typedef unsigned long long u64;//this or the one  below
#define ull unsigned long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int get_first_bit(long long n){
	return 63 - __builtin_clzll(n);
}

int get_bit_count(long long n){
	return __builtin_popcountll(n);
}

void pre_compute(){
	
}

const int mod = 1e9+7;

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	int n; cin>>n;
	
	int ans = 1;
	
	int mod = 1e9+7;
	
	for(int i=1 ,x ;i<=n;i++){
		cin>>x;
		
		/////answer is (1+a)(1+b).....       % mod  -1
		
		//////ai reasoning:
	/*
        		
	// Each element has two choices:  either exclude it (contribution = 1)
                                    // or include it (contribution = a[i]).
    // Therefore, multiplying (a[i] + 1) for all elements generates  the product of every possible subset.
    
    // We subtract 1 to exclude the empty subset.
        		
	*/
		
		ans=(((ans*(1+x))%mod)+mod)%mod;
		
	}
	
	ans--;
	ans=(ans+mod)%mod;
	
	cout<<ans<<'\n';
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	//setIO("problemname");
	
	//the following output way overwrites the file:
	
	// freopen("problemname.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("problemname.out", "w", stdout);
	
	
	
	pre_compute();
	
	int tc=1;
	if(multicases_)cin>>tc;
	int total_tcs=tc;
	while(tc--){
		solve(total_tcs-tc);
	}
	return 0;
}
