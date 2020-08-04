#include <stdio.h>
#include <math.h>
#define N 10
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)

void debug(char c[]) {
    printf("%s\n", c);
}

void debugMatrix(double a[N][N+1], int n) {
    REP(i, n) {
        REP(j, n+1) {
            printf("%15lf", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void replace(double a[][N+1], int i, int n) {
    // m行目 と i行目を入れ替える
    int m = i;
    FOR(k, n, i+1) {
        if (fabs(a[m][i]) < fabs(a[k][i])) m = k;
    }
    REP(j, n+1) {
        double tmp = a[m][j];
        a[m][j] = a[i][j];
        a[i][j] = tmp;
    }
    printf("%d行目と%d行目を入れ替えました。\n", i+1, m+1);
    debugMatrix(a, n);
}

int main(void) {
    int n;
    double a[N][N+1], x[N];
    char undefined_numbers[] = {'x', 'y', 'z', 'u', 'v', 'w'};

    printf("ガウスの消去法による連立一次方程式の解法\n");
    while(1) {
        char z, zz;
        printf("何元連立一次方程式ですか。(1 < n < 7) n = ");
        scanf("%d%c", &n, &zz);
        if (n <= 1 || n >= 7) continue;

        printf("係数と右辺の値を入力してください\n");
        REP(i, n) {
            printf("第%d式:\n", i+1);
            REP(j, n+1) {
                if (j == n) {
                    printf("\n\t右辺の値 A(%d, %d) = ", i+1, j+1);
                } else {
                    printf("\t%cの係数 A(%d, %d) = ", undefined_numbers[j], i+1, j+1);
                }
                scanf("%lf%c", &a[i][j], &zz);
            } 
        }
        printf("\n正しく入力しましたか。(y/n) ");
        scanf("%c%*c", &z);
        if (z == 'y') break;
    }

    printf("\n入力された拡大係数行列\n");
    debugMatrix(a, n);

    REP(i, n) {
        if (i != n-1) {
            replace(a, i, n);
        }

        double p = a[i][i];
        if (fabs(p) < 1.0e-6) {
            printf("一意解が存在しません。\n");
            return 0;
        }
        REP(j, n+1) {
            a[i][j] /= p;
        }
        printf("対角成分を1にする。\n");
        debugMatrix(a, n);
        FOR(k, n, i+1) {
            double q = a[k][i];
            FOR(j, n+1, i) {
                a[k][j] -= a[i][j] * q;
            }
        }
        printf("(%d, %d)成分を軸として掃き出した行列\n", i+1, i+1);
        debugMatrix(a, n);
    }
   
    // 逆進代入
    REPR(i, n-1) {
        double s;
        s = 0.0;
        FOR(j, n, i+1) {
            s += a[i][j] * x[j];
        }
        x[i] = a[i][n] - s;
    }
    debugMatrix(a, n);
    printf("連立一次方程式の解は\n");
    REP(i, n) {
        printf("%c = %10lf\n", undefined_numbers[i], x[i]);
    }

    return 0;
}