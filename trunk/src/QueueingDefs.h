/*
 * QueueingDefs.h
 *
 *  Created on: Jul 27, 2015
 *      Author: mastinux
 */

#ifndef QUEUEINGDEFS_H_
#define QUEUEINGDEFS_H_


#include <omnetpp.h>

#if OMNETPP_VERSION < 0x0400
#  error At least OMNeT++/OMNEST version 4.0 required
#endif

#if defined(QUEUEING_EXPORT)
#  define QUEUEING_API OPP_DLLEXPORT
#elif defined(QUEUEING_IMPORT)
#  define QUEUEING_API OPP_DLLIMPORT
#else
#  define QUEUEING_API
#endif


#endif /* QUEUEINGDEFS_H_ */
