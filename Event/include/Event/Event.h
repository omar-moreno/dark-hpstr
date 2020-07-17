#ifndef __EVENT_H__
#define __EVENT_H__

//----------------//
//   C++ StdLib   //
//----------------//
#include <stdexcept>

//----------//
//   LCIO   //
//----------//
#include <EVENT/LCCollection.h>
#include <EVENT/LCEvent.h>

//----------//
//   ROOT   //
//----------//
#include <TClonesArray.h>
#include <TTree.h>

//-----------//
//   hpstr   //
//-----------//
#include "Event/Collections.h"
#include "Event/EventHeader.h"

class Event { 

    public: 

        /** Constructor */
        Event(); 

        /** Destructor */
        ~Event(); 

        /** 
         *
         */
        void add(const std::string name, TObject* object); 

        /** 
         * Add a collection (TClonesArray) of objects to the event. 
         *
         * @param name Name of the collection
         * @param collection The TClonesArray containing the object. 
         */
        void addCollection(const std::string name, TClonesArray* collection);

        /** 
         * @param name Name of the collection
         *
         * @return Get a collection from the event. 
         */
        TClonesArray* getCollection(const std::string name); 

        /**
         * Checks if a collection already exist. 
         *
         * @param name Collection name
         * 
         * @return True if the collection exist, false otherwise.
         */
        bool exists(const std::string name);

        /**
         * Clear all of the collections in the event 
         */
        void Clear();

        /** @return Get a mutable copy of the EventHeader. */
        EventHeader& getEventHeaderMutable() const { return *event_header_; }

        /** @return The ROOT tree containing the event. */
        TTree* getTree() { return tree_; }

        /** Set the LCIO event. */
        void setLCEvent(EVENT::LCEvent* lc_event) { lc_event_ = lc_event; }; 

        /** @return LCIO event. */
        EVENT::LCEvent* getLCEvent() { return lc_event_; };

        /** Get the LCIO event. */
        EVENT::LCCollection* getLCCollection(std::string name) { 
            return static_cast<EVENT::LCCollection*>(lc_event_->getCollection(name)); 
        }; 

        /**
         * Set the current entry. 
         *
         * @param The current entry. 
         */
        void setEntry(const int entry) { entry_ = entry; }; 

    private: 

        /** The event headeer object (as pointer). */
        EventHeader* event_header_{nullptr};

        /** The ROOT tree containing the event. */
        TTree* tree_{nullptr}; 
        
        /** Object used to load all of current LCIO event information. */
        EVENT::LCEvent* lc_event_{nullptr};

        /** Container with all TClonesArray collections. */
        std::map<std::string, TObject*> objects_; 

        /** Container will all branches. */
        std::map<std::string, TBranch*> branches_; 

        /** The current entry. */
        int entry_{0};  

}; // Event

#endif // __EVENT_H__


