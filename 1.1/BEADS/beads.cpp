/*
ID: vitsali1
LANG: C++
TASK: beads
*/
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen( "beads.in", "r", stdin );
    freopen( "beads.out", "w", stdout );
    char a[ 2 ] = "w";
    char w = a[ 0 ], curr;
    int N, i, beg, max = 0, count;
    bool found;
    scanf( "%d", &N );
    char s[ N + 1 ];
    scanf( "%s", s );
    string str = s;
    for ( i = 0; i < str.length(); ++i ) {
        found = false;
        beg = i + 1;
        if ( beg == N ) {
            beg = 0;
        }
        count = 1;
        curr = str[ i ];
        while ( beg != i ) {
            if ( curr != w ) {
                if ( str[ beg ] != w ) {
                    if ( curr != str[ beg ] ) {
                        if ( found ) {
                            break;
                        }
                        else {
                            curr = str[ beg ];
                            found = true;
                        }
                    }
                }
            }
            else {
                curr = str[ beg ];
            }
            ++count;
            ++beg;
            if ( beg == N ) {
                beg = 0;
            }
        }
        if ( max < count ) {
            max = count;
        }
    }
    printf( "%d\n", max );
    return 0;
}
