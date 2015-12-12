#include <stdio.h>
#include <stdlib.h>

#define SHELLSCRIPT "\
#/bin/bash \n\
./k.sh\
"

int main()
{
    puts("Will execute sh with the following script :");
    puts(SHELLSCRIPT);
    puts("Starting now:");
    system(SHELLSCRIPT);
    return 0;
}
