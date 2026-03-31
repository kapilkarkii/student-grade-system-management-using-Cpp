============================================================
  Student Grade Management System
  Introduction to C++ - Mini Project
  Texas College of Management & IT
  Bachelor of Information Technology (BIT)
  First Year / First Semester
============================================================

PROJECT TITLE  : Student Grade Management System
SUBJECT        : Introduction to C++
LECTURER       : Mr. Ashish Gautam (PhD Scholar)
STUDENT NAME   : Kapil Karki

------------------------------------------------------------
FILES INCLUDED
------------------------------------------------------------
  student_grade_management.cpp  - Main C++ source code
  README.txt                    - compilation guide

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------
  - A C++ compiler (g++ recommended)
  - Terminal / Command Prompt
  - C++11 or later standard

------------------------------------------------------------
HOW TO COMPILE
------------------------------------------------------------

  On Linux / Mac:
  ---------------
  Step 1: Open Terminal
  Step 2: Navigate to the project folder
          cd path/to/LCID_CPP_MiniProject

  Step 3: Compile the program
          g++ -o grade_system student_grade_management.cpp -std=c++11

  Step 4: Run the program
          ./grade_system


  On Windows:
  -----------
  Step 1: Open Command Prompt
  Step 2: Navigate to the project folder
          cd path\to\LCID_CPP_MiniProject

  Step 3: Compile the program (using MinGW g++)
          g++ -o grade_system student_grade_management.cpp -std=c++11

  Step 4: Run the program
          grade_system.exe


  Using Dev-C++ IDE:
  ------------------
  Step 1: Open Dev-C++
  Step 2: File -> Open -> student_grade_management.cpp
  Step 3: Press F11 to Compile and Run


  Using Code::Blocks IDE:
  -----------------------
  Step 1: Open Code::Blocks
  Step 2: Create a new Empty Project
  Step 3: Add student_grade_management.cpp to the project
  Step 4: Press F9 to Build and Run


  Using VS Code:
  --------------
  Step 1: Open VS Code
  Step 2: Open the folder containing the .cpp file
  Step 3: Open Terminal (Ctrl + `)
  Step 4: Run: g++ -o grade_system student_grade_management.cpp -std=c++11
  Step 5: Run: ./grade_system  (Linux/Mac) or grade_system.exe (Windows)

------------------------------------------------------------
HOW TO USE THE PROGRAM
------------------------------------------------------------

  Once running, you will see a menu:

    1) Add Students          - Enter student name, roll, marks
    2) Show All Students     - Display all records in a table
    3) Search by Roll No     - Find a student by roll number
    4) Update Marks          - Change marks for a student
    5) Delete Student Data   - Remove a student record
    6) Exit                  - Close the program