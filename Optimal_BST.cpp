#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void optimalBST(double *p, double *q, int n) {
    double *e = calloc((n+1)*(n+1), sizeof(double));
    double *w = calloc((n+1)*(n+1), sizeof(double));
    int *root = calloc((n+1)*(n+1), sizeof(int));

    // Initialization
    for (int i = 0; i <= n; i++) {
        e[i*(n+1) + i] = q[i];
        w[i*(n+1) + i] = q[i];
    }
    for (int i = 0; i < n; i++) {
        root[i*(n+1) + i] = i+1;
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i + l;
            double min = INFINITY;
            w[i*(n+1) + j] = w[i*(n+1) + j-1] + p[j] + q[j];
            for (int r = i; r < j; r++) {
                double t = e[i*(n+1) + r] + e[(r+1)*(n+1) + j] + w[i*(n+1) + j];
                if (t < min) {
                    min = t;
                    e[i*(n+1) + j] = t;
                    root[i*(n+1) + j-1] = r+1;
                }
            }
        }
    }

    printf("------ e -------\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f ", e[i*(n+1) + j]);
        }
        printf("\n");
    }
    printf("------ w -------\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f ", w[i*(n+1) + j]);
        }
        printf("\n");
    }
    printf("----- root -----\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", root[i*(n+1) + j]);
        }
        printf("\n");
    }

    free(e);
    free(w);
    free(root);
}

int main() {
    double p[] = {0, 0.10, 0.20, 0.30, 0.10, 0.05};
    double q[] = {0.05, 0.03, 0.02, 0.01, 0.02, 0.12};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    optimalBST(p, q, n);

    return 0;
}

