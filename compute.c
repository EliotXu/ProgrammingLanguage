#include <stdio.h>

//int tmp = 0;
/**
 * numerator 分子
 * denominator 分母
 */
// int compute(int numerator, int denominator) {
//     if (numerator > denominator || numerator == 0 || denominator == 0) {
//         return 0;
//     }
    
//     tmp = denominator;
//     int complement = denominator % numerator;
    
//     if (complement == 0) {
//         return 1;
//     }
    
//     int amass = denominator / numerator;
    
//     numerator = numerator - complement;
//     denominator = denominator * (amass + 1);
    
//     if (denominator == tmp) {
//         return 1;
//     }
    
//     compute(numerator, denominator);
// }


// int main(void) {
//     int a = 0, b = 0;
//     while(scanf("%d/%d",&a,&b) != EOF) {
//         compute(a, b);
//     }
// }
#include<stdio.h>
 
int main() {
    int a, b, r, p, c, i = 0;
    char str[20] = {0};
    
    while (scanf("%d/%d", &a, &b) != EOF) {
        while (1) {
            r = b % a;
            p = (b - r) / a;
            c = p + 1;

            if (a > 1 && r == 0) {
                i += sprintf(str + i, "1/%d", p);
                break;
            }
            
            i += sprintf(str + i, "1/%d+", c);
            a = a - r;
            b = b * c;
            if (a > 1 && r == 0) {
                i += sprintf(str + i, "1/%d", p);
                break;
            }
            if (a == 1) {
                i += sprintf(str + i, "1/%d", b);
                break;
            }
        }
        
        printf("%s\n", str);
        i=0;
        memset(str, 0, 20);
    }
}
