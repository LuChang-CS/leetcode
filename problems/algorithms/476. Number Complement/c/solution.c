#include <stdio.h>

int findComplement(int num) {
    if (num == 0) return 1;
    
    int v = num;
    int r;
    int shift;

    // calculate log2(num)
    r = (v > 0xFFFF) << 4; v >>= r;
    shift = (v > 0xFF) << 3; v >>= shift; r |= shift;
    shift = (v > 0xF) << 2; v >>= shift; r |= shift;
    shift = (v > 0x3) << 1; v >>= shift; r |= shift;
    r |= (v >> 1);
    
    return (~num) & ((2 << r) - 1);
}

int main() {
    printf("%d\n", findComplement(5));
    return 0;
}
