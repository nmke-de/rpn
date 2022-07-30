# rpn

**rpn**, short for **R**everse **P**olish **N**otation, is a reverse polish notation calculator over integer numbers.

## But why?

No particular reason. This is mostly a test. For a calculator with more features, checkout [Unix `dc`](https://www.gnu.org/software/bc/manual/dc-1.05/html_mono/dc.html)

## Dependencies

- libc (including an implementation of termios.h and stdio.h)
- C compiler (i.e. gcc or [cproc](https://github.com/michaelforney/cproc))
- Included git submodules ([Itoa](https://github.com/nmke-de/Itoa) and [Lex](https://github.com/nmke-de/Lex))

## Build

Type `make`.

## Usage

Type `./rpn` to start the program. You will be faced with an empty input prompt. Entering something like `14 27 +p` will add the numbers 14 and 27 and print the result of the summation.

Use the following commands:

| Command | Effect |
| ------- | ------ |
| any integer number | put a number on the top of the stack. |
| `c` | Clear the entire stack. |
| `D` | Remove topmost number from stack. |
| `d` | Duplicate topmost number and put it on the top of the stack. |
| `p` | Print topmost number, without any change to the stack. |
| `q` | Exit. |
| `+`, `-`, `*`, `/`, `%` | Add/Subtract/Multiply/Divide/do the modulo operation on the two topmost numbers, remove them and put the result on the top of the stack. |

Any other command or character will be ignored.