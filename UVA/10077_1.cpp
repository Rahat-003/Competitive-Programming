#include<cstdio>

using namespace std;

int A, B;
int a, b, c, d, e, f;

int main () {

    while(1) {
        scanf("%d %d", &A, &B);
        if(A == 1 && B == 1) break;
        a = 0, b = 1, c = 1, d = 0;
        e = 1, f = 1;

        while(1) {
            if(e == A && f == B) break;
            if(e * B > f * A) {
                printf("L");
                b = e, d = f;
            } else {
                printf("R");
                a = e, c = f;
            }
            e = a + b; f = c + d;
        }

        printf("\n");

    }

    return 0;
}
