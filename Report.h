//Report.h
#ifndef REPORT_H
#define REPORT_H
#include "DepGraph.h"

/**
 * Generates a human-readable report of the requirement dependency graph.
 *
 * @param graph Array of RequirementNode structures.
 * @param num_reqs Number of requirements in the graph.
 * @param filename Name of the output report file.
 * @return 0 if successful, -1 on failure.
 */
int generate_report(const RequirementNode *graph, int num_reqs, const char *filename);

#endif










