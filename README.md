# Student Management System

A simple C++ program that lets you manage student records from the terminal. Data is saved to a binary file so nothing gets lost when you close the program.

## What it can do

- Add a student
- View all students
- Search by ID
- Update a student's info
- Delete a student

## How to build and run

Make sure you have a C++ compiler installed, then:

```bash
g++ main.cpp -o student
./student
```

On Windows just run `student.exe` directly.

## How to use it

When you run the program you'll see a menu like this:

```
===== Student Management System =====
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

Just type a number and hit enter. Student records are stored in a file called `students.dat` which gets created automatically the first time you add someone.
