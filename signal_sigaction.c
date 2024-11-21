/**
 * @file signal_handler.c
 * @brief Program that sets a signal handler for SIGUSR1 and prints the PID of the sender.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Matthew Senn
 *
 * Algorithm:
 * - Print the process ID.
 * - Set up a signal handler for SIGUSR1 using sigaction.
 * - Enter an infinite loop, waiting for signals.
 * - Upon receiving SIGUSR1, print the PID of the sender.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1 - prints the PID of the sender.
 * 
 * @param sig - The signal number.
 * @param info - Information about the signal.
 * @param context - Context of the signal.
 */
void handle_signal(int sig, siginfo_t *info, void *context);

int main() {
    printf("PID: %d\n", getpid()); // Print the process ID

    struct sigaction act; // Structure to hold the signal action
    act.sa_flags = SA_SIGINFO; // Indicate that we want additional info
    act.sa_sigaction = handle_signal; // Set the signal handler

    sigaction(SIGUSR1, &act, NULL); // Register the signal handler for SIGUSR1

    while (1) {
        // Infinite loop waiting for signals
    }

    return 0;
}

/**
 * @brief Signal handler for SIGUSR1 - prints the PID of the sender.
 * 
 * @param sig - The signal number.
 * @param info - Information about the signal.
 * @param context - Context of the signal.
 */
void handle_signal(int sig, siginfo_t *info, void *context) {
    int pid = info->si_pid; // Get the PID of the sender
    printf("Sent by PID: %d\n", pid); // Print the sender's PID
}
