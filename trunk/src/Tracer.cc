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


#include "Tracer.h"
#include <omnetpp.h>
#include <string.h>
#include <simtime.h>

namespace cloudMGn {

Define_Module(Tracer);

Tracer::Tracer() {

}

Tracer::~Tracer() {

}

void Tracer::initialize(){
    fd_server_0.open(par("tracesFileName_server0").stringValue());
    fd_server_1.open(par("tracesFileName_server1").stringValue());

    cMessage *msg = new cMessage("messaggioDalTracer");
    simtime_t sendingTime = par("interArrival");

    scheduleAt(sendingTime,msg);
}

void Tracer::handleMessage(cMessage *msg){
    //double sendInterval = par("interArrival");
    double sendInterval = par("interArrival").doubleValue();
    double service = par("service").doubleValue();
    double delay = par("delay").doubleValue();
    simtime_t currentSimTime = simulation.getSimTime();

    //simtime_t additionalTime = sendInterval;
    simtime_t additionalTime = exponential(sendInterval);
    simtime_t tracedTime = currentSimTime + additionalTime;
    //dynamic case
    simtime_t serviceTime = exponential(service);
    simtime_t delayTime = exponential(delay);
    //static case
    //simtime_t serviceTime = par("service");
    //simtime_t delayTime = par("delay");

    //simtime_t additionalTime_1 = sendInterval;
    simtime_t additionalTime_1 = exponential(sendInterval);
    simtime_t tracedTime_1 = currentSimTime + additionalTime_1;
    //dynamic case
    simtime_t serviceTime_1 = exponential(service);
    simtime_t delayTime_1 = exponential(delay);
    //static case
    //simtime_t serviceTime_1 = par("service");
    //simtime_t delayTime_1 = par("delay");

    EV << " -traced time: " << tracedTime;
    EV << "\t -service time: " << serviceTime;
    EV << "\t -delay time: " << delayTime << "\n";

    EV << " -traced time: " << tracedTime_1;
    EV << "\t -service time: " << serviceTime_1;
    EV << "\t -delay time: " << delayTime_1 << "\n";

    fd_server_0 << tracedTime << " " << serviceTime << " " << delayTime << endl;
    fd_server_1 << tracedTime_1 << " " << serviceTime_1 << " " << delayTime_1 << endl;

    scheduleAt((tracedTime > tracedTime_1)? tracedTime : tracedTime_1, msg);
}

void Tracer::finish(){
    fd_server_0.close();
    fd_server_1.close();
}

} /* namespace cloudMxGn */
