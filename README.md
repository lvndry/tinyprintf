# Tinyprintf

Minimal version of printf from `stdio.h`
Protoype: `printf(const char *fmt, ...)`

## Usage
```
make
gcc -Wall -Werror -Wextra -pedantic -std=c99 -l:libprintf.a main.c
```

```c
#include "tinyprintf.h"
...
printf("Hello World"); // "Hello World"
printf("Hey, C is %s!", "cool"); // "Hey C is cool"
printf("%%"); // "%"
printf("%x\n", 3405691582);  // "cafebabe"
```

## Possible wildcards
| wildcard |    type    |
| :------: | :--------: |
|    %d    |    int     |
|    %c    |    char    |
|    %s    |   char*    |
|    %u    |  unsigned  |
|    %o    |   octal    |
|    %x    | hexadecial |