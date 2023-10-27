# push_swap

<br>

## 🌕 What is push_swap ?

The push_swap is an individual project at [42 Tokyo][1].

<br>

The purpose of this project is to implement various algorithms and select the most suitable solution for efficient data sorting.

<br>

You begin with two empty stacks: A and B, and receive a random list of integers through command line arguments.

<br>

Given a set of integers, sort them using the predefined instructions with two stacks.

<br>

### 🌖 push_swap

This program generates an executable called `push_swap` which displays the instructions, which is below, to sort the given integers.

<br>

| instructions  | Description   |
|:-------------|:---------------|
| sa (swap A)   | Swap first two elements at the top of stack A |
| sb            | Swap first two elements at the top of stack B |
| ss            | sa and sb at the same time |
| pa (push A)   | Pops the first elememt at the top of B and puts it at the top of A |
| pb            | Pops the first elememt at the top of A and puts it at the top of B |
| ra (rotate A) | shift up all elements of stack A by 1 (The first element becomes the last one) |
| rb            | Shift up all elements of stack B by 1 (The first element becomes the last one) |
| rr            | ra and rb at the same time |
| rra (reverse rotate A) | Shift down all elements of stack A by 1 (The last element becomes the first one) |
| rrb           | Shift down all elements of stack B by 1 (The last element becomes the first one) |
| rrr           | rra and rrb at the same time |

<br>

### 🌖 checker

Additionally, this program produce an executable called `checker` as a bonus component.

<br>

The checker program reads a random list of integers from standard input (stdin), stores them, and verifies if they are sorted.

<br>

You can pipe the output of push_swap into checker, and checker will confirm the success of push_swap's instructions.

<br>

Both programs are required to rigorously parse input for errors, including empty strings, absence of parameters, non-numeric parameters, duplicates, and invalid/non-existent instructions

<br><br>

## 🌕 Usage

### 🌖 Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
<br><br>

### 🌖 Instructions

#### 🌗 1. Clone the repository

```shell
git clone --recursive git@github.com:hosuzuki/push_swap.git
```

The ``--recursive`` flag helps you initialize submodules in the clone.

<br>

And them, move to the cloned directory.
```shell
cd push_swap
```

<br>

#### 🌗 2. Run make to generate `push_swap`

run the ``make`` command.
```shell
make
```

The Makefile compiles all files from the ``srcs/`` folders and saves the object files to the ``objs/`` folder. 

<br>

Running the `make` command also automatically generates a library called `libftprintf.a` in ft_printf directory.

<br>

It then generates the executable `push_swap` in the root directory.

<br>

#### 🌗 3. Run `push_swap`

```C
./push_swap [set of intergers]
```

<br>

For instance, run the command below.

```C
./push_swap 2 3 1
```

Alter the execution, it should output `rra` which means rotating stuck A down by one. (`2 3 1` -> `1 2 3`)

<br>

#### 🌗 4. Generate `checker` executable

Runnning a command below generates an executable called `checker`.
```shell
make bonus
```
<br>

#### 🌗 5. Run `checker`

```C
./push_swap [set of intergers] | ./checker [set of intergers <same as on the left>] 
```

<br>

For instance, run the command below.

```C
./push_swap 2 3 1 | ./checker 2 3 1
```

<br>

After the execution, it should output `OK` which means that `push_swap`'s instructions have correctly sorted the given set of integers.

<br><br>

## 🌕 Additional tools

### 🌖 Checker provided by 42

| File Name  | Description   |
|:-------------|:---------------|
| checker_mac                        | a checker program for Mac |
| checker_linux                      | a checker program for Linux |

Because of these checker program, we are able to check whether the list of instructions generated by the push_swap program actually sorts the stack properly.

#### 🌗 How to use

It will work as follows:

```shell
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

It should displays `OK`.

If the program checker_mac or checker_linux displays `KO`, it means that the push_swap came up with a list of instructions that doesn’t sort the numbers.


### 🌖 Tester

| File Name  | Description   |
|:-------------|:---------------|
| [test_mac.sh](test_mac.sh)         | sa and sb at the same time |
| [test_linux.sh](test_linux.sh)     | pops the first elememt on B and puts it on top of A |
| [test_checker.sh](test_checker.sh) | rotates stuck B up by one |
| [test_error.sh](test_error.sh)     | rotates both A and B up by one |
| [test_error_checker.sh](test_error_checker.sh) | rotates stuck A down by one |
| [test_valgrind.sh](test_valgrind.sh) | rotates stuck A up by one|
| [test_review.sh](test_review.sh)   | pops the first elememt on A and puts it on top of B |

<br><br>

## 🌕 Visual result

Thanks to ~~, you can see how my algorithm works below.


[1]: https://42tokyo.jp/
