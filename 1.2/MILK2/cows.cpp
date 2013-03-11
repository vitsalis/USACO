/*
ID: vitsali1
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <algorithm>

using namespace std;

struct cow {
    int beg;
    int end;
};

bool operator <( cow a, cow b ) {
    return a.beg < b.beg;
}

int main() {
    freopen( "milk2.in", "r", stdin );
    freopen( "milk2.out", "w", stdout );
    int N, i;
    scanf( "%d", &N );
    cow array[ N + 1 ];

    for ( i = 0; i < N; ++i ) {
        scanf( "%d%d", &array[ i ].beg, &array[ i ].end );
    }
    sort( array, array + N );
    int sum = 0, max = 0;
    int mstart = 0;
    int begining, ending;
    begining = ending = array[ 0 ].beg;
    for ( i = 0; i < N; ++i ) {
        if ( array[ i ].beg >= begining && array[ i ].end >= ending && array[ i ].beg <= ending ) {
            sum += array[ i ].end - ending;
            if ( array[ i ].end > ending ) {
                ending = array[ i ].end;
            }
        }
        else if ( array[ i ].beg > ending ) {
            if ( array[ i ].beg - ending > mstart ) {
                mstart = array[ i ].beg - ending;
            }
            begining = array[ i ].beg;
            ending = array[ i ].end;
            sum = array[ i ].end - array[ i ].beg;
        }
        if ( sum > max ) {
            max = sum;
        }
    }
    printf( "%d %d\n", max, mstart );
     
    return 0;
}
