struct Student {
   time_t birthday;
   char name[100];
   struct Laptop * laptop;
};

struct Laptop{
   time_t realisedate;
   char mark[100];
};

void InitializeD(struct Student * , struct Student * );
void InitializeR (struct Student * , struct Student * );
