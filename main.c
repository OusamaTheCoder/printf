#include <stdio.h>
#include "main.h"

int main(void)
{
    char c = 'A';
    char *str = "Hello, world!";

    int count = _printf("Character: %c\nString: %s\nPercent: %%\n", c, str);

    _printf("Number of characters printed: %d\n", count);

    return (0);
}
