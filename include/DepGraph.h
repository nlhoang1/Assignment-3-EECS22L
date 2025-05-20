//DepGraph.h
#ifndef DEPGRAPH_H
#define DEPGRAPH_H
#include "ParseFile.h"  //Can use Requirement struct

//Struct for each requirement or "node" in requirement array. Create variables for dependencies and IDs of eahc requirement 
typedef struct {
    char id[50];
    int dependencies;
} ReqNode;


 //Creates a dependency graph from array of parsed requirements from SRS
 //reqs = Array of parsed requirements
 //reqsLEN = Number of requirements in the array
 //graph = Output graph array (with ReqNode structs for each requirement w their dependencies and IDs)
void createDepGraph(const Requirement *reqs, int reqsLEN, ReqNode *graph);

//Prints the dependency graph
//graph = Output graph array (with ReqNode structs for each requirement w their dependencies and IDs)
//reqsLEN = Number of requirements in the array
void printDepGraph(const ReqNode *graph, int reqsLEN);

#endif
