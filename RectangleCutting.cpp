#include<bits/stdc++.h>
using namespace std ;
 
// START
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
// END


signed main() {
    int a, b ; cin >> a >> b ;
	let dp = matrix<int>( a+1, b+1, INT_MAX ) ;
	// dp[i][j] is minimum number of cuts for rectangle of sides [a, b]
	for( int i = 0 ; i <= min(a, b) ; i++ ) dp[i][i] = 0 ;
	for( int i = 1 ; i <= b ; i++ )   dp[1][i] = i - 1 ;
	for( int i = 1 ; i <= a ; i++ )   dp[i][1] = i - 1 ;
	for( int i = 2 ; i <= a ; i++ ){
		for( int j = 2 ; j <= b ; j++ ){
			// cutting on a side
			for( int k = 1 ; k < i ; k++ ){
				dp[i][j] = min( dp[k][j] + dp[i-k][j] + 1, dp[i][j] ) ;
			}
			// cutting on b side
			for( int k = 1 ; k < j ; k++ ){
				dp[i][j] = min( dp[i][k] + dp[i][j-k] + 1, dp[i][j] ) ;
			}
		}
	} 
	cout << dp[a][b] << endl ;
}
