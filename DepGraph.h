//DepGraph.h
#ifndef DEPGRAPH_H
#define DEPGRAPH_H
#include "ParseFile.h"  // So it can use the Requirement struct

// Define the maximum number of requirements
#define MAX_REQS 100

// Adjacency list representation of the dependency graph
typedef struct {
    char id[50];
    int depends_on[MAX_REQS]; // Indices of requirements this one depends on
    int num_dependencies;
} RequirementNode;

/**
 * Builds a dependency graph from the list of parsed requirements.
 *
 * @param reqs Array of parsed requirements.
 * @param num_reqs Number of requirements in the array.
 * @param graph Output array of RequirementNode structures representing the graph.
 */
void build_dependency_graph(const Requirement *reqs, int num_reqs, RequirementNode *graph);

/**
 * Prints the dependency graph.
 *
 * @param graph Array of RequirementNode structures.
 * @param num_reqs Number of nodes in the graph.
 */
void print_dependency_graph(const RequirementNode *graph, int num_reqs);

#endif
