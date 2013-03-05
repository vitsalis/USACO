/*
ID: vitsali1
LANG: C++
TASK: crypt1
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< int > a, b;

int toint( vector< int > c ) {
    int num = 0;
    int i = 0;
    while ( i < c.size() ) {
        num = ( num * 10 ) + c[ i++ ];
    }
    return num;
}

bool check( bool seq[] ) {
    int i, j; 
    int rem = 0;
    int prod;
    for ( i = 0; i < 2; ++i ) {
        prod = b[ i ] * toint( a );
        if ( prod >= 1000 ) return false;
        while ( prod > 0 ) {
            if ( !seq[ prod % 10 ] ) {
                return false;
            }
            prod /= 10;
        }
    }
    prod = toint( a ) * toint( b );
    if ( prod >= 10000 ) return false;
    while ( prod > 0 ) {
        if ( !seq[ prod % 10 ] ) {
            return false;
        }
        prod /= 10;
    }
    return true;
}

int next( int num, bool seq[] ) {
    int i;
    for ( i = num + 1; !seq[ i ]; ++i ) {
        ;
    }
    return i;
}

void printVector( vector< int > c ) {
    for ( int i = 0; i < c.size(); ++i ) {
        printf( "%d", c[ i ] );
    }
    printf( "\n" );
}

void generate( int nums[], int N, bool seq[] ) {
    int i = a.size() - 1;
    while ( i >= 0 && a[ i ] == nums[ N ] ) {
        a[ i ] = nums[ 0 ];
        --i;
    }
    if ( i < 0 ) {
        i = b.size() - 1;
        while ( i >= 0 && b[ i ] == nums[ N ] ) {
            b[ i ] = nums[ 0 ];
            --i;
        }
        b[ i ] = next( b[ i ], seq );
    }
    else {
        a[ i ] = next( a[ i ], seq );
    }
}

bool fin( int nums[], int N ) {
    int i;
    for ( i = 0; i < a.size(); ++i ) {
        if ( a[ i ] != nums[ N ] ) {
            return false;
        }
    }
    for ( i = 0; i < b.size(); ++i ) {
        if ( b[ i ] != nums[ N ] ) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen( "crypt1.in", "r", stdin );
    freopen( "crypt1.out", "w", stdout );
    int N, i, n;
    scanf( "%d", &N );
    bool seq[ 10 ];
    int nums[ N ];
    for ( i = 0; i < 10; ++i ) {
        seq[ i ] = false;
    }
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", &n );
        seq[ n ] = true;
        nums[ i ] = n;
    }
    sort( nums, nums + N );
    int count = 0;
    for ( i = 0; i < 3; ++i ) {
        a.push_back( nums[ 0 ] );
    }
    for ( i = 0; i < 2; ++i ) {
        b.push_back( nums[ 0 ] );
    }
    while ( !fin( nums, N - 1) ) {
        if ( check( seq ) ) {
            ++count;
        }
        generate( nums, N - 1, seq );
    }
    printf( "%d\n", count );
    return 0;
}
