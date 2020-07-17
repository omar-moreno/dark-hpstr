/**
 * @file Processor.cxx
 * @brief Base classes for all user event processing components to extend
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#include "Processing/Processor.h" 
#include "Processing/ProcessorFactory.h"

Processor::Processor(const std::string& name, Process& process) :
    process_ (process ), name_ { name } {
}

void Processor::declare(const std::string& classname, ProcessorMaker* maker) {
    ProcessorFactory::instance().registerProcessor(classname, maker);
}
