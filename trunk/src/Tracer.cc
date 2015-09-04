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

namespace cloudMGn {

Define_Module(Tracer);

Tracer::Tracer() {
    // TODO Auto-generated constructor stub

}

Tracer::~Tracer() {
    // TODO Auto-generated destructor stub

}

void Tracer::initialize(){
    if (strcmp("mainSender", getName()) == 0){
        cMessage *msg = new cMessage("messaggioDalMainSender");
        send(msg,"out");
    }
}

void Tracer::handleMessage(cMessage *msg){
    send(msg,"out");
}

} /* namespace cloudMGn */
