#include <stdio.h>
#include <math.h>
#define N 11
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)

void ffv(int p, double a, double *b) {
    switch (p)
    {
    case 1:
        *b = a;
        break;
    case 2:
        *b = 1.0;
        break;
    default:
        *b = a;
        break;
    }
}

int main(void) {
    int n, f, g;
    double s, fx, gx, c[4][4], x, y;
    double a[N][4];
    char z, zz;

    printf("このプログラムは最小2乗法によって\n");
    printf("\ty = a*e^bx\n");
    printf("の形の曲線をあてはめるものです。\n\n");

    f = 1;
    g = 2;

    while(1) {
        printf("データの個数は何個ですか？ (1<n<10) n = ");
        scanf("%d%c", &n, &zz);
        if(n <= 1 || n >= 10) continue;

        REP(i, n) {
            printf("%d個目のデータ\n", i+1);
            printf("\tX = ");
            scanf("%lf%c", &x, &zz);
            printf("\tY = ");
            scanf("%lf%c", &y, &zz);

            ffv(f, x, &fx);
            ffv(g, x, &gx);

            a[i][0] = fx;
            a[i][1] = gx;
            a[i][2] = logf(y);
        }

        printf("\n");
        printf("正しく入力しましたか　(y/n) ");
        scanf("%c%c", &z, &zz);
        if (z == 'y') break;
    }

    printf("\n");

    REP(i, 2) {
        REP(j, 3) {
            s = 0.0;
            REP(l, n) {
                s = s + a[l][i] * a[l][j];
            }
            c[i][j] = s;
        }
    }

    REP(i, 2) {
        double p = c[i][i];
        FOR(j, 3, i) {
            c[i][j] = c[i][j] / p;
        }
        REP(l, 2) {
            if (l != i) {
                double q = c[l][i];
                FOR(j, 3, i) {
                    c[l][j] = c[l][j] - q*c[i][j];
                }
            }
        }
    }

    printf("xとyの関数関係は,\n");
    printf("y = %lf*e^%lfx\n", exp(c[1][2]), c[0][2]);
    printf("です。");
    

}