/*
 * =====================================================================================
 *
 *       Filename:  buffer.h
 *
 *    Description:  Header of buffer.h. Get all function using a buffer
 *
 *        Version:  1.0
 *        Created:  09/16/2019 02:50:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (Landry Monga <lvndry@protonmail.com>), 
 *
 *
 * =====================================================================================
 */

#define BUFFER_SIZE 128

void buffer_flush(char buffer[], unsigned int *size);
int buffer_write(char buffer[], char c, unsigned int *size);
int buffer_write_int(char buffer[], int n, unsigned *size);
int buffer_write_int_base(char buffer[], int n, int base, unsigned int *size);
