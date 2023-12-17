# ft_printf Project

Welcome to the ft_printf project! 🖨️ In this project, you are tasked with recoding the printf() function from libc.

## Project Overview

- **Function Prototype:** `int ft_printf(const char *, ...);`
- **Buffer Management:** You are not required to implement the buffer management of the original printf().
- **Conversions Handled:** Your function must handle the following conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`.
- **Library Creation:** Use the `ar` command to create your library (`libftprintf.a`). Avoid using the `libtool` command.

## Requirements

- Your `libftprintf.a` library must be created at the root of your repository.
- Your implementation will be compared against the original `printf()`.

## Supported Conversions

- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The `void *` pointer argument is printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## How to Use 🚀

1. Clone the repository to your local machine.
2. Navigate to the project folder.
3. Build the project using the provided Makefile.
   ```
   $ make
   ```
Create the library (libftprintf.a) using the ar command.
  ```
  $ ar -rcs libftprintf.a [your object files]
  ```
Link your program with libftprintf.a during compilation.
  ```
  $ gcc -o your_program [your_program.c] -L. -lftprintf
  ```
Run your program.
  ```
  $ ./your_program
  ```
