In Bash, a shell builtin is a command implemented inside Bash itself, rather than a separate executable such as /usr/bin/ls.

You can see all Bash builtins with:

compgen -b

Or:

help
Important Bash builtins
Builtin	Purpose
cd	Change directory
pwd	Print current directory
echo	Print text/variables
printf	Formatted output
read	Read user input
export	Export variables to child processes
unset	Remove variables/functions
alias	Create command aliases
unalias	Remove aliases
type	Identify what a command is
command	Execute/inspect a command without function/alias lookup effects
source / .	Execute another file in the current shell
declare	Declare variables and attributes
local	Create function-local variables
readonly	Make variables read-only
set	Configure shell options/positional parameters
shift	Shift positional parameters
test / [	Evaluate conditions
true	Return success (0)
false	Return failure (non-zero)
exit	Exit the shell
return	Return from a function/sourced script
break	Exit a loop
continue	Continue to next loop iteration
jobs	Show shell jobs
fg	Bring job to foreground
bg	Resume job in background
wait	Wait for process/job completion
kill	Send a signal
trap	Handle signals/events
exec	Replace current shell with another command
history	Display/manage command history
getopts	Parse command-line options
umask	Set default permission mask
ulimit	Display/set shell resource limits
How to check whether something is a builtin

This is particularly useful for interview practice:

type cd
type echo
type printf
type read
type ls

You'll see something like:

cd is a shell builtin
echo is a shell builtin
printf is a shell builtin
read is a shell builtin
ls is /usr/bin/ls

Another useful command:

type -a echo

You may discover both a builtin and an external program:

echo is a shell builtin
echo is /usr/bin/echo
Why cd must be a builtin

This is a classic Linux/Shell interview question.

If cd were an external program:

bash
 │
 ├── fork()
 │
 └── child process
       └── cd /tmp

The child could change its working directory, but when it exited, Bash would still be in its original directory.

Because cd is executed inside the current Bash process, it can change Bash's own working directory:

cd /tmp
pwd
/tmp

For your Bash refresher, I'd especially know cd, read, printf, export, source, type, test/[, set, shift, trap, jobs, fg, bg, wait, exec, return, and exit. These are the ones I'd prioritise for Linux/support interviews.


