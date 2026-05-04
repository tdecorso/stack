#include "stack.h"
#include "test.h"

int main(void) {
    TEST_SECTION("Stack initialization") {
        int* numbers = NULL;

        CHECK_BOOL(
            STACK_HEADER(numbers) == NULL,
            "Stack header is null for null pointers.",
            ""
        );

        CHECK_BOOL(
            STACK_CAPACITY(numbers) == 0,
            "Stack capacity is zero for null pointers.",
            ""
        );

        CHECK_BOOL(
            STACK_COUNT(numbers) == 0,
            "Stack count is zero for null pointers.",
            ""
        );

        STACK(numbers, 10);
        if (!numbers) exit(EXIT_FAILURE);

        CHECK_BOOL(
            STACK_CAPACITY(numbers) == 10,
            "Capacity matches given input.",
            ""
        );
        
        CHECK_BOOL(
            STACK_COUNT(numbers) == 0,
            "Count is zero at initialization.",
            ""
        );

        STACK_FREE(numbers);
    };

    TEST_SECTION("Stack insertion & pop") {
        int* numbers = NULL;
        STACK(numbers, 5);

        for (int i = 0; i < 7; ++i) {
            STACK_APPEND(numbers, i+1);
        }

        CHECK_BOOL(
            STACK_COUNT(numbers) == 5,
            "Count gets clamped over capacity.",
            ": count is %zu", STACK_COUNT(numbers)
        );

        CHECK_BOOL(
            numbers[0] == 6 &&
            numbers[1] == 7 && 
            numbers[2] == 3 && 
            numbers[3] == 4 && 
            numbers[4] == 5,
            "Out of capacity index wraps around [0-capacity]",
            "%d - %d - %d - %d - %d", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]
        );

        int last = STACK_PEEK(numbers);

        CHECK_BOOL(
            last == 7,
            "Peek retrieves last element in the stack.",
            ""
        );

        STACK_DISCARD(numbers);

        last = STACK_PEEK(numbers);

        CHECK_BOOL(
            last == 6,
            "Peek after discard retrieves last element in the stack.",
            ""
        );

        STACK_FREE(numbers);
    };

    TEST_SUMMARY();

    exit(EXIT_SUCCESS);
}
