# Queue Implementation in C

This is a macro-based header-only implementation of queues in C. It makes use of a circular buffer, you can overwrite the oldest element if you insert
more elements than the specified capacity. It does not have reallocation capabilities.

## Usage

Its usage is very similar to my implementation of dynamic arrays:
### Initialization
```
int *numbers = NULL;
// you define a capacity, this will be the maximum number of items
QUEUE(numbers, 10); 
```

### Insertion
```
int *numbers = NULL;
QUEUE(numbers, 10);
// you can append items to the queue, if you exceed the capacity, you overwrite the queue
QUEUE_APPEND(numbers, 1); 
```

### Peeking
```
int *numbers = NULL;
QUEUE(numbers, 10);
QUEUE_APPEND(numbers, 1);
// peeking doesn't remove the element, it just retrieves the first item you entered
int first = QUEUE_PEEK(numbers); 
```

### Discarding
```
int *numbers = NULL;
QUEUE(numbers, 10);
QUEUE_APPEND(numbers, 1);
int first = QUEUE_PEEK(numbers);
// discard drops the oldest element you inserted
QUEUE_DISCARD(numbers); 
```

## Tests

Tests are included in the repo. You can run them with:
```
gcc test.c -o test && ./test
```
