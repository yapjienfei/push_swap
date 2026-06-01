_This project has been created as part of the 42 curriculum by jyap._

# Push_swap – Turk Algorithm with Three‑Case Optimisation

## Description

**Push_swap** is a highly structured algorithmic challenge: sort a stack of integers using a limited set of operations (swap, push, rotate, reverse rotate) and two stacks (`a` and `b`). The goal is to output the **shortest possible sequence** of instructions that sorts stack `a` in ascending order.

This implementation uses the **Turk algorithm** with a custom optimisation: for each element in stack `a`, three rotation strategies are evaluated – rotating both stacks up together, rotating both stacks down together, or rotating each independently – and the strategy with the lowest move count is chosen. This greedy decision‑making minimises the total number of operations.

The program is written in **C**, complies with the 42 Norm, and handles error cases (non‑integers, duplicates, overflow) gracefully.

## Instructions

### Compilation

Run `make` in the project root. The `Makefile` provides the following rules:

- `make all` (or simply `make`) – compiles the `push_swap` executable.
- `make clean` – removes object files.
- `make fclean` – removes object files and the executable.
- `make re` – recompiles everything from scratch.

### Execution

```bash
./push_swap [list of integers]
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program prints a sequence of instructions (one per line) that sorts the stack. If no arguments are given, nothing is printed. On error (invalid input, duplicate, overflow), it prints `Error` to standard error and exits.

### Checking the output

Use the provided `checker_linux` (or `checker_Mac`) program:

```bash
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
```

Expected output: `OK` if the sequence sorts correctly, `KO` otherwise.

## Algorithm Overview

The core sorting strategy works as follows:

1. **Small stacks** (size ≤ 5) are handled by dedicated optimised routines (`sort_three`, `sort_five`).
2. **Larger stacks** (size > 5):
   - Push two elements to stack `b` to initialise.
   - Repeatedly push the **cheapest** element from `a` to `b`. Cheapest is determined by evaluating for each element in `a`:
     - **Case 1** – rotate both stacks upwards until one reaches the top, then rotate the remaining individually.
     - **Case 2** – same as Case 1 but rotate downwards instead.
     - **Case 3** – rotate each stack independently (optimal direction for each).
   - The case with the smallest total moves is selected.
   - Continue until only 3 elements remain in `a`. Sort those 3 with a hard‑coded optimal sequence.
   - Finally, push all elements from `b` back to `a`, rotating `a` as needed to maintain sorted order, and rotate the whole stack so the smallest element is on top.

All operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) are implemented and print their corresponding instruction.

## Resources
- [Turk algorithm explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### AI usage

This project was developed with the assistance of an AI assistant. AI was used for:
- Refactoring code to comply with the 42 Norm (function length, variable count, file splitting).
- Debugging rotation loops and edge cases (especially `sort_three` and `sort_five`).
- Generating this README and suggesting project structure.

All AI‑generated code was reviewed, tested, and adjusted manually to ensure correctness and adherence to the subject requirements.

## File Structure

```
.
├── Makefile
├── push_swap.h
├── push_swap.c
├── parse.c
├── op_rotate.c
├── op_reverse_rotate.c
├── op_swap_push.c
├── utils.c
├── sort_utils.c
├── sort_utils_2.c
├── get_target.c
├── case_rotate.c
└── execute_case_rotations.c
```

Each file is small and focused, following the Norm. The core sorting logic is spread across `sort_utils.c` (main dispatcher, `push_back`), `sort_utils_2.c` (`sort_three`, `sort_five`, `push_all_but_three`), `get_target.c` (target finding and cost calculation), `case_rotate.c` (three cost case definitions), and `execute_case_rotations.c` (rotations execution).

## Performance

- Sorts 100 random numbers in **<700 operations**.
- Sorts 500 random numbers in **<5500 operations**.

These results satisfy the maximum validation requirements of the project.

## License

This project is part of the 42 curriculum and is provided for educational purposes.
