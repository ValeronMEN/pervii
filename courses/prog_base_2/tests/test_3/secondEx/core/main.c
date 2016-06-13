#include <stdio.h>
#include <stdlib.h>

#include "C:\Users\DrLove\Desktop\secondEx\libblog\blog.h"

int main()
{
    valerooncom_t * myNetwork = valerooncom_new();
    user_t * Valera = user_new(8, "valerik", "Valera", "Babenko", 18, "Ukraine", myNetwork);
    return 0;
}
