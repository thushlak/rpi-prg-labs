# Python 6-Week Course — Week 1, Day 1

## Python Foundations

### Objective

Day 1 introduces the core Python syntax needed for the rest of the 6-week course.

The focus is on:

* Running Python programs
* Variables
* Basic data types
* Arithmetic operators
* Strings and f-strings
* User input
* Type conversion
* Assignment operators
* Basic Linux/embedded-oriented exercises

By the end of this lab, I should be able to write and execute a simple Python program without using a template.

---

## 1. Environment

Platform:

* Linux / Raspberry Pi
* Python 3
* Command line / terminal

Check the installed Python version:

```bash
python3 --version
```

Create the Day 1 working directory:

```bash
mkdir -p ~/python-6weeks/week01/day01
cd ~/python-6weeks/week01/day01
```

---

## 2. First Python Program

Create:

```bash
nano first.py
```

Code:

```python
print("Hello, Embedded Linux!")
print("Python Week 1 - Day 1")
```

Run:

```bash
python3 first.py
```

### Python Execution Model

Unlike a normal C build, I do not manually compile and link this program.

Simplified Python execution:

```text
first.py
   |
   v
Python Interpreter
   |
   v
Bytecode
   |
   v
Python Virtual Machine
   |
   v
Execution
```

For comparison, a typical C build is:

```text
source.c
   |
   v
Preprocessor
   |
   v
Compiler
   |
   v
Assembler
   |
   v
Linker
   |
   v
Executable
```

---

## 3. Variables and Data Types

Create:

```bash
nano variables.py
```

Code:

```python
name = "Raspberry Pi"
cores = 4
temperature = 48.5
online = True

print(name)
print(cores)
print(temperature)
print(online)

print(type(name))
print(type(cores))
print(type(temperature))
print(type(online))
```

Important basic Python types:

| Type    | Example          | Purpose               |
| ------- | ---------------- | --------------------- |
| `int`   | `4`              | Integer               |
| `float` | `48.5`           | Floating-point number |
| `str`   | `"Raspberry Pi"` | Text/string           |
| `bool`  | `True`           | Boolean value         |

Python is dynamically typed.

For example:

```python
cores = 4
temperature = 48.5
```

Compared with C:

```c
int cores = 4;
float temperature = 48.5;
```

Python does not require the variable type to be declared explicitly.

---

## 4. Arithmetic Operators

Create:

```bash
nano arithmetic.py
```

Code:

```python
a = 10
b = 3

print(a + b)
print(a - b)
print(a * b)
print(a / b)
print(a // b)
print(a % b)
print(a ** b)
```

### Operators

| Operator | Meaning          |
| -------- | ---------------- |
| `+`      | Addition         |
| `-`      | Subtraction      |
| `*`      | Multiplication   |
| `/`      | Division         |
| `//`     | Floor division   |
| `%`      | Modulo/remainder |
| `**`     | Power            |

Example:

```python
10 % 3
```

Result:

```text
1
```

Modulo is particularly useful for determining whether a number is even or odd.

```python
number = 10

print(number % 2)
```

If:

```python
number % 2 == 0
```

then the number is even.

---

## 5. Strings and f-Strings

Python f-strings provide a convenient way to insert values into strings.

```python
name = "Raspberry Pi"
cores = 4

print(f"System: {name}")
print(f"CPU cores: {cores}")
```

Compare this with C:

```c
printf("CPU cores: %d\n", cores);
```

Python:

```python
print(f"CPU cores: {cores}")
```

Floating-point formatting:

```python
temperature = 48.56789

print(f"Temperature: {temperature}")
print(f"Temperature: {temperature:.2f} C")
```

Output:

```text
Temperature: 48.56789
Temperature: 48.57 C
```

---

## 6. User Input

Create:

```bash
nano input.py
```

Code:

```python
name = input("Enter your name: ")

print(f"Hello {name}")
```

`input()` always returns a string.

For example:

```python
number = input("Enter a number: ")

print(number)
print(type(number))
```

Entering:

```text
25
```

still produces:

```text
<class 'str'>
```

To obtain an integer:

```python
number = int(input("Enter a number: "))
```

For floating-point input:

```python
temperature = float(input("Enter temperature: "))
```

### Important Pattern

```python
n = int(input("Enter number: "))
```

This means:

```text
Keyboard
   |
   v
input()
   |
   v
String
   |
   v
int()
   |
   v
Integer
   |
   v
n
```

---

## 7. Simple System Information Program

Create:

```bash
nano server.py
```

Code:

```python
hostname = input("Hostname: ")
cpu_count = int(input("CPU count: "))
memory_gb = float(input("Memory GB: "))

print()
print("System Information")
print("------------------")

print(f"Hostname : {hostname}")
print(f"CPUs     : {cpu_count}")
print(f"Memory   : {memory_gb} GB")
```

Example:

```text
Hostname: raspberrypi
CPU count: 4
Memory GB: 4

System Information
------------------
Hostname : raspberrypi
CPUs     : 4
Memory   : 4.0 GB
```

---

## 8. Assignment Operators

Normal assignment:

```python
n = 10
```

Increment by one:

```python
n = n + 1
```

The shorter form is:

```python
n += 1
```

Other examples:

```python
n -= 1
n *= 2
n /= 2
```

### Important Difference from C/C++

Python does not support:

```text
n++
```

Instead use:

```python
n += 1
```

---

# Exercises

## Exercise 1 — Arithmetic

Create:

```text
exercise1.py
```

Start with:

```python
a = 20
b = 6
```

Calculate and display:

* Addition
* Subtraction
* Multiplication
* Division
* Remainder

Example output:

```text
20 + 6 = 26
20 - 6 = 14
20 * 6 = 120
```

---

## Exercise 2 — User Information

Ask the user for:

* Name
* Age

Display:

```text
Hello <name>, you are <age> years old.
```

This exercise practises:

```python
input()
int()
print()
f-strings
```

---

## Exercise 3 — Linux System Information

Ask the user for:

* Hostname
* CPU count
* RAM in GB

Calculate:

```text
RAM per CPU
```

Example:

```text
Hostname: raspberrypi
CPU count: 4
RAM: 8
```

Expected output:

```text
System: raspberrypi
CPUs: 4
RAM: 8 GB
RAM per CPU: 2.0 GB
```

---

# Day 1 Mini Challenge

Create:

```text
challenge.py
```

Ask the user to enter two integers:

```text
a
b
```

Calculate:

* Sum
* Difference
* Product
* Remainder

Example:

```text
Enter a: 20
Enter b: 6

Results
-------
Sum        : 26
Difference : 14
Product    : 120
Remainder  : 2
```

The goal is to complete this challenge without copying the earlier examples.

---

# Day 1 Syntax Reference

```python
name = "Pi"
n = 10
temperature = 42.5
running = True

n += 2

value = int(input("Enter value: "))

remainder = value % 2

print(f"Value = {value}")
```

| Syntax    | Meaning                   |
| --------- | ------------------------- |
| `=`       | Assignment                |
| `+`       | Addition                  |
| `-`       | Subtraction               |
| `*`       | Multiplication            |
| `/`       | Division                  |
| `//`      | Floor division            |
| `%`       | Remainder                 |
| `**`      | Power                     |
| `+=`      | Add and assign            |
| `int()`   | Convert to integer        |
| `float()` | Convert to floating point |
| `str()`   | Convert to string         |
| `input()` | Read keyboard input       |
| `print()` | Display output            |
| `type()`  | Inspect object type       |

---

# Files Created

The completed Day 1 directory should look approximately like this:

```text
day01/
├── README.md
├── first.py
├── variables.py
├── arithmetic.py
├── input.py
├── server.py
├── exercise1.py
├── exercise2.py
├── exercise3.py
└── challenge.py
```

---

# Day 1 Completion Checklist

* [ ] Confirm Python 3 installation
* [ ] Run `first.py`
* [ ] Understand Python variables
* [ ] Understand `int`, `float`, `str`, and `bool`
* [ ] Use `type()`
* [ ] Practise arithmetic operators
* [ ] Understand `%`
* [ ] Use f-strings
* [ ] Use `input()`
* [ ] Convert input using `int()` and `float()`
* [ ] Understand `+=`
* [ ] Complete Exercise 1
* [ ] Complete Exercise 2
* [ ] Complete Exercise 3
* [ ] Complete the Day 1 Mini Challenge without copying

---

# Interview Takeaways

At the end of Day 1, I should be able to explain:

**What is Python?**

Python is a high-level, interpreted programming language with dynamic typing and automatic memory management.

**What does `input()` return?**

`input()` returns a string.

**How do I convert keyboard input to an integer?**

```python
n = int(input("Enter number: "))
```

**What does `%` do?**

It returns the remainder from a division operation.

```python
10 % 3
```

returns:

```text
1
```

**How can modulo be used to identify an even number?**

```python
n % 2 == 0
```

**Does Python support `n++`?**

No. Use:

```python
n += 1
```

**How do I print a variable inside a string?**

Using an f-string:

```python
hostname = "raspberrypi"

print(f"Hostname: {hostname}")
```

---

## Next: Week 1 — Day 2

Day 2 introduces decision-making and Boolean logic:

```python
if
elif
else

==
!=
>
<
>=
<=

and
or
not
```

These will then be combined with today's variables, user input and arithmetic to begin solving interview-style programming problems.
