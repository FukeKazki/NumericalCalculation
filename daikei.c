#include <stdio.h>

#define FX(x) 1/(1+x*x)

int main(void) {
    printf("台形公式により, 以下の関数の積分計算を行います.\n");
    printf("\tf(x) = 1 / (1 + x^2)\n");
    printf("積分区間[a, b]を入力してください.\n");
    double a, b;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("分割数を入力してください.\n");
    int n;
    printf("n = ");
    scanf("%d", &n);

    double h = (b - a) / n;
    double fa = FX(a);
    double fb = FX(b);
    double fxi = 0;

    for (int i = 1; i < n; ++i) {
        double x = a + h * i;
        fxi += FX(x);
    }

    double result = h * (fa + fb + 2 * fxi) / 2.0;
    printf("--- 計算過程の表示 ---\n");
    printf("刻み幅 h = %lf\n", h);
    printf("f(a) + f(b) = %lf\n", fa + fb);
    printf("Σf(xi)(両端以外) = %lf\n", fxi);
    printf("f(a) + f(b) + 2 * Σf(xi)(両端以外) = %lf\n", fa + fb + 2 * fxi);
    printf("h / 2.0 * (f(a) + f(b) + 2 * Σf(xi)(両端以外)) = %lf\n", result);
    printf("--- 計算結果の表示 ---\n");
    printf("積分値は, %lf です.\n", result);

    return 0;
}