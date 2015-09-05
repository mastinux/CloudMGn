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
    // TODO Auto-generated constructor stub

}

Tracer::~Tracer() {
    // TODO Auto-generated destructor stub

}

void Tracer::initialize(){
    // apri file sovrascrivendo quello già esistente
    //EV << " opening file " << par("tracesFileName").str();
    fd.open(par("tracesFileName").stringValue());
    //EV << "\n file open";

    cMessage *msg = new cMessage("messaggioDalTracer");
    simtime_t sendingTime = exponential(par("interArrivalMean").doubleValue());

    // invia un messaggio a se stesso
    scheduleAt(sendingTime,msg);
}

void Tracer::handleMessage(cMessage *msg){
    simtime_t currentSimTime = simulation.getSimTime();
    simtime_t sendingTime = exponential(par("interArrivalMean").doubleValue());
    int appId = simulation.getEventNumber();
    simtime_t serviceTime = exponential(par("serviceMean").doubleValue());
    simtime_t delayTime = exponential(par("delayMean").doubleValue());

    EV << " -simulation time: " << currentSimTime;
    EV << "\t -appId: " << appId;
    EV << "\t -service time: " << serviceTime;
    EV << "\t -delay time: " << delayTime << "\n";

    // data recording on file
    //EV << "recording on file\n";
    fd << currentSimTime.dbl() << " " << appId << " " << serviceTime .dbl() << " " << delayTime .dbl() << endl;
    //EV << "recorded\n";

    // simtime parsing
    //EV << "\n performing simulation time parsing\n double value:" << serviceTime.dbl();
    //EV << "\n original value: " << serviceTime << "\n reparsed value: " << SimTime(serviceTime.dbl());
    // invia un messaggio a se stesso
    scheduleAt(simTime() + sendingTime, msg);

    // TODO migliorare la qualità del controllo
    if(simulation.getSimTime() > 3600){
        // chiusura del file
        //EV << "\n closing file";
        fd.close();
        //EV << "\n file closed";
    }
}

} /* namespace cloudMxGn */
