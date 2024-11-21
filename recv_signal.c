#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/**
 * @file recv_signal.c
 * @brief A program to demonstrate signal handling using SIGUSR1.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Mathew Senn
 *
 * Algorithm:
 * - Set up a signal handler for SIGUSR1.
 * - Print the process ID for sending signals.
 * - Enter an infinite loop to wait for signals.
 */

void handle_signal(int sig, siginfo_t *info, void *ucontext);

/**
 * @brief Main function to set up signal handling.
 * 
 * @return int - Exit status of the program.
 */
int main() {
    struct sigaction act; // struct of sigaction options

    act.sa_sigaction = handle_signal; // Register function
    act.sa_flags = SA_SIGINFO; // Indicate info required
    sigaction(SIGUSR1, &act, NULL); // Register signal

    printf("PID: %d\n", getpid()); // Show PID for sending program to use

    while (1) {
        // Do nothing, waiting for signals
    }

    return 0; 
}

/**
 * @brief Signal handler for SIGUSR1.
 * 
 * @param sig - The signal number.
 * @param info - Information about the signal.
 * @param ucontext - Context of the signal.
 */
void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    printf("Received data: %d\n", info->si_value.sival_int);
}
