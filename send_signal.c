/**
 * @file signal_sender.c
 * @brief A program to send a random integer to a specified PID using SIGUSR1.
 *
 * Course: CPE2600
 * Section: 011
 * Assignment: Lab 10
 * Name: Matthew Senn
 *
 * Algorithm:
 * - Check for sufficient command line arguments.
 * - Convert the provided PID from string to integer.
 * - Seed the random number generator.
 * - Generate a random integer and prepare it for sending.
 * - Send the random integer to the specified PID using sigqueue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Insufficient arguments provided!\n");
        return -1;
    }

    int pid = atoi(argv[1]); // Read receiving program's PID from command line
    srand(time(NULL)); // Seed random number generator
    union sigval sig; // Union contains info to send
    sig.sival_int = rand(); // Stage random number to send

    printf("Sending: %d to PID: %d\n", sig.sival_int, pid);
    sigqueue(pid, SIGUSR1, sig); // Send value via SIGUSR1

    return 0;
}
