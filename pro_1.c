#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/reg.h>

int main()
{   pid_t child;
    long orig_rax;
    child = fork();
    if(child == 0) { // 子进程:
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);   //告诉内核这个进程将被其父进程追踪

        // printf("Hello from child process!\n");
        // fflush(stdout);
        // 执行 execve 系统调用时，它将控制权移交给其父进程。父进程通过 wait() 调用等待来自内核的通知
        execl("/bin/ls", "ls", NULL);
    }
    else {  // 父进程:
        wait(NULL);
        orig_rax = ptrace(PTRACE_PEEKUSER,      // 读取子进程的系统调用号
                          child, 8 * ORIG_RAX,
                          NULL);
        printf("The child made a "
               "system call %ld\n", orig_rax);          // output: The child made a system call 59
        ptrace(PTRACE_CONT, child, NULL, NULL); // 继续执行子进程。
    }
    return 0;
}