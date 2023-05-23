# READ() FUNCTION

The read() function in the C language is used to read data from a file descriptor. It is typically used with files or sockets, but it can also be used with other types of input data streams.

The signature of the read() function is as follows:
```bash
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t count);
```

The parameters of the read() function are:

- `fd` : This is the file descriptor from which the data should be read. A file descriptor is an integer that identifies an open file or another type of input data stream. For example, 0 represents standard input (stdin), 1 represents standard output (stdout), and 2 represents standard error (stderr). File descriptors are typically obtained using functions like open() or socket().
- `buffer` : This is a pointer to the buffer where the read data will be stored.
- `count` : It specifies the maximum number of bytes to read from the file descriptor.
The read() function returns the number of bytes read from the file descriptor. If the returned value is -1, it indicates a read error.

<br>
<br>
<br>

# MALLOC() FUNCTION

The malloc() function in the C language is used for dynamic memory allocation. It allows you to allocate a specified number of bytes from the heap memory at runtime. The term "malloc" stands for "memory allocation."

The signature of the malloc() function is as follows:
```bash
#include <stdlib.h>

void *malloc(size_t size);
```
- `size` : this represents the number of bytes to allocate. It specifies the amount of memory you want to request from the operating system. The malloc() function returns a void pointer (void *) that points to the beginning of the allocated memory block.



# FREE() FUNCTION

The free() function in the C language is used to deallocate memory that was previously allocated dynamically using functions like malloc(), calloc(), or realloc().

The signature of the free() function is as follows:
```bash
#include <stdlib.h>

void free(void *ptr);
```

- `*ptr` : this is a pointer to the memory block that needs to be freed. It should correspond to a memory block previously allocated using malloc(), calloc(), or realloc(). If ptr is a NULL pointer, the free() function does nothing.

When you call the free() function, it releases the specified memory block so that it can be reused later. Once the memory is freed, you should no longer access its content as it would result in undefined behavior.

It is important to note that free() does not modify the value of the ptr pointer itself. This means that the pointer should not be used anymore after calling free() to avoid errors.
