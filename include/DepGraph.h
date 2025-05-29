//DepGraph.h
#ifndef DEPGRAPH_H
#define DEPGRAPH_H
#include "ParseFile.h"  //Can use Requirement struct

/*
 * Data Structure Choice: Array of Structures (DepList)
 * ----------------------------------------------------
 * Used an array of DepList structs to represent the dependency graph.
 * Each DepList stores the requirement ID and arrays of parent and child IDs.
 * This allows efficient access by index and is simple to implement for a moderate number of requirements.
 * The structure is flexible and easy to traverse for printing or further processing.
 */
#define MAX_DEP 10

typedef struct {
    char id[50];
    char parents[MAX_DEP][50];
    int num_parents;
    char children[MAX_DEP][50];
    int num_children;
} DepList;

// Creates a dependency graph from array of parsed requirements from SRS
void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph);

// Prints the dependency graph
void printDepGraph(const DepList *graph, int reqsLEN);

#endif
