#include <stdio.h>
#include <math.h>
#define N 11
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)
#define FN 2

double ffv(int p, double a) {
    switch (p)
    {
    case 0:
        return 1.0;
    case 1:
        return a;
    default:
        return 1.0;
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

    // 基本関数の指定
    f = 0;
    g = 1;

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

            a[i][0] = ffv(f, x);
            a[i][1] = ffv(g, x);
            a[i][2] = logf(y);
            /*
            | f1(x1) f2(x1) Y1|
            | f1(x2) f2(x2) Y2| 
            | f1(x3) f2(x3) Y3|
            */
        }

        printf("\n");
        printf("正しく入力しましたか　(y/n) ");
        scanf("%c%c", &z, &zz);
        if (z == 'y') break;
    }

    printf("\n");
    puts("入力された行列");
    REP(i, n) {
        REP(j, 3) {
            printf("%lf ", a[i][j]);
        }
        puts("");
    }
    printf("\n");
    // 拡大係数行列 tA[A b] の計算
    REP(i, FN) {
        REP(j, FN+1) {
            c[i][j] = 0.0;
            REP(k, n) {
                c[i][j] += a[k][i] * a[k][j];
            }
        }
    }

    puts("拡大係数行列 tA[A b]の結果");

    REP(i, 2) {
        REP(j, 3) {
            printf("%lf ", c[i][j]);
        }
        puts("");
    }
    // c[2][3]

    REP(i, FN) {
        double p = c[i][i];
        FOR(j, FN+1, i) {
            c[i][j] = c[i][j] / p;
        }
        REP(k, FN) {
            if (k == i) continue;
            double q = c[k][i];
            FOR(j, FN+1, i) {
                c[k][j] -= q*c[i][j];
            }
        }
    }

    puts("ガウスジョルダンの結果");

    REP(i, 2) {
        REP(j, 3) {
            printf("%lf ", c[i][j]);
        }
        puts("");
    }

    printf("xとyの関数関係は,\n");
    printf("y = %lf*e^%lfx\n", exp(c[0][2]), c[1][2]);
    printf("です。");
    

}