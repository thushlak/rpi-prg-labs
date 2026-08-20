 Branching Quiz Notes

These notes explain the five C branching examples, including semicolons
after if, else association, printf() return values, nested if,
and pre/post increment and decrement.

1. Semicolon After if

Code

#include <stdio.h>

int main()
{
    int x = 10;

    if (x < 1);

    printf("To be or not to be!");

    printf("That's a big question.");

    return 0;
}

Explanation

The important line is:

if (x < 1);

The semicolon immediately terminates the if statement. It is
effectively:

if (x < 1)
{
    // do nothing
}

Since x = 10, the condition 10 < 1 is false, but the only thing
controlled by the if is the empty statement ;.

Both printf() statements are therefore unconditional.

Output

To be or not to be!That's a big question.

Without the Semicolon

if (x < 1)
    printf("To be or not to be!");

printf("That's a big question.");

Now the first printf() is controlled by the if. Since 10 < 1 is
false, it is skipped.

Output:

That's a big question.

Key Rule

Avoid accidentally writing:

if (condition);

when you intended:

if (condition)
{
    // statements
}

A semicolon is itself a valid empty C statement.

2. Why else Fails After if (...);

Code

#include <stdio.h>

int main()
{
    int x = 10;

    if (x < 1);

    printf("To be or not to be!");

    else

    printf("It's me whom you love to see");

    printf("That's a big question");

    return 0;
}

Explanation

The semicolon completes the if:

if (x < 1)
    ;

Then this is a separate statement:

printf("To be or not to be!");

When the compiler reaches else, there is no unmatched if available
for it.

This produces a compiler error similar to:

else without a previous if

Correct Version

#include <stdio.h>

int main()
{
    int x = 10;

    if (x < 1)
    {
        printf("To be or not to be!");
    }
    else
    {
        printf("It's me whom you love to see");
    }

    printf("That's a big question");

    return 0;
}

Because 10 < 1 is false, the else executes.

Key Rule

An else must belong directly to an unmatched if.

3. printf() Inside an if Condition

Code

#include <stdio.h>

int main()
{
    if (printf("Hello,") > 10)

        printf("Are you taking this seriously?");

    else

        printf("I love you always!");

    return 0;
}

Explanation

printf() not only prints text; it also returns the number of
characters successfully printed.

printf("Hello,")

prints six characters:

H e l l o ,
1 2 3 4 5 6

So the condition becomes:

if (6 > 10)

which is false.

Therefore the else executes.

Output

Hello,I love you always!

Hello, still appears because printf() has to execute to produce its
return value.

Execution Flow

printf("Hello,")
       |
       +-- prints "Hello,"
       |
       +-- returns 6
              |
              v
           6 > 10
              |
            FALSE
              |
              v
    "I love you always!"

Key Rule

A function returning a value can be used as part of a condition:

if (function() > value)

4. Post-Increment / Post-Decrement in Nested if

Code

#include <stdio.h>

int main()
{
    int x = 10, y = 9;

    if (x-- > y++)

        if (x < y)

            printf("Hello, ");

        else

            printf("Hi, ");

    else

        printf("Hey, ");

    printf("x = %d y = %d\n", x, y);

    return 0;
}

Starting Values

x = 10
y = 9

Outer Condition

if (x-- > y++)

Post-decrement means use the current value and then decrement:

x--

Post-increment means use the current value and then increment:

y++

The comparison therefore uses:

10 > 9

which is true.

After the comparison:

x = 9
y = 10

Inner Condition

Now C evaluates:

if (x < y)

which becomes:

9 < 10

This is true, so:

printf("Hello, ");

executes.

Output

Hello, x = 9 y = 10

Dangling else

Without braces, an else associates with the nearest unmatched if.

For clarity, the structure can be written as:

if (condition1)
{
    if (condition2)
    {
        statement1;
    }
    else
    {
        statement2;
    }
}
else
{
    statement3;
}

Using braces is strongly recommended, especially in interview code.

5. Pre-Increment in Nested if

Code

#include <stdio.h>

int main()
{
    int x = -1, y = -2;

    if (++x < ++y)

        if (x < y)

            printf("Hello, ");

        else

            printf("Hi, ");

    else

        printf("Hey, ");

    printf("x = %d y = %d\n", x, y);

    return 0;
}

Starting Values

x = -1
y = -2

Pre-Increment

++x means increment first and then use the new value.

Therefore:

x: -1 -> 0
y: -2 -> -1

The outer condition becomes:

0 < -1

which is false.

Therefore the entire inner if/else is skipped.

The outer else executes:

printf("Hey, ");

Final Values

The increments still occurred:

x = 0
y = -1

Output

Hey, x = 0 y = -1

Why Doesn't It Print Hi?

The inner condition:

if (x < y)

is never reached because the outer condition is false.

Therefore neither Hello nor Hi can execute.

Execution Flow

x = -1
y = -2
   |
   v
++x -> 0
++y -> -1
   |
   v
0 < -1 ?
   |
 FALSE
   |
   v
skip inner if/else
   |
   v
"Hey"
   |
   v
x = 0
y = -1

Pre vs Post Quick Reference

Expression   Meaning

++x        Increment first, then use
x++        Use first, then increment
--x        Decrement first, then use
x--        Use first, then decrement

Memory Aid

PRE

++x
Change -> Use

POST

x++
Use -> Change

Interview Takeaways

These examples demonstrate several common C interview traps:

A semicolon after if creates an empty statement.

else associates with an unmatched if.

printf() returns the number of characters printed.

Nested if statements should normally use braces for clarity.

++x changes the value before it is used.

x++ uses the value before changing it.

--x changes the value before it is used.

x-- uses the value before changing it.

Side effects inside conditions can modify variables even when the
condition evaluates to false.