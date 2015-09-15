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

#ifndef TRACER_H_
#define TRACER_H_

#include <omnetpp.h>
#include <string.h>
#include <fstream>

namespace cloudMGn {

class Tracer : public cSimpleModule{
private:
    std::ofstream fd_server_0;
    std::ofstream fd_server_1;
//    cMessage *event; // pointer to the event object which we'll use for timing
//    cMessage *msg; // variable to remember the message until we send it back

public:
    Tracer();
    virtual ~Tracer();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

} /* namespace cloudMGn */

#endif /* TRACER_H_ */
