#include <stdio.h>

#define FX(x) 1/(1+x*x)

int main(void) {
    printf("シンプソンの公式により, 以下の関数の積分計算を行います.\n");
    printf("\tf(x) = 1 / (1 + x^2)\n");
    printf("積分区間[a, b]を入力してください.\n");
    double a, b;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("2n分割します。分割数の 1/2 を入力してください.\n");
    int n;
    printf("2n = ");
    scanf("%d", &n);

    double h = (b - a) / (2 * n);
    double fa = FX(a);
    double fb = FX(b);
    double fxi_even = 0;
    double fxi_odd = 0;

    for (int i = 1; i < 2*n; ++i) {
        double x = a + h * i;
        if (i % 2 == 0) {
            fxi_even += FX(x);
        } else {
            fxi_odd += FX(x);
        }
    }

    double result = h * (fa + fb + 2 * fxi_even + 4 * fxi_odd) / 3.0;
    printf("--- 計算過程の表示 ---\n");
    printf("分割数 2n = %d\n", 2*n);
    printf("刻み幅 h = %lf\n", h);
    printf("f(a) + f(b) = %lf\n", fa + fb);
    printf("Σf(xi)(奇数番目) = %lf\n", fxi_odd);
    printf("Σf(xi)(偶数番目) = %lf\n", fxi_even);
    printf("f(a) + f(b) + 4 * Σf(xi)(奇数番目) + 2 * Σf(xi)(偶数番目) = %lf\n", fa + fb + 2 * fxi_even + 4 * fxi_odd);
    printf("h / 3.0 * (f(a) + f(b) + 4 * Σf(xi)(奇数番目) + 2 * Σf(xi)(偶数番目)) = %lf\n", result);
    printf("--- 計算結果の表示 ---\n");
    printf("積分値は, %lf です.\n", result);

    return 0;
}