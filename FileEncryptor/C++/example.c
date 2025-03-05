#include "fec.h"

#define F fflush(stdout)

int main(void);

void printbin(const int8 *input, const int16 size)
{
    int16 x;
    int8 *p;

    assert(size>0);

    for(x = size, p = input; x; x--, p++ )
    {
        if(!((x+1) % 2))
        {
           printf(" ");
        }
        printf("%.02x", *p);
        F;
    }

    printf("\n");

    return;
}

int main ()
{
   Arcfour *rc4;
   int16 skey, stext;
   char *key, *from, *to, *encrypted, *decrypted;

   key = (int8 *)"tomatoes";
   skey= strlen(key);
   from= (int8 *)"ripe but some consider veg yet some fruit";
   stext = strlen(from);

   printf("Initializing encrytion.....");

   rc4 = rc4init(key, skey);

   printf("done\n");


   printf("'%s' \n ->", from);

   encrypted = rc4encrypt(from, stext);

   printbin(key, skey);
    
    return 0;
}

