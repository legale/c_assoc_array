#include <stdio.h>          //printf()
#include <stdlib.h>         //malloc() free()
#include <stdbool.h>        //bool true false
#include <string.h>         //memcpy() memcmp()
#include "hash.h"           //crc32() hashphp() murmur3_32() murmur3_64()
#include "single_list.h"    //linked list library
#include "assoc_array.h"    //associative array library



int main() {

    htable *hashtable = init_array(21); //array size is a power of two. 21 means power(2,21) or 2<<19, or 2 097 152

    unsigned char key1[] = "first";
    unsigned char key2[] = "second";
    unsigned char key3[] = "third";
    unsigned char key4[] = "fourth";
    unsigned char key5[] = "before_first";

    unsigned long value = 123456, check;
    list *lst_set = array_set(hashtable, key1, sizeof(key1), value);

    check = array_get(hashtable, key1, sizeof(key1));

    printf("val: %lu check %lu\n", value, check);

    array_remove(hashtable, key1, sizeof(key1));



    list *lst = list_push(NULL, key1, sizeof(key1), 1);
    list_push(lst, key2, sizeof(key2), 2);
    list_push(lst, key3, sizeof(key3), 3);
    list_push(lst, key4, sizeof(key4), 4);
    list_unshift(lst, key5, sizeof(key5), 11);

    list_node *get = list_get(lst, key1, 5);

    list_remove(lst,key1, sizeof(key1));
    list_remove(lst,key5, sizeof(key5));
    list_remove(lst,key3, sizeof(key3));
    list_remove(lst,key2, sizeof(key2));
    list_remove(lst,key4, sizeof(key4));


    printf("murmur3_64 mod hash: 0x%016lX\n", murmur3_64(key1, sizeof(key1)));
    printf("murmur3_32 mod hash: 0x%08X\n", murmur3_32(key1, sizeof(key1)));


    //*

    for (int i = 0, j = 45, k = 45, n = 45, m = 45; i < hashtable->halfsize; ++i) { //a ascii code is 97
        if (j > 122) { //z ascii code is 122
            exit(2);
            j = 45;
            m++;
        }
        if (k > 122) { //z ascii code is 122
            k = 45;
            j++;
        }
        if (n > 122) { //z ascii code is 122
            n = 45;
            k++;
        }
        if (m > 122) { //z ascii code is 122
            m = 45;
            n++;
        }
        unsigned char *key = (unsigned char *) malloc(5);
        key[0] = j;
        key[1] = k;
        key[2] = n;
        key[3] = m;
        key[4] = 0;

        array_set(hashtable, key, 5, i);
        m++;
    }
    printf("hashtable size:              %lu\n", hashtable->size);
    printf("hashtable elements:          %lu\n", hashtable->elements);
    printf("collisions:              %lu\n", hashtable->collisions);
    printf("collision factor:        %f\n", (float) hashtable->collisions / hashtable->elements);
    printf("load factor:             %f\n", (float) hashtable->elements / (float) hashtable->size);


    return 0;

     //*/
}