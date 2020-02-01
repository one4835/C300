#include <stdio.h>

void print(char**ppanimal);

void main(void)
{
    char *animal[3];

    animal[0] = "tiger";
    animal[1] = "lion";
    animal[2] = "rabbit";

    print(animal);
}

void print(char **ppanimal)
{
    puts(ppanimal[0]);
    puts(ppanimal[1]);
    puts(ppanimal[2]);
}
