#include <stdio.h>
#include <math.h>
#define N 10
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)

void debug(char c[]) {
    printf("%s\n", c);
}

void debugMatrix(double a[N][N*2], int n) {
    REP(i, n) {
        REP(j, n*2) {
            printf("%15lf", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void replace(double a[][N*2], int i, int n) {
    int m = i;
    double key;
    FOR(k, n, i+1) {
        if (fabs(a[m][i]) < fabs(a[k][i])) m = k;
    }

    REP(j, n*2) {
        key = a[m][j];
        a[m][j] = a[i][j];
        a[i][j] = key;
    }
    // printf("%d行目と%d行目を入れ替えました。\n", i+1, m+1);
    // debugMatrix(a, n);
}

int main(void) {
    int n;
    double a[N][N*2], x[N];
    char undefined_numbers[] = {'x', 'y', 'z', 'u', 'v', 'w'};

    printf("ガウスジョルダン法による逆行列の解法\n");
    while(1) {
        char z, zz;
        printf("何次の行列ですか。(1 < n < 7) n = ");
        scanf("%d%c", &n, &zz);
        if (n <= 1 || n >= 7) continue;

        printf("行列の成分を入力してください\n");
        REP(i, n) {
            printf("\n");
            REP(j, n) {
                printf("\tA(%d, %d) = ", i+1, j+1);
                scanf("%lf%c", &a[i][j], &zz);
            } 
        }
        printf("\n正しく入力しましたか。(y/n) ");
        scanf("%c%*c", &z);
        if (z == 'y') break;
    }

    // 単位行列を生成する
    REP(i, n) {
        FOR(j, n*2, n) {
            if (i == j-n) {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    printf("\n入力された行列と単位行列\n");
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
        
        REP(j, n*2) {
            a[i][j] /= p;
        }

        REP(k, n) {
            // 同じ行なら飛ばす
            if (i == k) continue;

            double q = a[k][i];
            FOR(j, n*2, i) {
                a[k][j] = a[k][j] - a[i][j] * q;
            }
        }

        printf("(%d, %d)成分を軸として上下に掃き出した行列\n", i+1, i+1);
        debugMatrix(a, n);
    }

    // 逆行列の出力
    printf("問題の行列の逆行列\n");
    REP(i, n) {
        FOR(j, n*2, n) {
           printf("%15lf", a[i][j]); 
        }
        printf("\n");
    }

    return 0;
}