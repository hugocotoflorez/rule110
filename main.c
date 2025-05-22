#include <stdio.h>
#include <string.h>
#include <unistd.h>

static const char next_state[] = {
        0, 1, 1, 1, 0, 1, 1, 0
};

#define len 156
#define iters -1

int
main()
{
        unsigned int state[len];
        memset(state, 0, sizeof state);
        state[len - 1] = 1;
        state[len - 2] = 1;
        state[len - 3] = 1;
        state[len - 4] = 1;
        state[len - 5] = 1;
        state[len - 6] = 0;
        state[len - 7] = 1;
        state[len - 8] = 1;
        state[len - 9] = 0;
        state[len - 10] = 0;
        state[len - 11] = 1;
        unsigned int new_state[len];

        for (int i = 0; i < len; i++) {
                printf("%c", state[i] ? '#' : '.');
        }
        printf("\r");
        fflush(stdout);

        for (int iter = 0; iter < (size_t) iters; iter++) {
                for (int i = 0; i < len; i++) {
                        int index =
                        (state[(i + len - 1) % len] << 2) +
                        (state[i] << 1) +
                        (state[(i + 1) % len] << 0);
                        new_state[i] = next_state[index];
                }
                memcpy(state, new_state, sizeof state);
                for (int i = 0; i < len; i++) {
                        printf("%c", state[i] ? '#' : '.');
                }
                printf("\r");
                fflush(stdout);

                sleep(1);
        }


        return 0;
}
