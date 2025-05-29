# Assignment-3-EECS22L, Natalie Hoang
# Objective: When given an input SRS file, the program will parse through the file, print a dependency graph and corresponding report.

# Copilot was used to auto-complete module function and struct definitions!!

# ParseFile.c -.h  Module reads input markdown SRS file and parses through text. Creates array of Requirement structs containing requirement ID, requirement's ID, description, parents, children, and line numbers.

# DepGraph.c -.h  Module that creates and prints dependency graph from inputted SRS. Uses struct 'Requirement' array and defined in ParseFile module. Creates array of 'DepList' structs that contains each requirement's ID, parent/child IDs, and their line numbers. Provides functions to print the dependency graph to the terminal.

# Report .c -.h  Module generates the report of dependency graph. Uses 'DepList' struct and array defined in DepGraph module, lists each requirement and its dependencies with correct SRS line numbers. Writes a report file called rdgg-report-<STUDENT_ID>.md.

#  Main.c       Module that gathers input SRS markdown file and handles user input. Prompts the user for the SRS file path, calls the parsing, graph-building, and report-generating modules, and displays the dependency graph in the terminal.

# How to make/run: 
# Program ran and tested with Windows powershell!!!
# 1. print 'make' to terminal
# 2. type '.\rdgg-01234567.exe' into terminal.
# 3. "Input the SRS file (or 'x' to exit): " should appear to terminal
# 4. type input filepath (EX: "C:\Users\name\Downloads\A04_Example_SRS.md") or 'x' to exit

# How to clean:
# type 'make clean'


