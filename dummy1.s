.data
hello:
    .string "hello world\n"
.globl  main
main:
    # write system call
    mov     $1, %rax        # syscall number for write
    mov     $1, %rdi        # file descriptor 1 (stdout)
    lea     hello(%rip), %rsi  # pointer to string
    mov     $12, %rdx       # length of string
    syscall                 # invoke system call

    # exit system call
    mov     $60, %rax       # syscall number for exit
    xor     %rdi, %rdi      # exit code 0
    syscall                 # invoke system call

    ret                     # return
