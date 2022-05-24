
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 1000

int main() {
    freopen("input34.txt", "r", stdin);
    freopen("output34.txt", "w", stdout);

    char str[MAX_LIMIT], temp[MAX_LIMIT];

    while (fgets(str, MAX_LIMIT, stdin)) {
        strcpy(temp, str);
        int len = strlen(str);

        int i, j;

        for (i = 0; i < len - 1; i++) {
            if (str[i] == '/' && str[i + 1] == '/') {
                temp[i + 1]   = '*';
                temp[len]     = '*';
                temp[len + 1] = '/';
                temp[len + 2] = '\0';

                break;
                // printf("paisi");
            }

            if (str[i] == '/' && str[i + 1] == '*') {
                temp[i + 1]   = '/';
                temp[len - 3] = '\0';
                break;
            }
        }
        printf("%s", temp);
    }

    return 0;
}