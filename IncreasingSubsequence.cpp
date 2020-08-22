#include<bits/stdc++.h>
using namespace std ;
 
 
/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)(1e9) + 7 ;
/************************************************************/
 
// finding leftmost idx of number just bigger than x
int binSearch( vector<int> &a, int f, int t, int &x ){
	int low = f, high = t ;
	int mid, ans = -1 ;
	while( low <= high ){
		mid = low + ( high - low ) / 2 ;
		if( a[mid] >= x ){
			ans = mid ;
			high = mid - 1 ;
		}
		else low = mid + 1 ;
	}
	return ans ;
}
// dp[i] is smallest possible tail of increasing subsequence of length i
int lis( vector<int> &a, int n ){
	int len = 1 ;
	vector<int> dp(n+1, 0) ;
	dp[1] = a[0] ;
	for( int i = 1 ; i < n ; i++ ){
		int t = binSearch( dp, 1, len, a[i] ) ;
		if( t == -1 ){
			dp[++len] = a[i] ;
		}
		else {
			dp[t] = a[i] ;
		}
	}
	return len ;
}
 
 
signed main() {
	int n; cin >> n ;
	vector<int> a(n) ;
	for( int &i of a ) cin >> i ;
	cout << lis( a, n ) ;
    return 0; 
} 
