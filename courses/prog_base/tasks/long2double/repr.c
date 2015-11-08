#include <math.h>

double long2double (long long bitcode)
{
    int b[64];
    for (int i=63; i>=0; bitcode>>=1, i--)
        b[i]=bitcode & 1;

    int sign=b[0];

    int exponent=0;
    for (int i=1; i<=11; i++)
        if (b[i])
        exponent += pow(2, 11-i);

    double mantissa=0;
    for (int i=12; i<=63; i++)
        if (b[i])
        mantissa += pow(2, 11 - i);

    if (exponent>0 && exponent<2047)
        return pow(-1, sign) * pow(2, exponent-1023) * (mantissa+1);
    if (exponent==0 && mantissa!=0)
        return pow(-1, sign) * pow(2, -1022)*mantissa;

    if (sign==1 && exponent==0 && mantissa==0)
        return -0.;
    if (sign==0 && exponent==0 && mantissa==0)
        return 0.;

    if (sign==1 && exponent==2047 && mantissa==0)
        return -INFINITY;
    if (sign==0 && exponent==2047 && mantissa==0)
        return INFINITY;

    if (exponent==2047 && mantissa!=0)
        return NAN;
}
