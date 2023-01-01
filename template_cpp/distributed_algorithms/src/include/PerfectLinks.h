#pragma once // do not include a headfile multiple times

#include "UDPHeader.h"
#include "UDPSegment.h"
#include "Process.h"

class PerfectLinks {
    private:
        Process pi_;//sender
        Process pj_;//delivered to
        UDPSegment message_;
    public:
        PerfectLinks(Process pi=Process(), Process pj=Process(), UDPSegment message=UDPSegment());
        ~PerfectLinks();
};