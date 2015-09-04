package cloudMGn.src;

//
// Joins several incoming connections. Anything that comes in
// will be sent out immediately on the "out" gate.
//
simple Merge
{
    parameters:
        @display("i=block/join");
    gates:
        input in[];
        output out;
}