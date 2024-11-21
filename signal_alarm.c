/**
 * @file alarm_signal.c
 * @brief A program that sets an alarm to trigger a signal after 5 seconds.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Matthew Senn
 *
 * Algorithm:
 * - Set up a signal handler for SIGALRM.
 * - Set an alarm to go off after 5 seconds.
 * - Enter an infinite loop, printing "Sleeping!" every second.
 * - Upon receiving the alarm signal, print a message and exit.
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Function prototype for the signal handler
void handle_signal();

int main() {
    signal(SIGALRM, handle_signal); // Register the signal handler
    alarm(5); // Set an alarm for 5 seconds

    while (1) {
        printf("Sleeping!\n");
        sleep(1); // Sleep for 1 second
    }

    return 0; 
}

/**
 * @brief Signal handler for SIGALRM.
 * 
 * This function is called when the alarm signal is received.
 */
void handle_signal() {
    printf("Alarm received!\n");
    exit(1); // Exit the program
}
