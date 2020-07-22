/**
 * @file EventFile.cxx
 * @brief Class for managing IO files.
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#include "Processing/EventFile.h"

#include "IOIMPL/LCFactory.h"


EventFile::EventFile(const std::string input_file, const std::string out_file) { 
    
    // Instantiate the LCIO reader
    lc_reader_ = IOIMPL::LCFactory::getInstance()->createLCReader();
     
    // Open the input LCIO file. If the input file can't be opened, throw an 
    // exception. 
    lc_reader_->open(input_file); 
    
    // Open the output ROOT file
    ofile_ = new TFile(out_file.c_str(), "recreate");
}


EventFile::~EventFile() {}

bool EventFile::nextEvent() { 

    // Close out the previous event before moving on.
    if (entry_ > 0) { 
        event_->getTree()->Fill(); 
    }
   
    // Read the next event.  If it doesn't exist, stop processing events.
    if ((lc_event_ = lc_reader_->readNextEvent())  == 0) return false;
    
    event_->setLCEvent(lc_event_); 
    event_->setEntry(entry_); 

    ++entry_; 
    return true; 
}

void EventFile::setupEvent(Event* event) { 
    event_ = event;
    entry_ = 0;  
}

void EventFile::close() { 
    
    // Close the LCIO file that was being processed
    lc_reader_->close();

    // Write the ROOT tree to disk
    event_->getTree()->Write();  
    
    // Close the ROOT file
    ofile_->Close(); 
}
