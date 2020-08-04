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

    /*
    * 1  -2  3  0.5
    * 0   1 -1  0.1
    * 0   0  1 -1.1
    */
    printf("行列\n");
    REP(i, n) {
        REP(j, n+1) {
            printf("%.2lf  ", a[i][j]);
        }
        printf("\n");
    }
    REP(i, n) {
        double p = a[i][i];
        // fabs: 浮動小数点の絶対値
        if (fabs(p) < 1.0e-6) {
            printf("一意解をもちません\n");
            return 0;
        }
        FOR(j, n+1, i) {
            a[i][j] /= p;
        }
    }
    // 逆進代入
    REPR(i, n-1) { // 初期値 n - 1
        double s = 0.0;
        printf("%d行目です。\n", i);
        FOR(j, n, i+1) { // 初期値 i + 1
            printf("s += %lf * %lf\n", a[i][j], x[j]);
            s += a[i][j] * x[j];
        }
        x[i] = a[i][n] - s;
        printf("%lf - %lf = %lf\n", a[i][n], s, x[i]);
    }

    printf("上三角型連立1次方程式の解\n");
    REP(i, n) {
        printf("\tx%d = %10.6lf\n", i+1, x[i]);
    }

    return 0;
}