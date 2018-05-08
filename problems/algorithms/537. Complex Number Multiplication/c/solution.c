#include <stdio.h>
#include <stdlib.h>

struct Complex {
    int real;
    int image;
};
typedef struct Complex Complex;

int _itoa(int a, char *s) {
    int i = 0, start = 0;
    // zero should also be printed
    if (a == 0) {
        s[0] = '0';
        s[1] = '\0';
        return 1;
    }
    if (a < 0) {
        a = -a;
        s[0] = '-';
        start = i = 1;
    }
    while (a > 0) {
        s[i++] = (char)((a % 10) + '0');
        a /= 10;
    }
    // reverse number because steps above fetch digit from lower end to higher.
    for (int k = start; k < i / 2 + start; ++k) {
        char c = s[k];
        int pos = i - k - (1 - start);
        s[k] = s[pos];
        s[pos] = c;
    }
    s[i] = '\0';
    return i;
}

void parse_complex(Complex *complex, char *s) {
    char c;
    int val = 0;
    int sign = 1;
    for (int i = 0; (c = s[i]) != '\0'; ++i) {
        switch (c) {
        case '+':
            // val now is the real part
            complex->real = sign == 1 ? val : -val;
            // reset val and sign after real part to calculate image part
            val = 0;
            sign = 1;
            break;
        case 'i':
            // val now is the image part
            complex->image = sign == 1 ? val : -val;
        case '-':
            sign = -1;
            break;
        default:
            val *= 10;
            val += c - '0';
        }
    }
}

char* complexNumberMultiply(char* a, char* b) {
    Complex c1, c2;
    parse_complex(&c1, a);
    parse_complex(&c2, b);
    int real = c1.real * c2.real - c1.image * c2.image;
    int image = c1.real * c2.image + c1.image * c2.real;
    char *result = (char *)malloc(20 * sizeof(char));
    int pos = _itoa(real, result);
    result[pos++] = '+';
    pos += _itoa(image, result + pos);
    result[pos++] = 'i';
    result[pos] = '\0';
    return result;
}

int main() {
    char a[] = "71+-28i";
    char b[] = "-60+-2i";
    char *result = complexNumberMultiply(a, b);
    printf("%s", result);
    getchar();
}
