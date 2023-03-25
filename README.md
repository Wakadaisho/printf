# Topic: 0x11. C - printf

This project is meant to be a rudimetary implementation of the printf function that exist in the C standard library.

The project files are laid out as follows:
- `main.h`: contains all function defintions typedefs of structs used in the rest of the source files.
- `printf.c`: contains the main function defintion for `_printf`. Also contains a helper function,`_putarg`, for handling variadic parameters by their respective type.
- `get_spec.c`: retuns a function pointer that prints out a type based on a format specifier character.
- `print_types.c`: contains function defintions for printing different arguments based on the type. these functions are what `get_spec.c` references.
- `alpha.c`: This is a helper function to check the case of a letter.

## Tasks

### Task 0
Handles the following conversion specifiers; `c`, `s`, `%`.

### Task 1
Handles the following conversion specifiers; `d`, `i`.
