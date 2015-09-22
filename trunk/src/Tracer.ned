package cloudMGn.src;

simple Tracer
{
    parameters:
        volatile double interArrival @unit(s);
        volatile double service @unit(s);
        volatile double delay @unit(s);
        string tracesFileName;
//        string tracesFileName_server1;        
//    gates:
//        input in;
//        output out; 
}
