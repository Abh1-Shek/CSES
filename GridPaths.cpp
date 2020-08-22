#include<bits/stdc++.h>
using namespace std ;
 
 
// START
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
// END
const int mod = (int)1e9 + 7 ;
 
 
signed main() {
	int n ; cin >> n;
	let grid = matrix<char>( n, n, ' ' ) ;
	for(let &row of grid) for(let &cell of row) cin >> cell ;
	let dp = matrix<int>( n, n, 0 ) ;
	for( int i = 0 ; i < n ; i++ ) {
		if( grid[i][0] != '*' ){
			dp[i][0] = 1 ;
		} else break ;
	}
	for( int i = 0 ; i < n ; i++ ) {
		if( grid[0][i] != '*' ){
			dp[0][i] = 1 ;
		} else break ;
	}
	for( int i = 1 ; i < n ; i++ ){
		for( int j = 1 ; j < n ; j++ ){
			if( grid[i][j] != '*' ) dp[i][j] = dp[i][j-1] + dp[i-1][j] ;
			dp[i][j] %= mod ;
		}
	}
	cout << dp[n-1][n-1] << endl; 
}
