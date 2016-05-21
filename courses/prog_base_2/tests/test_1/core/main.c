#include <stdio.h>
#include <stdlib.h>

#include "../liblibrary/library.h"

int main()
{
    library_t * mylib = library_new();
    book_t * mybook = book_new("Babenko", "Sea", 8);
    library_addIndex(mylib, mybook, 9);
    library_view(mylib);
    int size = library_getCount(mylib);

    char * (*cb1)(events ev, const char * name) = user;
    book_subs(mybook, cb1);
    books_isUsing(mylib);

    book_t * book;
    book = library_subIndex(mylib, 0);
    printf("%s", book->author);
    printf("\n%i - size of list, before deleting\n", size);

    library_free(mylib);
    book_free(mybook);

    return 0;
}
