#include "PerfectLinks.h"

PerfectLinks::PerfectLinks(Process pi, Process pj, UDPSegment message): pi_(pi),pj_(pj),\
    message_(message) {}
PerfectLinks::~PerfectLinks(){}
