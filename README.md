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
|:-------------:|:---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

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

#### 🌗 2. Run make

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

#### 🌗 3. Run push_swap

```C
./push_swap [set of intergers]
```

<br>

For instance, run the command below.

```C
./push_swap 2 3 1
```

Alter the execution, it should output `rra` which means rotating stuck A down by one. (`2 3 1` -> `1 2 3`)

#### 🌗 4. Generate `checker` executable

Runnning a command below generates an executable called `checker`.
```shell
make bonus
```
<br>

#### 🌗 5. Run checker


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

## 🌕 Tester

[ft_lstnew](srcs/ft_lstnew.c)

| File Name  | Description   |
|:-------------|:---------------|
| checker_mac   | swap first two elements of stack A |
| checker_linux | swap first two elements of stack B |
| [test_mac.sh](test_mac.sh)  | sa and sb at the same time |
| [test_linux.sh](test_linux.sh) | pops the first elememt on B and puts it on top of A |
|             | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

## 🌕 Visual result


[1]: https://42tokyo.jp/
