#include <math.h>

double calc(double x, double y, double z) {
   double a, a0, a1, a2;
if (2*fabs(x+y)==0)
    return NAN;
if (pow(x-y, 1/z)==0)
    return NAN;
if (fabs(sin(y))==0)
    return NAN;
    else
a0=((pow(x, y+1))/(pow(x-y, 1/z)));
a1=(y/(2*fabs(x+y)));
a2=(pow(x,1/fabs(sin(y))));
a=a0+a1+a2;
   return a;
}
