# Tinyprintf

Minimal implementation of printf from `stdio.h`

Protoype: `tinyprintf(const char *fmt, ...)`

## Usage
``` bash
make
```
or

```bash
gcc -L . -l:libprintf.a <file.c> tinyprintf.c utils.c buffer.c
```

```c
#include "tinyprintf.h"
...
tinyprintf("Hello World"); // "Hello World"
tinyprintf("Hey, C is %s!", "cool"); // "Hey C is cool"
tinyprintf("%%"); // "%"
tinyprintf("%x\n", 3405691582);  // "cafebabe"
```

## Possible wildcards
| wildcard |    type    |
| :------: | :--------: |
|    %c    |    char    |
|    %s    |   char*    |
|    %d    |    int     |
|    %u    |  unsigned  |
|    %o    |   octal    |
|    %x    | hexadecial |