#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
using namespace std;

void print_numbers(int start, int writer, int reader) {
    for (int i = start; i <= 100; i += 2) {
        char buf;
        read(reader, &buf, 1);

        cout << i << ' ';
        fflush(stdout);

        write(writer, &buf, 1);
    }
}

void pipe_test() {
    printf("\033[35m>>>>>>>>>>> Test pipe Start <<<<<<<<<<<\033[0m\n");
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();
    if (pid == 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        print_numbers(1, pipe1[1], pipe2[0]);

        close(pipe1[1]);
        close(pipe2[0]);
    } else {
        close(pipe1[1]);
        close(pipe2[0]);

        char signal = 's';
        write(pipe2[1], &signal, 1);

        print_numbers(2, pipe2[1], pipe1[0]);

        close(pipe1[0]);
        close(pipe2[1]);

        wait(NULL);
    }

    cout << endl;
    printf("\033[35m>>>>>>>>>>> Test pipe Passed <<<<<<<<<<<\033[0m\n");
}