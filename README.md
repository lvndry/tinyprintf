# Tinyprintf

Minimal version of printf from `stdio.h`
Protoype: `tinyprintf(const char *fmt, ...)`

## Usage
```
make
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
|    %d    |    int     |
|    %c    |    char    |
|    %s    |   char*    |
|    %u    |  unsigned  |
|    %o    |   octal    |
|    %x    | hexadecial |