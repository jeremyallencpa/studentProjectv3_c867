#pragma once
#include <string>

/*Requirement C. define an enumerated data type DegreeProgram for the degree programs containing the data
type values SECURITY, NETWORK, SOFTWARE.*/

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };
/*Create a parallel string of degree programs to match the enumerated data type.
These will be what displays rather than the digit output from the enumerated data type.*/

static const std::string degreeProgramStringFormat[] = { "SECURITY", "NETWORK", "SOFTWARE" };
