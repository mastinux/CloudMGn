package cloudMGn.simulations;

import cloudMGn.src.Tracer;

network TracesGenerationSystem
{
    //foo parameters
//    parameters:
//        double interArrivalMean = default(0.0);
    
    submodules:
        tracer: Tracer;
        
        //mainSender: Tracer;
        //mirrorSender: Tracer;
        
        // foo submodules
        //a: Tracer {
        //    @display("p=126,50");
        //}
        //b: Tracer {
        //    @display("p=214,50");
        //}
    //foo connections
//    connections:
//        tracer.out --> tracer.in;
        
        //mainSender.out --> mirrorSender.in;
        //mirrorSender.out --> mainSender.in;
        
    //    a.in <-- {  delay = 100ms; } <-- b.out;
}
