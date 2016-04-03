typedef enum card_values{EMPTY=0, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13, ACE=14} values;
typedef enum card_suits{NOSUIT=0, HEART=1, DIAMOND, CLUB, SPADE} suits;

typedef struct card{
    values value;
    suits suit;
} struct_c;

void coloda_fill_36(struct_c *);
