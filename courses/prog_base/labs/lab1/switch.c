#include <math.h>

int satisfies2(int x, int y) {
   int result1, d, k;
   {
         d = abs(y)%8;
         switch (d)
         {
         case 0: k=sizeof(char); break;
         case 1: k=sizeof(signed char); break;
         case 2: k=sizeof(short);  break;
         case 3: k=sizeof(unsigned int); break;
         case 4: k=sizeof(long);  break;
         case 5: k=sizeof(unsigned long long); break;
         case 6: k=sizeof(float); break;
         case 7: k=sizeof(double); break;
         }
         result1=abs(x)*k;
            }
   return result1;
}

#include <math.h>

int exec(int op, int a, int b) {
   int result, c;
if (op<0)
    {c=a;
     a=b;
     b=c;}
     switch (op)
     {
         case 0: result=a*(-1); break;
         case 1: result=a+b; break;
         case 2: result=a-b; break;
         case 3: result=a*b; break;
         case 4: result=a/b; break;
         case 5: result=abs(a); break;
         case 6: result=pow(a,b); break;
         case 7:
         case 13:
         case 77: result=a%b; break;
         case 8: result=fmax(a,b); break;
         case 9: result=fmin(a,b); break;
         case 10: result=satisfies2(a,b); break;
         case 11: result=(pow(a,(1+b))/(0+M_PI)); break;
         default: {
             if (op<100)
                result=(op%abs(a+1))+(op%abs(b+1));
             else
                result=-1;}
     }

   return result;
}
