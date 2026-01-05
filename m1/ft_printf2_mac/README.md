# ft_printf

This project has been created as part of the 42 curriculum by uregis-d.

## Description
The main goal of this project is to learn and practice variadic functions, as well as to familiarize with related functionalities by replicating the printf function from the stdio.h library.

## Instructions
To use this function, first you need to run the command `make` to compile the .c files and generate the static library.

Then, compile your test.c file linking it with the libftprintf library:
```bash
cc -Wall -Wextra -Werror test.c -L. -lftprintf -o test
```

If you need to recompile everything, use the commands below:
```bash
make re && cc -Wall -Wextra -Werror test.c -L. -lftprintf -o test && ./test
```

## Resources
The three main resources used in this project were: Google search for simple questions, documentation to understand variadic functions, and AI tools like ChatGPT and Perplexity AI. I used AI to generate examples of variadic functions, detect persistent bugs, and get insights to improve my code. GitHub was also useful to see how other people approached their projects and get inspiration.

## Some justifications about logic choices
At first, I used a lot of static functions, which made the code quite disorganized. After successive tries, I realized that it's more interesting to modularize the project and put important functions inside the library. Refactoring was done and the project is much better now.

It's important to note that some libft functions were modified to meet the project's objectives. Because of this, those functions may have the same name but will behave differently in case of errors.
So, to use these functions alongside the other libft functions, I suggest placing them in a separate folder.

## Quick reference for important commands
```bash
make re 
# Recompile and regenerate the library

cc -Wall -Werror -Wextra test.c -L. -lftprintf -o test
# Compile and link the test file, generating the test binary

./test
# Execute the test file
```