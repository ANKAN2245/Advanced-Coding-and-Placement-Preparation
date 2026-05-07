#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    long long A[N];

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long K;
    scanf("%lld", &K);

    // Check possibility
    long long rem = A[0] % K;

    for (int i = 1; i < N; i++) {
        if (A[i] % K != rem) {
            printf("-1\n");
            return 0;
        }
    }

    // Sort array
    qsort(A, N, sizeof(long long), compare);

    // Median element
    long long median = A[N / 2];

    long long operations = 0;

    for (int i = 0; i < N; i++) {
        operations += llabs(A[i] - median) / K;
    }

    printf("%lld\n", operations);

    return 0;
}