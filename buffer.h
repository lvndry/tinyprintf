#define BUFFER_SIZE 126

void buffer_flush(char buffer[], unsigned int *size);
int buffer_write(char buffer[], char c, unsigned int *size);
int buffer_write_int(char buffer[], int n, unsigned *size);
int buffer_write_int_base(char buffer[], int n, int base, unsigned int *size);
