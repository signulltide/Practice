#include <stdio.h>

#include <stdio.h>

int main() {
    char line[256];

    if (fgets(line, sizeof line, stdin)) {
        long long sum = 0, val;
        int i = 0, off;

        while (line[i] != '\0') {
            int matched = sscanf(line + i, " %lld%n", &val, &off);

            if (matched == 1) {
                sum += val; i += off;
            } else {
                i++;
            }
        }
        printf("%lld\n", sum);
    }
} 