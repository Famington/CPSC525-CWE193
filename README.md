# CWE-193: Off-by-one Error Exploitation

## Description
Here we demonstrate an off-by-one buffer overflow vulnerability in C. The vulnerable program contains a fixed-size buffer adjacent to a flag variable. An overflow in the buffer allows an attacker to overwrite the flag variable and trigger a success message when it is set to 1

## Compilation and Execution

### Vulnerable Program

The vulnerable program (vulnerable.c) initializes a struct containing:

- A 16-byte buffer

- A flag variable initialized to 0

An off-by-one error in the loop allows writing beyond the bounds of the buffer, enabling an overwrite of the flag variable.

1. Compile the vulnerable program:
   gcc -o vulnerable off_by_one.c


# CWE-193: Off-by-one Error Exploitation

### Exploit

The exploit (exploit.c) generates a payload that:

- Fills the buffer with 16 As.

- Appends \x01 to overwrite the flag variable with 1.


1. Compile the exploit:
    gcc -o exploit exploit.c
2. Run the exploit to demonstrate the vulnerability:
    ./exploit



## Expected Output:
    ./exploit
    Launching exploit with payload: AAAAAAAAAAAAAAAA
    Initial flag value: 0
    Memory address of buffer: 0x404030
    Memory address of flag: 0x404040
    Flag captured! The value is: 1
    Congratulations, you've successfully exploited the vulnerability!
    Execution complete.