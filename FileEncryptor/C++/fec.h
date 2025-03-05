#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <openssl/aes.h>

#define rc4decrypt(x,y) rc4encrypt(x,y)

struct s_arcfour
{
    int x;
};

typedef struct s_arcfour Arcfour;
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

Arcfour *rc4init(int8* ,int16);
int8 rc4byte(void);
int8 *rc4encrypt(int8*, int16);