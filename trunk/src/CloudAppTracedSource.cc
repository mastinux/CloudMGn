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

    fd.open(filePath);

    scheduleAt(simTime(), timerMessage);
}

void CloudAppTracedSource::handleMessage(cMessage *msg)
{
    ASSERT(msg==timerMessage);

    int tracedJobId;
    double tracedTime, tracedServiceTime, tracedDelayTime;
    simtime_t t, trand;

    fd >> tracedTime >> tracedJobId >> tracedServiceTime >> tracedDelayTime;

    // create new message
    CloudAppJob *job = new CloudAppJob(getJobName());
    job->setStartTime(simTime());
    job->setQueuingTime(0.0);

    //job->setServiceTime(0.0);
    job->setServiceTime(SimTime(tracedServiceTime));

    //job->setDelayTime(0.0);
    job->setDelayTime(SimTime(tracedDelayTime));
    job->setQueueCount(0);
    job->setDelayCount(0);
    job->setAppId(par("appId"));

    //TODO creare job ID univoco per la simulazione
    // override di cPar che se legge il valore lo aumenta
    //job->setJobId(tracedJobId);

//    EV << "\n sending job " << job->getJobId() << " at: " << job->getStartTime() << endl;
    send(job, "out");

    t=SimTime(tracedTime);
    //EV << "\n sending self message at: " << t << endl;
    scheduleAt(t, timerMessage);
}

void CloudAppTracedSource::finish(){
    fd.close();
}

const char *CloudAppTracedSource::getJobName(){
    return "job";
}

}; // namespace
