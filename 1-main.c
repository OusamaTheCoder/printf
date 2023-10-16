#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s! You are %d years old.\n", "World", 25);
    _printf("Total characters printed: %d\n", len);

    return (0);
}

