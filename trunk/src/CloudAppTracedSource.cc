//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "CloudAppTracedSource.h"
#include "CloudAppJob_m.h"
#include <string>
#include <iostream>
#include <simtime.h>

namespace cloudMGn {

Define_Module(CloudAppTracedSource);

CloudAppTracedSource::CloudAppTracedSource()
{
    timerMessage = NULL;
}

CloudAppTracedSource::~CloudAppTracedSource()
{
    cancelAndDelete(timerMessage);
}

void CloudAppTracedSource::initialize()
{
    timerMessage = new cMessage("timer");
    maxInterval = par("maxInterval").doubleValue();

    std::string fileName((par("tracesFileName").stringValue()));
    std::string fileDirectory("../simulations/");
    std::string filePath = fileDirectory + fileName;

    //EV << " \n opening file "<< fd << " for reading: " << filePath << "\n\n";
    fd.open(filePath);
/*
    if (fd.is_open())
        EV << "\n file is open";
    else
        EV << "\n file is not open";
*/
    scheduleAt(simTime(), timerMessage);
}

void CloudAppTracedSource::handleMessage(cMessage *msg)
{
    ASSERT(msg==timerMessage);

    int tracedJobId;
    double tracedTime, tracedServiceTime, tracedDelayTime;
    simtime_t t, trand;

    //reading data from file
    fd >> tracedTime >> tracedJobId >> tracedServiceTime >> tracedDelayTime;
/*
    EV << "\n value red:\n - traced time:" << tracedTime;
    EV << "\n - job id:" << tracedJobId;
    EV << "\n - service time:" << tracedServiceTime;
    EV << "\n - delay time:" << tracedDelayTime << "\n";
*/

    // create new message
    CloudAppJob *job = new CloudAppJob(getJobName());

    job->setStartTime(simTime());
    //job->setStartTime(SimTime(tracedTime));
    job->setQueuingTime(0.0);

    //job->setServiceTime(0.0);
    job->setServiceTime(SimTime(tracedServiceTime));
    //EV << "\n service time for current job:\t" << job->getServiceTime();

    //job->setDelayTime(0.0);
    job->setDelayTime(SimTime(tracedDelayTime));
    //EV << "\n delay time for current job:\t" << job->getDelayTime();
    job->setQueueCount(0);
    job->setDelayCount(0);
    // non fa riferimento a [CloudAppJob] ma all'oggetto che lo usa [appProc]
    job->setAppId(par("appId"));

    //job->setJobId(tracedJobId);
    job->setJobId(tracedJobId);
    //EV << "\n\n current job id:\t" << job->getJobId();

    EV << " sending job [ jobId=" << job->getJobId() << ", startTime=" << job->getStartTime() << " ]\n" << endl;
    send(job, "out");

    // schedule next message
    //trand=par("sendInterval").doubleValue();
    trand = SimTime(tracedTime);
    //trand = tracedTime;
    if (maxInterval>0
            && trand>maxInterval
            ){
        t=simTime() + maxInterval;
    } else {
        t=simTime() + trand;
    }
    EV << " sending self message" << endl;
    EV << " maxInterval: \t" << maxInterval << endl;
    EV << " sendInterval: " << trand << endl;
    EV << " tracedTime: \t" << tracedTime << endl;
    EV << " next self message scheduled at: \t" << t << "\n" << endl;
    scheduleAt(t, timerMessage);

    // TODO migliorare la qualità del controllo
    if(simulation.getSimTime() > 3600){
        // chiusura del file
        EV << "\n closing file";
//        fd.close();
        EV << "\n file closed";
    }

}

const char *CloudAppTracedSource::getJobName(){
    return "job";
}

}; // namespace
