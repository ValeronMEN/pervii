// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
char * getWannaText(int points)
{
    if (points==1)
    {
        return "ACE";
    }
    else if (points == 2)
    {
        return "SECUNDA";
    }
    else if (points == 3)
    {
        return "TERTIA";
    }
    else if (points == 4)
    {
        return "QUARTA";
    }
    else if (points == 5)
    {
        return "QUINTA";
    }
    else if (points == 6)
    {
        return "SEXTA";
    }
    else if (points == 7)
    {
        return "SEPTIMA";
    }
    else if (points == 8)
    {
        return "OCTAVA";
    }
    else if (points == 9)
    {
        return "NONA";
    }
    else if (points == 10)
    {
        return "DECIMA";
    }
    else if (points == 11)
    {
        return "JACK";
    }
    else if (points == 12)
    {
        return "QUEEN";
    }
    else if (points == 13)
    {
        return "KING";
    }
    else
    {
        return "";
    }
}
