#include<bits/stdc++.h>
using namespace std ;

/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
/************************************************************/

int main(){
	int n, m ; cin >> n >> m ;
	vector<int> a(n) ;
	for(int &x of a) cin >> x ;
	let dp = matrix<int>( n, m+1, 0 ) ;
	// dp[i][j] is number of ways to form a[0:i] such that a[i] = v
	if( a[0] == 0 ){
		dp[0].assign( m + 1, 1 ) ;
	} else dp[0][a[0]] = 1 ;
	for( int i = 1 ; i < n ; i++ ){
		int x = a[i] ;
		if( !x ){
			for( int j = 1 ; j <= m ; j++ ){
				for( int k of { j - 1, j, j + 1 } ){
					if( k >= 1 && k <= m ) (dp[i][j] += dp[i-1][k]) %= mod ;
				}
			}
		}
		else{
			for( int k of { x - 1, x, x + 1 } ){
				if( k >= 1 && k <= m ) (dp[i][x] += dp[i-1][k]) %= mod ;
			}
		}
	}
	int ans = 0 ;
	for( int i = 1 ; i <= m ; i++ ){
		( ans += dp[n-1][i] ) %= mod ; 
	}
	cout << ans ;
	return 0 ;
}
