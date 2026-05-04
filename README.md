# Stack Implementation in C

This is a macro-based header-only implementation of stacks in C. It makes use of a circular buffer, you can overwrite if you insert
more elements than the specified capacity. It does not have reallocation capabilities.

## Usage

Its usage is very similar to my implementation of dynamic arrays:
### Initialization
```
int *numbers = NULL;
// you define a capacity, this will be the maximum number of items
STACK(numbers, 10); 
```

### Insertion
```
int *numbers = NULL;
STACK(numbers, 10);
// you can append items to the stack, if you exceed the capacity, you overwrite it
STACK_APPEND(numbers, 1); 
```

### Peeking
```
int *numbers = NULL;
STACK(numbers, 10);
STACK_APPEND(numbers, 1);
// peeking doesn't remove the element, it just retrieves the last item you entered
int first = STACK_PEEK(numbers); 
```

### Discarding
```
int *numbers = NULL;
STACK(numbers, 10);
STACK_APPEND(numbers, 1);
int first = STACK_PEEK(numbers);
// discard drops the newest element you inserted
STACK_DISCARD(numbers); 
```

## Tests

Tests are included in the repo. You can run them with:
```
gcc test.c -o test && ./test
```
