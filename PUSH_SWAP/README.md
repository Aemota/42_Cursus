# Push Swap

This project, **Push Swap**, is part of the curriculum at Campus 42. The goal of this project is to create a sorting algorithm that can arrange a stack of integers in ascending order, using a limited set of operations.

The project consists of a program called **push_swap**. The **push_swap** program takes a list of integers as input and outputs a series of operations that will sort the stack.

## Installation

To compile the **push_swap** program, clone the project repository and navigate to the project's root directory in your terminal. Then, run the following command:

```
make
```

This will compile the necessary files and generate the executable **push_swap**.

## Usage

To use the **push_swap** program, run the following command:

```
./push_swap [list_of_integers]
```

Replace `[list_of_integers]` with the integers you want to sort. The program will output a series of operations that will sort the stack.

## Rules

The **push_swap** program operates on a stack named `a`. The available operations are as follows:

- **sa**: Swap the top two elements of stack `a`.
- **sb**: Swap the top two elements of stack `b`.
- **ss**: Swap the top two elements of both stacks `a` and `b`.
- **pa**: Push the top element from stack `b` to stack `a`.
- **pb**: Push the top element from stack `a` to stack `b`.
- **ra**: Rotate stack `a` (move the top element to the bottom).
- **rb**: Rotate stack `b` (move the top element to the bottom).
- **rr**: Rotate both stacks `a` and `b`.
- **rra**: Reverse rotate stack `a` (move the bottom element to the top).
- **rrb**: Reverse rotate stack `b` (move the bottom element to the top).
- **rrr**: Reverse rotate both stacks `a` and `b`.

## Algorithm

The **push_swap** program utilizes the **Radix Sort** algorithm to sort the stack efficiently. Radix Sort is a non-comparative sorting algorithm that sorts integers by grouping them by individual digits or by significant places.

In the context of the **push_swap** project, Radix Sort is implemented by performing multiple passes through the stack, sorting the elements based on their digits from the least significant to the most significant. This approach allows the program to sort the stack using a limited set of operations.

## Example

Here is an example usage of the **push_swap** program:

```
$ ./push_swap 321 15 87
ra
pb
sa
pa
```

In this example, the **push_swap** program outputs the operations `ra` (rotate `a`), `pb` (push `b`), `sa` (swap `a`), and `pa` (push `a`) to sort the stack.

## Final Score

✅ 84% 
