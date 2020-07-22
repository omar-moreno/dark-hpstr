/**
 * @file Processing/EventFile.h
 * @brief Class for managing io files.
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#ifndef __EVENT_FILE_H__
#define __EVENT_FILE_H__

//----------//
//   ROOT   //
//----------//
#include <TFile.h>
#include <TTree.h>

//----------//
//   LCIO   //
//----------//
#include "EVENT/LCEvent.h"

//-----------//
//   hpstr   //
//-----------//
#include "Event/Event.h"

#include "IO/LCReader.h"

class EventFile { 

    public: 

        /** Constructor */
        EventFile(const std::string ifilename, const std::string ofilename);

        /** Destructor */
        ~EventFile();

        /**
         * Load the next event in the file. 
         *
         * @return true if an event was loaded successfully, false otherwise 
         */
        bool nextEvent(); 

        /**
         * Setup the event object that will be used by this file.
         *
         * @param event The Event container.
         */
        void setupEvent(Event* event); 

        /** 
         * Close the file, writing the tree to disk if creating an output file.
         */
        void close();

    private: 

        /** The ROOT file to which event data will be written to. */
        TFile* ofile_{nullptr}; 

        /** Object used to build the HPS event model. */
        Event* event_{nullptr};

        /** Object used to load all of current LCIO event information. */
        EVENT::LCEvent* lc_event_{nullptr}; 
        
        /** LCIO reader */
        IO::LCReader* lc_reader_{nullptr}; 

        int entry_{0};  

}; // EventFile

#endif // __EVENT_FILE_H__
