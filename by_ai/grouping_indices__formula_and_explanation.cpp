/*
    
    GROUPING INDICES

    Before understanding expressions such as:

        i / 2 % 2

    it helps to understand the idea of "groups".

    Suppose we have the indices:

        0 1 2 3 4 5 6 7 8 9 10 11

    We can divide them into consecutive groups.

    For example, groups of size 2:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]

    Every index belongs to exactly one group.

    We can give each group a number:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
          0      1      2      3      4       5

    The important observation is that:

        i / 2

    gives us exactly the group number of index i.

        i:        0 1 | 2 3 | 4 5 | 6 7 | 8 9 | 10 11
        i / 2:    0 0 | 1 1 | 2 2 | 3 3 | 4 4 |  5  5

    Why?

        0 / 2 = 0
        1 / 2 = 0
        2 / 2 = 1
        3 / 2 = 1
        4 / 2 = 2
        ...

    Integer division makes every group of 2 indices have the same
    group number.

    ------------------------------------------------------------

    Now suppose we do not want every group to have a unique number.

    Maybe we want the groups to alternate between two states:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
          0      1      0      1      0       1

    We can get this by taking the group number modulo 2:

        i / 2 % 2

        i / 2:    0 0 | 1 1 | 2 2 | 3 3 | 4 4 | 5 5
        % 2:      0 0 | 1 1 | 0 0 | 1 1 | 0 0 | 1 1

    This happens because:

        0 % 2 = 0
        1 % 2 = 1
        2 % 2 = 0
        3 % 2 = 1
        4 % 2 = 0
        ...

    So:

        / 2 -> creates groups of size 2
        % 2 -> makes the groups alternate between 0 and 1

    Therefore:

        i / 2 % 2

    means:

        "Which group am I in, and is that group even or odd?"

    ------------------------------------------------------------

    USING IT TO FLIP A BINARY VALUE

    Suppose x is either 0 or 1.

        x ^ 0 = x
        x ^ 1 = 1 - x

    Therefore:

        x ^ (i / 2 % 2)

    gives:

        x x | 1-x 1-x | x x | 1-x 1-x | ...

    The XOR does not create the groups.
    The expression:

        i / 2 % 2

    creates the 0/1 pattern.

    XOR simply uses that pattern to decide whether x should stay
    the same or be flipped.

    ------------------------------------------------------------

    GENERAL FORMULA

        floor(i / k) % y

    The first part:

        floor(i / k)

    divides the indices into groups of size k.

        k = 2:

            [0 1] [2 3] [4 5] [6 7] ...

        k = 3:

            [0 1 2] [3 4 5] [6 7 8] ...

        k = 4:

            [0 1 2 3] [4 5 6 7] [8 9 10 11] ...

    The second part:

        % y

    makes the group numbers repeat every y groups.

    For example:

        i / 3 % 2

        groups:

            [0 1 2] [3 4 5] [6 7 8] [9 10 11]
              0        1        0          1

        So we get:

            0 0 0 | 1 1 1 | 0 0 0 | 1 1 1 | ...

    Another example:

        i / 2 % 3

        groups:

            [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
              0      1      2      0      1       2

        So we get:

            0 0 | 1 1 | 2 2 | 0 0 | 1 1 | 2 2 | ...

    GENERAL IDEA:

        / k  -> determines the group size
        % y  -> determines how many group values are repeated

    Therefore:

        floor(i / k) % y

    means:

        "Divide the indices into groups of size k,
         then cycle the group number through 0, 1, ..., y-1."

    In C++, because / between integers is integer division:

        i / k % y

    is the implementation of:

        floor(i / k) % y
        
        
*/

//////////////////////problem for that

//https://codeforces.com/problemset/problem/2256/B



//solution using this concept:

/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    // The first two positions can independently be 0 or 1.
    // Therefore, there are only 4 possible starting pairs:
    //
    //      a b
    //      0 0
    //      0 1
    //      1 0
    //      1 1
    //
    // Once a and b are chosen, the whole string is determined because:
    //
    //      s[i + 2] = 1 - s[i]
    //
    // So we only need to try these 4 possibilities.

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {

            bool ok = true;

            for (int i = 0; i < n; i++) {

                // Even positions use a:
                //
                //     i = 0, 2, 4, 6, ...
                //
                // Odd positions use b:
                //
                //     i = 1, 3, 5, 7, ...
                //
                // Every two positions, the value must flip.
                //
                // For either a or b:
                //
                //     x ^ (i / 2 % 2)
                //
                // i / 2 groups positions into pairs:
                //
                //     0 1 | 2 3 | 4 5 | 6 7
                //       0     1     2     3
                //
                // % 2 makes the pairs alternate:
                //
                //     0 0 | 1 1 | 0 0 | 1 1
                //
                // XOR then gives:
                //
                //     x x | 1-x 1-x | x x | 1-x 1-x

                int x;

                // Even position -> start from a.
                if (i % 2 == 0)
                    x = a;

                // Odd position -> start from b.
                else
                    x = b;

                // Flip x every pair.
                int expected = x ^ (i / 2 % 2);

                // '?' can represent either 0 or 1,
                // so it never makes this candidate invalid.
                //
                // If s[i] is already 0 or 1,
                // it must equal the expected value.
                if (s[i] != '?' && s[i] - '0' != expected) {
                    ok = false;
                    break;
                }
            }

            // This choice of (a, b) produces a valid string.
            if (ok)
                ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}
*/



























/*
/////////////////////////////////////////////other way to solve it (not related to the concept) :

//https://codeforces.com/problemset/problem/2256/B

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

void pre_compute(){
	
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	////for n=2 what are all valid:
	//00 , 01 , 10 , 11   because it is only one block
	
	// for n=3 what are all valid?
	//001 100 011 110 
	
	//for n=4 what are all valid?
	//0011 1001 0110 1101 also 4 and it keep changing but only 4 not more than 4
	
	
	/////// a b c =====>> a and c can't be the same to be valid ! <<<<<<main observation
				///////also when something is forced put it for example 1 0 ? then put the ? as 1 because it has the element before the previous is 1
	
	int n; cin>>n;
	string s; cin>>s;
	
	////////to get the difference chrachter from c (1>0),(0>1) in assci:
										/////////'1'-c+'0'
														//but i didn't use it here
	
	
	///////clean code:
	
	
	string s2=s;
	
	for(int i = 0 ; i < n ; i++){///////////fix : start from 0
		
		if(i-2>=0&&s2[i]!='?'){//////////////added &&s[i]!='?' for the four ifs
			if(s2[i-2]=='?')s2[i-2]=(s2[i]=='1'?'0':'1');
		}
		
		
		if(i+2<=n-1&&s2[i]!='?'){
			if(s2[i+2]=='?')s2[i+2]=(s2[i]=='1'?'0':'1');
		}
		
	}
	
	
	// cerr<<s2<<' ';
	
	
	for(int i = n-1 ; i >=0 ; i--){//////to fix based on what was already fixed
		
		
		if(i-2>=0&&s2[i]!='?'){/////////fix check if s2 not s of i is not ?
			if(s2[i-2]=='?')s2[i-2]=(s2[i]=='1'?'0':'1');
		}
		
		
		if(i+2<=n-1&&s2[i]!='?'){
			if(s2[i+2]=='?')s2[i+2]=(s2[i]=='1'?'0':'1');
		}
		
		
	}
	
	
	int count=0;
	
	for(int i =0 ;i < n; i++){
		
		if(i>=2) 
			if((s[i]==s[i-2]&&s[i]!='?')||(s2[i]==s2[i-2]&&s2[i]!='?'))
				return void(cout<<"0\n");
		
		if(s[i]=='?')count++;
	}
	
	
	
	bool all_1=true,all_2=true;
	
	for(int i = 0 ; i < n; i+=2){
		if(s[i]!='?'){//////////////////fix: != not == (and also downward)
			all_1=false;
			break;
		}
	}
	
	for(int i = 1 ; i < n; i+=2){
		if(s[i]!='?'){
			all_2=false;
			break;
		}
	}
	
	if(all_1&&all_2)cout<<"4\n";
	else if(all_1||all_2)cout<<"2\n";
	else cout<<"1\n";
	
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

*/











