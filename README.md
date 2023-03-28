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

### Task 2
Handles the following concersion specifier; `b`.

### Task 3 
Handles the following conversion specifiers; `u`, `o`, `x`,`X.`

### Task 4
Uses a local buffer of 1024 chars in order to call write as little as possible.

### Task 5
Handles the following custom conversion specifier; `s` and ` Non printable characters`

### Task 6
Handles the following concersion specifier; `p`.

### Task 7
Handles the following flag characters for non-custom conversion specifiers; `+`, `space`, `#`.

### Task 8
Handles the following length modifiers for non-custom conversion specifiers; `d`, `i`, `u`, `o`, `x`, `X`

### Task 9
Handles the field width for non-custom conversion specifiers.

### Task 10
Handlea the precision for non-custom conversion specifiers.

### Task 11
Handles the 0 flag character for non-custom conversion specifiers.

### Task 12
Handles the - flag character for non-custom conversion specifiers.

### Task 13
Handles the following custom conversion specifier: `r`
