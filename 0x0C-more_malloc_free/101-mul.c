0x0C. C - More malloc, free
README.md


Project

0x0C. C - More malloc, free





































main.h


#ifndef MAIN_H

#define MAIN_H


#include <stdio.h>

#include <stdlib.h>

#include <limits.h>


int _putchar(char c);

void *malloc_checked(unsigned int b);

char *string_nconcat(char *s1, char *s2, unsigned int n);

void *_calloc(unsigned int nmemb, unsigned int size);

int *array_range(int min, int max);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void errors(void);

int _strlen(char *s);

int is_digit(char *s);


#endif





















0-malloc_checked.c


#include <stdlib.h>

#include "main.h"


/**

 * *malloc_checked - allocates memory using malloc

 * @b: number of bytes to allocate

 *

 * Return: a pointer to the allocated memory

 */

void *malloc_checked(unsigned int b)

{

        void *ptr;


        ptr = malloc(b);


        if (ptr == NULL)

                exit(98);


        return (ptr);

}



















1-string_nconcat.c


#include <stdlib.h>

#include "main.h"


/**

 * *string_nconcat - concatenates n bytes of a string to another string

 * @s1: string to append to

 * @s2: string to concatenate from

 * @n: number of bytes from s2 to concatenate to s1

 *

 * Return: pointer to the resulting string

 */

char *string_nconcat(char *s1, char *s2, unsigned int n)

{

        char *s;

        unsigned int i = 0, j = 0, len1 = 0, len2 = 0;


        while (s1 && s1[len1])

                len1++;

        while (s2 && s2[len2])

                len2++;


        if (n < len2)

                s = malloc(sizeof(char) * (len1 + n + 1));

        else

                s = malloc(sizeof(char) * (len1 + len2 + 1));


        if (!s)

                return (NULL);


        while (i < len1)

        {

                s[i] = s1[i];

                i++;

        }


        while (n < len2 && i < (len1 + n))

                s[i++] = s2[j++];


        while (n >= len2 && i < (len1 + len2))

                s[i++] = s2[j++];


        s[i] = '\0';


        return (s);

}


































2-calloc.c


#include <stdlib.h>

#include "main.h"


/**

 * *_memset - fills memory with a constant byte

 * @s: memory area to be filled

 * @b: char to copy

 * @n: number of times to copy b

 *

 * Return: pointer to the memory area s

 */

char *_memset(char *s, char b, unsigned int n)

{

        unsigned int i;


        for (i = 0; i < n; i++)

        {

                s[i] = b;

        }


        return (s);

}


/**

 * *_calloc - allocates memory for an array

 * @nmemb: number of elements in the array

 * @size: size of each element

 *

 * Return: pointer to allocated memory

 */

void *_calloc(unsigned int nmemb, unsigned int size)

{

        char *ptr;


        if (nmemb == 0 || size == 0)

                return (NULL);


        ptr = malloc(size * nmemb);


        if (ptr == NULL)

                return (NULL);


        _memset(ptr, 0, nmemb * size);


        return (ptr);

}

































3-array_range.c


#include <stdlib.h>

#include "main.h"


/**

 * *array_range - creates an array of integers

 * @min: minimum range of values stored

 * @max: maximum range of values stored and number of elements

 *

 * Return: pointer to the new array

 */

int *array_range(int min, int max)

{

        int *ptr;

        int i, size;


        if (min > max)

                return (NULL);


        size = max - min + 1;


        ptr = malloc(sizeof(int) * size);


        if (ptr == NULL)

                return (NULL);


        for (i = 0; min <= max; i++)

                ptr[i] = min++;


        return (ptr);

}









100-realloc.c


#include <stdlib.h>

#include "main.h"


/**

 * *_realloc - reallocates a memory block using malloc and free

 * @ptr: pointer to the memory previsouly allocated by malloc

 * @old_size: size of the allocated memory for ptr

 * @new_size: new size of the new memory block

 *

 * Return: pointer to the newly allocated memory block

 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{

        char *ptr1;

        char *old_ptr;

        unsigned int i;


        if (new_size == old_size)

                return (ptr);


        if (new_size == 0 && ptr)

        {

                free(ptr);

                return (NULL);

        }


        if (!ptr)

                return (malloc(new_size));


        ptr1 = malloc(new_size);

        if (!ptr1)

                return (NULL);


        old_ptr = ptr;


        if (new_size < old_size)

        {

                for (i = 0; i < new_size; i++)

                        ptr1[i] = old_ptr[i];

        }


        if (new_size > old_size)

        {

                for (i = 0; i < old_size; i++)

                        ptr1[i] = old_ptr[i];

        }


        free(ptr);

        return (ptr1);

}





























101-mul.c


#include "main.h"

#include <stdlib.h>

#include <stdio.h>


#define ERR_MSG "Error"


/**

 * is_digit - checks if a string contains a non-digit char

 * @s: string to be evaluated

 *

 * Return: 0 if a non-digit is found, 1 otherwise

 */

int is_digit(char *s)

{

        int i = 0;


        while (s[i])

        {

                if (s[i] < '0' || s[i] > '9')

                        return (0);

                i++;

        }

        return (1);

}


/**

 * _strlen - returns the length of a string

 * @s: string to evaluate

 *

 * Return: the length of the string

 */

int _strlen(char *s)

{

        int i = 0;


        while (s[i] != '\0')

        {

                i++;

        }

        return (i);

}


/**

 * errors - handles errors for main

 */

void errors(void)

{

        printf("Error\n");

        exit(98);

}


/**

 * main - multiplies two positive numbers

 * @argc: number of arguments

 * @argv: array of arguments

 *

 * Return: always 0 (Success)

 */

int main(int argc, char *argv[])

{

        char *s1, *s2;

        int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;


        s1 = argv[1], s2 = argv[2];

        if (argc != 3 || !is_digit(s1) || !is_digit(s2))

                errors();

        len1 = _strlen(s1);

        len2 = _strlen(s2);

        len = len1 + len2 + 1;

        result = malloc(sizeof(int) * len);

        if (!result)

                return (1);

        for (i = 0; i <= len1 + len2; i++)

                result[i] = 0;

        for (len1 = len1 - 1; len1 >= 0; len1--)

        {

                digit1 = s1[len1] - '0';

                carry = 0;

                for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)

                {

                        digit2 = s2[len2] - '0';

                        carry += result[len1 + len2 + 1] + (digit1 * digit2);

                        result[len1 + len2 + 1] = carry % 10;

                        carry /= 10;

                }

                if (carry > 0)

                        result[len1 + len2 + 1] += carry;

        }

        for (i = 0; i < len - 1; i++)

        {

                if (result[i])

                        a = 1;

                if (a)

                        _putchar(result[i] + '0');

        }

        if (!a)

                _putchar('0');

        _putchar('\n');

        free(result);

        return (0);

}
