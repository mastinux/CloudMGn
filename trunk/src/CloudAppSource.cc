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

#include "CloudAppSource.h"
#include "CloudAppJob_m.h"

namespace cloudMGn {

Define_Module(CloudAppSource);

CloudAppSource::CloudAppSource()
{
    timerMessage = NULL;
}

CloudAppSource::~CloudAppSource()
{
    cancelAndDelete(timerMessage);
}

void CloudAppSource::initialize()
{
    timerMessage = new cMessage("timer");
    maxInterval = par("maxInterval").doubleValue();
    scheduleAt(simTime(), timerMessage);
}

void CloudAppSource::handleMessage(cMessage *msg)
{
    ASSERT(msg==timerMessage);
    simtime_t t, trand;
    // create new message
    CloudAppJob *job = new CloudAppJob(getJobName());
    job->setStartTime(simTime());
    job->setQueuingTime(0.0);

    job->setServiceTime(0.0);
    job->setDelayTime(0.0);

    job->setQueueCount(0);
    job->setDelayCount(0);
    job->setAppId(par("appId"));
    send(job, "out");

    // schedule next message
    trand=par("sendInterval").doubleValue();
    if (maxInterval>0 && trand>maxInterval){
        t=simTime() + maxInterval;
    } else {
        t=simTime() + trand;
    }
    scheduleAt(t, timerMessage);
}

const char *CloudAppSource::getJobName(){
    return "job";
}


}; // namespace
