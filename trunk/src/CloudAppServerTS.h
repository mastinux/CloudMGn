//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __CLOUDAPPSERVER_H
#define __CLOUDAPPSERVER_H

#include <omnetpp.h>
#include <QueueingDefs.h>
#include <cmsgpar.h>
#include <cqueue.h>
#include "CloudAppJob_m.h"


namespace cloudMGn {

//class CloudAppJob;

/**
 * Abstract base class for single-server queues.
 */
class CloudAppServerTS : public cSimpleModule
{
    private:
		//simsignal_t droppedSignal;
		//simsignal_t queueLengthSignal;
		//simsignal_t queueingTimeSignal;
		//simsignal_t busySignal;

		CloudAppJob *jobServiced;
        cMessage *endServiceMsg;
        cMessage *contextSwitchMsg;
        cMessage *timeoutMsg;
        cQueue queue;
        int capacity;
        bool fifo;
        simtime_t maxServiceTime;
        simtime_t timeout;
        CloudAppJob *getFromQueue();
        // status and stats
        bool busy;
        bool congested;
        double congestionMultiplier;
        simtime_t totalBusyTime;
        simtime_t startBusyTime;
        simtime_t totalIdleTime;
        simtime_t startIdleTime;
        simtime_t startCongestionTime;
        simtime_t startNCongestionTime;
        simtime_t totalCongestionTime;
        simtime_t totalNCongestionTime;
        double timeSlice;
        int totalJobs;
        int droppedJobsQueue;
        int droppedJobsTimeout;
        void changeState(int transition);
        void processCloudCongestionUpdateMessage(cMessage *msg);
        void processEndServiceMessage(cMessage *msg);
        void processCloudAppJobMessage(cMessage *msg);
        void processContextSwitchMessage(cMessage *msg);
        void processTimeoutMessage(cMessage *msg);
        void setRemainingTime(cMessage *job, simtime_t time);
        simtime_t getRemainingTime(cMessage *job);
        void deleteRemainingTime(cMessage *job);
        void scheduleNextEvent();
        bool checkTimeoutExpired(CloudAppJob *job, bool autoremove=true);
        void setTimeout(CloudAppJob *job);
        void cancelTimeout(CloudAppJob *job);
        void removeExpiredJobs();

    public:
        CloudAppServerTS();
        virtual ~CloudAppServerTS();
        int length();

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void finish();

        // hook functions to (re)define behaviour
        // virtual void arrival(CloudAppJob *job);
        virtual simtime_t setupService(CloudAppJob *job);
        virtual void endService(CloudAppJob *job);
        virtual void resumeService(CloudAppJob *job);
        virtual void stopService(CloudAppJob *job);
};

}; //namespace

#endif
