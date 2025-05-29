//DepGraph.h
#ifndef DEPGRAPH_H
#define DEPGRAPH_H
#include "ParseFile.h"  //Can use Requirement struct

/*
 * Data Structure: Array of Structures (DepList)
 * - Used an array of DepList structs to represent the dependency graph.
 * - Each DepList stores the requirement ID and arrays of parent and child IDs.
 * - This allows access by index and most simple way to implement for input requirements.
 * - Easy to traverse for printing or further processing.
 */
#define MAX_DEP 10

typedef struct {
    char id[50];
    int line_number; // Line number of the ID in the SRS file
    char parents[MAX_DEP][50];
    int parent_lines[MAX_DEP]; // Line numbers for each parent
    int num_parents;
    char children[MAX_DEP][50];
    int child_lines[MAX_DEP]; // Line numbers for each child
    int num_children;
} DepList;

//Creates a dependency graph from array of parsed requirements from SRS
void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph);

//Prints the dependency graph
void printDepGraph(const DepList *graph, int reqsLEN);

#endif
