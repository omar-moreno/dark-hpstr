/**
 * @file Collection.h
 * @brief List of collection names.
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#ifndef _COLLECTIONS_H_
#define _COLLECTIONS_H_

namespace Collections { 

    /** Name of the tracks collection. */
    constexpr const char* GBL_TRACKS{"GBLTracks"};

    /** Name of the Raw tracker hits collection. */
    constexpr const char* RAW_SVT_HITS{"SVTRawTrackerHits"};

    /** Name of the tracker hits collection. */
    constexpr const char* TRACKER_HITS{"RotatedHelicalTrackHits"};

    /** The name of the collection containing GBL kink data GenericObjects */
    constexpr const char* KINK_DATA{"GBLKinkData"};

    /** Name of the collection containing Track to GBLKinkData LCRelations. */
    constexpr const char* KINK_DATA_REL{"GBLKinkDataRelations"};

    /** Name of the collection of TrackData GenericObjects */ 
    constexpr const char* TRACK_DATA{"TrackData"}; 

    /** Name of the collection containing Track to TrackData LCRelations */
    constexpr const char* TRACK_DATA_REL{"TrackDataRelations"};

    /** Name of the collection containing Final State Particles. */
    constexpr const char* FINAL_STATE_PARTICLES{"FinalStateParticles"}; 

    /** Name of time corrected ECal hits collection. */
    constexpr const char* ECAL_TIME_CORR_HITS{"TimeCorrEcalHits"}; 

    /** Name of ECal hits collection. */
    constexpr const char* ECAL_HITS{"EcalCalHits"}; 

    /** Name of ECal clusters collection. */
    constexpr const char* ECAL_CLUSTERS{"EcalClustersCorr"};

    /** Name of collection containing "other electrons". */
    constexpr const char* OTHER_ELECTRONS{"OtherElectrons"};

    /** Name of the collection of event headers. */
    constexpr const char* EVENT_HEADERS{"EventHeader"}; 
    
    /** Name of trigger bank collection. */
    constexpr const char* TRIGGER_BANK{"TriggerBank"}; 

    /** Name of RF hits collection. */
    constexpr const char* RF_HITS{"RFHits"};
}

#endif // _COLLECTION_H_
