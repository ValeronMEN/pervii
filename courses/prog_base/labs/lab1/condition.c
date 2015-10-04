#include <math.h>

int satisfies(int a, int b, int c) {
int min, sum2, sum2m, result, max, k;
   if (a<0&&b<0&&c<0)
       {if (a<b&&a<c)
       {min=a*(-1);
       sum2=b+c;}
       if (b<a&&b<c)
       {min=b*(-1);
       sum2=a+c;}
       if (c<a&&c<b)
       {min=c*(-1);
       sum2=b+a;}
       sum2m=sum2*(-1);
       int k = (int) log2(min);
        if ((sum2<(-256))&&(min<256)&&(k%1==0))
           return 1;
        if (sum2m>min&&sum2>(-256))
           return 1;
        else
           return 0;}
    if (a>=0&&b>=0&&c>=0)
     {if (a<b&&a<c)
       {min=a;}
       if (b<a&&b<c)
       {min=b;}
       if (c<a&&c<b)
       {min=c;}
       if (a>b&&a>c)
       {max=a;}
       if (b>a&&b>c)
       {max=b;}
       if (c>a&&c>b)
       {max=c;}
       if ((max+min)<256)
       return 1;
       if ((max+min)>256)
       return 0;}
   else
       if (a<0&&b>=0&&c>=0)
       {min=a;}
       if (b<0&&a>=0&&c>=0)
        {min=b;}
       if (c<0&&b>=0&&a>=0)
       {min=c;}
       if (min>(-256))
       return 1;
       if (min<(-256))
       return 0;
       if (a<0&&b<0&&c>=0){
       if (((a+b)*(1+0))>(-256))
        return 1;
        if (((a+b)*(1+0))<(-256))
            return 0;}
       if (b<0&&c<0&&a>=0)
        {if (((b+c)*(1+0))>(-256))
        return 1;
        if (((b+c)*(1+0))<(-256))
            return 0;}
       if (c<0&&a<0&&b>=0)
       {if (((c+a)*(1+0))>(-256))
        return 1;
        if (((c+a)*(1+0))<(-256))
            return 0;}
            else
                return 0;
   return result;
}
