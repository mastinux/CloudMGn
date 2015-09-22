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
    fd_server_0.open(par("tracesFileName").stringValue());

    cMessage *msg = new cMessage("messaggioDalTracer");
    simtime_t sendingTime = par("interArrival");

    scheduleAt(sendingTime,msg);
}

void Tracer::handleMessage(cMessage *msg){
    simtime_t currentSimTime = simulation.getSimTime();

    simtime_t additionalTime = par("interArrival");
    simtime_t serviceTime = par("service");
    simtime_t delayTime = par("delay");

    simtime_t tracedTime = currentSimTime + additionalTime;

    EV << " -traced time: " << tracedTime;
    EV << "\t -service time: " << serviceTime;
    EV << "\t -delay time: " << delayTime << "\n";

    fd_server_0 << tracedTime << " " << serviceTime << " " << delayTime << endl;

    scheduleAt(tracedTime, msg);
}

void Tracer::finish(){
    fd_server_0.close();
}

} /* namespace cloudMxGn */
