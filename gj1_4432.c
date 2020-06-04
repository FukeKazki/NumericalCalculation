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
    int m = i;
    double key;
    FOR(k, n, i+1) {
        if (fabs(a[m][i]) < fabs(a[k][i])) m = k;
    }
    REP(j, n+1) {
        key = a[m][j];
        a[m][j] = a[i][j];
        a[i][j] = key;
    }
    // printf("%d�s�ڂ�%d�s�ڂ����ւ��܂����B\n", i+1, m+1);
    // debugMatrix(a, n);
}

int main(void) {
    int n;
    double a[N][N+1], x[N];
    char undefined_numbers[] = {'x', 'y', 'z', 'u', 'v', 'w'};

    printf("�K�E�X�̏����@�ɂ��A���ꎟ�������̉�@\n");
    while(1) {
        char z, zz;
        printf("�����A���ꎟ�������ł����B(1 < n < 7) n = ");
        scanf("%d%c", &n, &zz);
        if (n <= 1 || n >= 7) continue;

        printf("�W���ƉE�ӂ̒l����͂��Ă�������\n");
        REP(i, n) {
            printf("��%d��:\n", i+1);
            REP(j, n+1) {
                if (j == n) {
                    printf("\n\t�E�ӂ̒l A(%d, %d) = ", i+1, j+1);
                } else {
                    printf("\t%c�̌W�� A(%d, %d) = ", undefined_numbers[j], i+1, j+1);
                }
                scanf("%lf%c", &a[i][j], &zz);
            } 
        }
        printf("\n���������͂��܂������B(y/n) ");
        scanf("%c%*c", &z);
        if (z == 'y') break;
    }

    printf("\n���͂��ꂽ�g��W���s��\n");
    debugMatrix(a, n);

    REP(i, n) {
        if (i != n-1) {
            replace(a, i, n);
        }

        double p = a[i][i];
        if (fabs(p) < 1.0e-6) {
            printf("��Ӊ������݂��܂���B\n");
            return 0;
        }
        
        REP(j, n+1) {
            a[i][j] /= p;
        }

        REP(k, n) {
            // �����s�Ȃ��΂�
            if (i == k) continue;

            double q = a[k][i];
            FOR(j, n+1, i) {
                a[k][j] = a[k][j] - a[i][j] * q;
            }
        }

        printf("(%d, %d)���������Ƃ��ď㉺�ɑ|���o�����s��\n", i+1, i+1);
        debugMatrix(a, n);
    }

    REPR(i, n-1) {
        double s;
        s = 0.0;
        FOR(j, n, i+1) {
            s += a[i][j] * x[j];
        }
        x[i] = a[i][n] - s;
    }
    // debugMatrix(a, n);
    printf("�A���ꎟ�������̉���\n");
    REP(i, n) {
        printf("%c = %10lf\n", undefined_numbers[i], x[i]);
    }

    return 0;
}