set terminal postscript eps solid color "Helvetica" 22
set key top left
set xlabel "NServers"
set logscale x
set ylabel "Simulation Time [s]"
set logscale y
set ytics nomirror
set y2label "Max Memory [KB]"
set y2tics nomirror
set y2range [0:]
set nologscale y2
set pointsize 2
set output "scala.eps"
p \
"scala-nservers-ts.log" u 2:3 t "Nservers TS (SimTime)" w lp pt 5 axes x1y1, \
"scala-nservers-ts.log" u 2:6 t "Nservers TS (Mem)" w lp pt 7 axes x1y2, \
"scala-nservers-nots.log" u 2:3 t "Nservers noTS (SimTime)" w lp pt 5 axes x1y1, \
"scala-nservers-nots.log" u 2:6 t "Nservers noTS (Mem)" w lp pt 7 axes x1y2


