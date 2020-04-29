#include <stdio.h>
#include <math.h>
#define N 7
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)

int main(void) {
    int n;
    double a[N][N+1], x[N];

    printf("上三角型連立1次方程式の解法\n");
    while (1) {
        printf("未知数の個数 n を入力してください。 (1 < n < 7) n = ");
        scanf("%d%*c", &n);
        if (n <= 1 || n >= 7) {
            printf("Error\n");
            continue;
        }
        printf("係数と右辺の値を入力してください\n");
        REP(i, n) {
            printf("第%d式:\n", i+1);
            FOR(j, n+1, i) {
                if (j == n) {
                   printf("\n\t右辺の値 = "); 
                } else {
                    printf("\tx%dの係数 = ", j+1);
                }
                scanf("%lf%*c", &a[i][j]);
            }
        }
        char z;
        printf("正しく入力しましたか。(y/n)");
        scanf("%c%*c", &z);
        if (z == 'y') break;
    }

    REP(i, n) {
        double p = a[i][i];
        if (fabs(p) < 1.0e-6) {
            printf("一意解をもちません\n");
            return 0;
        }
        FOR(j, n+1, i) {
            a[i][j] /= p;
        }
    }

    REPR(i, n-1) {
        double s;
        s = 0.0;
        FOR(j, n, i+1) {
            s += a[i][j] * x[j];
        }
        x[i] = a[i][n] - s;
    }

    printf("上三角型連立1次方程式の解\n");
    REP(i, n) {
        printf("\tx%d = %10.6lf\n", i+1, x[i]);
    }

    return 0;
}