/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT; the handler prints a message and then quits.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Matthew Senn
 *
 * Algorithm:
 * - Print the process ID.
 * - Register a signal handler for SIGINT.
 * - Enter an infinite loop, printing "Sleeping" every second.
 * - Upon receiving SIGINT, print a message and exit.
 */

/**
 * @brief Signal handler for SIGINT - prints a message and exits.
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(0); // Exit the program after handling the signal
}

int main() {
    printf("PID: %d\n", getpid()); // Print the process ID

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while (1) {
        printf("Sleeping\n");
        sleep(1); // Sleep for 1 second
    }

    return 0;
}
