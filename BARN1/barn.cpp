/*
ID: vitsali1
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <algorithm>

using namespace std;

struct barn {
    int diff;
    int pos;
};

bool operator <( barn a, barn b ) {
    return a.diff > b.diff;
}

int main() {
    freopen( "barn1.in", "r", stdin );
    freopen( "barn1.out", "w", stdout );
    int M, S, N;
    scanf( "%d%d%d", &M, &S, &N );
    int array[ N ], i;
    bool cutted[ N ];
    barn houses[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", array + i );
        cutted[ i ] = false;
    }
    sort( array, array + N );
    for ( i = 0; i < N - 1; ++i ) {
       houses[ i ].diff = array[ i + 1 ] - array[ i ]; 
       houses[ i ].pos = i;
    }
    sort( houses, houses + N - 1 );
    i = 0;
    while ( M > 1 && i < N - 1 ) {
       cutted[ houses[ i++ ].pos ] = true; 
       --M;
    }
    int sum = 0, beg = 0;
    for ( i = 0; i < N; ++i ) {
       if ( cutted[ i ] ) {
            if ( array[ i ] - array[ beg ] == 0 ) {
                sum += 1;
            }
            else {
                sum += array[ i ] - array[ beg ] + 1;
            }
            beg = i + 1;
       }
    }
    sum += array[ N - 1 ] - array[ beg ] + 1;
    printf( "%d\n", sum );
    return 0;
}
