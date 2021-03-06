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

    std::string fileName_server_0((par("tracesFileName").stringValue()));
    std::string fileDirectory("../simulations/");
    std::string filePath_server_0 = fileDirectory + fileName_server_0;

    fd_server_0.open(filePath_server_0);

    std::fstream next_fd;
    next_fd.open("file", std::fstream::out | std::fstream::trunc);
    next_fd << 1 << endl;
    next_fd.close();

    scheduleAt(simTime(), timerMessage);
}

void CloudAppTracedSource::handleMessage(cMessage *msg)
{
    ASSERT(msg==timerMessage);

    double tracedTime, tracedServiceTime, tracedDelayTime;
    simtime_t t, trand;

    fd_server_0 >> tracedTime >> tracedServiceTime >> tracedDelayTime;

    // create new message
    CloudAppJob *job = new CloudAppJob(getJobName());

    //job->setStartTime(simTime());
    job->setStartTime(SimTime(tracedTime));
    job->setQueuingTime(0.0);

    job->setServiceTime(0.0);
    job->setDelayTime(0.0);

    //TODO my changes
    job->setTracedFlag(true);
    job->setBudgetedServiceTime(SimTime(tracedServiceTime));
    job->setBudgetedDelayTime(SimTime(tracedDelayTime));

    job->setQueueCount(0);
    job->setDelayCount(0);
    job->setAppId(par("appId"));

    // read from file, and overwrite next job id
    int nextJobId;
    std::fstream next_fd;
    std::string fileName((par("nextJobIdFileName").stringValue()));
    std::string fileDirectory("../simulations/");
    std::string filePath = fileDirectory + fileName;

    next_fd.open("file", std::fstream::in);
    next_fd >> nextJobId;
    next_fd.close();

    next_fd.open("file", std::fstream::out | std::fstream::trunc);
    next_fd << (nextJobId + 1) << endl;
    next_fd.close();

    job->setJobId(nextJobId);
    EV << "\n | starting job " << job->getJobId() << " at " << job->getStartTime() << endl;
    EV << " | BST " << job->getBudgetedServiceTime() << " and BDT " << job->getBudgetedDelayTime() << "\n" << endl;

    send(job, "out");

    t=SimTime(tracedTime);
    //EV << "\n sending self message at: " << t << endl;
    scheduleAt(t, timerMessage);
}

void CloudAppTracedSource::finish(){
    fd_server_0.close();
}

const char *CloudAppTracedSource::getJobName(){
    return "job";
}

}; // namespace
