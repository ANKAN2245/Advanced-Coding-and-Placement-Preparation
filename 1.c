#include <stdio.h>
#include <string.h>

int main() {
    char S[100005];
    scanf("%s", S);

    int n = strlen(S);

    char T[200010];
    strcpy(T, S);
    strcat(T, S);

    int freq[26] = {0};
    int left = 0, max_sum = 0, current_sum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = T[right] - 'a';

        while (freq[idx] > 0 || (right - left + 1) > n) {
            int lidx = T[left] - 'a';
            freq[lidx]--;
            current_sum -= (lidx + 1);
            left++;
        }

        freq[idx]++;
        current_sum += (idx + 1);

        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    printf("%d\n", max_sum);

    return 0;
}