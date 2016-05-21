#include <stdio.h>
#include <stdlib.h>

#include "../liblibrary/library.h"

int main()
{
    library_t * mylib = library_new();
    book_t * mybook = book_new("Babenko", "Sea", 8);
    user_t * myuser = user_new("Igor");

    library_addIndex(mylib, mybook, 9);
    library_view(mylib);
    int size1 = library_getCount(mylib);

    char * (*cb1)(events ev, const char * name) = user;
    book_subs(mybook, cb1);

    books_isNotUsing(mylib);
    book_taking(mybook, myuser);
    puts("\n...Taking...");
    books_isUsing(mylib);
    puts("");
    library_subIndex(mylib, 0);
    int size2 = library_getCount(mylib);

    printf("\n%i - size of list, before deleting\n", size1);
    printf("\n%i - size of list, after deleting\n", size2);

    library_free(mylib);
    book_free(mybook);

    return 0;
}
