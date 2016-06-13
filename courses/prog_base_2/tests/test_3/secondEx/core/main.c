#include <stdio.h>
#include <stdlib.h>

#include "C:\Users\DrLove\Desktop\secondEx\libblog\blog.h"

int main()
{
    valerooncom_t * myNetwork = valerooncom_new();
    user_t * Valera = user_new(8, "valerik", "Valera", "Babenko", 18, "Ukraine", myNetwork);
    user_t * Igor = user_new(7, "igormet", "Igor", "Babenko", 18, "Lvov", myNetwork);
    user_t * myUser = user_get(myNetwork, 7);
    user_view(myUser);

    user_edit(7, myNetwork, "igoralpha", "Igor", "Babenko", 19, "Russia");
    post_t * postAboutMonster = post_new("My name is Igor and i'm a big monster!", Igor);

    //comment_new(Valera, postAboutMonster, "Fuck, it's great!");

    user_view(Igor);
    return 0;
}
