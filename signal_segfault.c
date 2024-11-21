/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Matthew Senn
 *
 * Algorithm:
 * - Set up a signal handler for SIGSEGV.
 * - Declare a null pointer.
 * - Dereference the null pointer to trigger a segmentation fault.
 * - Handle the segmentation fault in the signal handler.
 */

/**
 * @brief Signal handler for SIGSEGV - prints a message when a segmentation fault occurs.
 */
void handle_signal() {
    printf("Seg fault occurred!\n");
    exit(1); // Exit the program after handling the signal
}

int main(int argc, char* argv[]) {
    signal(SIGSEGV, handle_signal); // Register the signal handler for SIGSEGV

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i); // This will cause a segmentation fault

    // Return to exit the program (this line will not be reached)
    return 0;
}
