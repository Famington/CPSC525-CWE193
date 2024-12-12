#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
    char buffer[16];
    volatile int flag;
} vuln_struct;

void vulnerable_function(const char *input) {
    vuln_struct.flag = 0; // Initialize flag to 0
    printf("Initial flag value: %d\n", vuln_struct.flag);
    printf("Memory address of buffer: %p\n", (void *)vuln_struct.buffer);
    printf("Memory address of flag: %p\n", (void *)&vuln_struct.flag);

    // Intentional off-by-one error
    for (int i = 0; i <= 16; i++) { // <= allows writing out of bounds
        vuln_struct.buffer[i] = input[i];
    }

    if (vuln_struct.flag == 1) {
        printf("Flag captured! The value is: %d\n", vuln_struct.flag);
        printf("Congratulations, you've successfully exploited the vulnerability!\n");
    } else {
        printf("Modified flag value: %d\n", vuln_struct.flag);
        printf("Buffer content: %s\n", vuln_struct.buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    vulnerable_function(argv[1]);
    printf("Execution complete.\n");
    return 0;
}