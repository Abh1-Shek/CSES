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
int mod = (int)1e9 + 7 ;
/************************************************************/

auto accumulate( vector<int> &a, int &len ){
	vector<int> dp( len, 0 ) ;
	dp[0] = a[0] ;
	for( int i = 1 ; i < len ; i++ ){
		dp[i] = dp[i-1] + a[i] ;
	}
	return dp ;
}
int sum( vector<int> &a, int f, int t ){
	return( a[t] - ( f == 0 ? 0 : a[f - 1] ) );
}

signed main(){
	int n ; cin >> n ;
	vector<int> a(n) ;
	for( int i = 0 ; i < n ; i++ ) cin >> a[i] ;
	let prefix = accumulate( a, n ) ;
	int dp[n][n] = {0} ;
	for( int i = 0 ; i < n ; i++ ) dp[i][i] = a[i] ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = i - 1 ; j >= 0 ; --j ){
			dp[i][j] = max(
				a[i] + sum( prefix, j, i - 1 ) - dp[i-1][j],
				a[j] + sum( prefix, j + 1, i ) - dp[i][j+1]
			) ;
		}
	}
	cout << dp[n-1][0] ;
	return 0 ;
}  
