//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "CloudAppDispatcherRR.h"

namespace cloudMGn {

Define_Module(CloudAppDispatcherRR);

void CloudAppDispatcherRR::initialize()
{
    setPerformFinalGC(true); // FIXME: WTF?
    currentOut=0;
    nOut=gateSize("out");
    ASSERT(nOut>0);
}

void CloudAppDispatcherRR::handleMessage(cMessage *msg)
{
    send(msg, "out", currentOut);
    currentOut=(currentOut+1)%nOut;
}

}; // namespace
