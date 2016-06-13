#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>

#include <string.h>

int sizeOfSmallStrings(char * myString, char * mySmallString){
    if (strcmp(mySmallString, "")==0){
        return -1;
    }
    if (strcmp(myString, "")==0){
        return 0;
    }
    int size = strlen(myString);
    int smallSize = strlen(mySmallString);
    if (size<smallSize){
        return -1;
    }

    int result = 0;
    int i = 0;
    char * newString = "";
    newString = strstr(myString, mySmallString);

    while(i<strlen(myString)){
        if (strncmp(newString, mySmallString, strlen(mySmallString))!=0){
            break;
        }
        result++;
        i++;
        newString = strstr(newString+1, mySmallString);
        if (NULL==newString){
            break;
        }
    }

    return result;
}

static void sizeOfSmallStrings_normalStringWithTwoSmall_twoCount(void **state){
    int res = sizeOfSmallStrings("my two two my", "two");
    assert_int_equal(res, 2);
}

static void sizeOfSmallStrings_nullString_zeroCount(void **state){
    int res = sizeOfSmallStrings("", "two");
    assert_int_equal(res, 0);
}

static void sizeOfSmallStrings_nullSmallString_errorCount(void **state){
    int res = sizeOfSmallStrings("", "");
    assert_int_equal(res, -1);
}

static void sizeOfSmallStrings_SmallGreaterThanOrdinary_errorCount(void **state){
    int res = sizeOfSmallStrings("two", "twos");
    assert_int_equal(res, -1);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(sizeOfSmallStrings_normalStringWithTwoSmall_twoCount),
        cmocka_unit_test(sizeOfSmallStrings_nullString_zeroCount),
        cmocka_unit_test(sizeOfSmallStrings_nullSmallString_errorCount),
        cmocka_unit_test(sizeOfSmallStrings_SmallGreaterThanOrdinary_errorCount)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
