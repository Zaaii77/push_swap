# Push Swap

Push Swap is a sorting algorithm project designed to sort a stack of integers using a limited set of operations. The goal is to achieve the sorting with the minimum number of moves. This project is part of the 42 curriculum and serves as an excellent introduction to algorithm optimization and data structure manipulation.

## Key Features

- Implements sorting using stacks and a limited set of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.).
- Focuses on optimizing the number of moves required to sort the stack.
- Handles edge cases such as duplicate values, invalid inputs, and large datasets.

## Educational Value

This project is particularly valuable for learning and mastering **linked lists**. It provides hands-on experience with:

- Creating and managing linked list nodes.
- Traversing and manipulating linked lists efficiently.
- Understanding the importance of pointers and memory management in C.

## How It Works

The program uses two stacks (`a` and `b`) and performs operations to sort the integers in ascending order. The operations are predefined and must be used strategically to minimize the number of moves.

### Operations

- **Swap**: Swap the first two elements of a stack.
- **Push**: Move the top element from one stack to another.
- **Rotate**: Shift all elements of a stack up by one.
- **Reverse Rotate**: Shift all elements of a stack down by one.

## Compilation and Usage

To clone the project, run:

```bash
git clone git@github.com:Zaaii77/push_swap.git
cd push_swap
```

To compile the project, run:

```bash
make
```

To execute the program:

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 4 67 3 87 23
```

## Learning Outcomes

By completing this project, you will:

1. Gain a deep understanding of linked lists and their operations.
2. Learn to implement and optimize algorithms in C.
3. Improve your problem-solving and debugging skills.
4. Develop a better understanding of memory management and pointer manipulation.

## License

This project is part of the 42 curriculum and is intended for educational purposes.
