# Assignment-3-EECS22L, Natalie Hoang
# Objective: When given an input SRS file, the program will parse through the file, print a dependency graph and corresponding text report.

# Copilot was used to auto-complete module function and struct definitions!!

# ParseFile.c -.h  Module reads input markdown SRS file and parses throught text. Creates array of Requirement.

# DepGraph.c -.h  Module that creates and prints dependency graph from inputted SRS. Uses Requirement array and structure defined in ParseFile module. Creates ReqNode struture and array that contains each requirement's ID and dependencies. 

# Report .c -.h  Module generates the report. Uses ReqNode structure and array define in DepGraph module and writes report on each requirment.

#  Main.c       Module that gathers input SRS markdown file and handles user input. Calls each module to parse, print dependency graph, and generate report.


