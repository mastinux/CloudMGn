package cloudMGn.src;

//
// Forks a job to one child per output. The children can be joined together
// into the original job with the Join module.
//
simple CloudAppDispatcherRR
{
    parameters:
        @display("i=block/fork");
    gates:
        input in;
        output out[];
}
