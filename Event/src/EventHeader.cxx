/**
 * @file EventHeader.cxx
 * @brief Class used to encapsulate event information.
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#include "Event/EventHeader.h"

EventHeader::EventHeader() { 
    }

EventHeader::~EventHeader() {
}

void EventHeader::Print() { 
    std::cout << "[ EventHeader ]:\n" 
              << "\tEvent number: " << event_number_ << "\n"
              << "\tRun number: " << run_number_ << "\n"
              << "\tEvent time: " << event_time_ << "\n" 
              << "\tRF time: 1) " << rf_times_[0] << " 2) " << rf_times_[1] 
              << std::endl;
}
