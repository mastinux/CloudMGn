#!/bin/bash

CONFDIR="../simulations"
SIM="${CONFDIR}/run -u Cmdenv"
DEFNAPPS="10"
DEFNSERVERS="10"
NAPPS="10 20 50 100 200 500 1000"
NSERVERS="10 20 50 100 200 500 1000"
NALOGFILE="scala-napps.log"
NSLOGFILE="scala-nservers.log"
TIME=/usr/bin/time

declare -A config
export config

function runsim {
        # $1 --> logfile
        # $2 --> message
	#$TIME -a -o $1 -f "$2 elapsed[s]=%e user[s]=%U sys[s]=%S mem[KB]=%M ret=%x" $SIM > /dev/null
	$TIME -a -o $1 -f "$2 %e %U %S %M %x" $SIM > /dev/null
}

function printConfig {
	echo "* Config dump *"
        for cpar in "${!config[@]}"
        do 
                echo "$cpar -> \"${config["$cpar"]}\""
        done
}

function updateConfig {
        # $1 --> template config file
        # $2 --> output config file
        # use every entry in config array
        TMPF=/tmp/$$_conf
        cp $1 $TMPF
        for cpar in "${!config[@]}"
        do 
                sed -i s%$cpar%${config["$cpar"]}% $TMPF
        done
        mv $TMPF $2
}

if [ -n "$NALOGFILE" ]
then
	echo "*** SCALATEST: NAPPS ***"
	echo "# NApps NServers elapsed[s] user[s] sys[s] mem[KB] retval" > $NALOGFILE
	for na in $NAPPS
	do
		config["NAPPS"]=$na
		config["NSERVERS"]=$DEFNSERVERS
		config["INTERVAL"]=$(echo "scale=6; 1/${config[NSERVERS]}"|bc)
		config["TSERVICE"]="0.8" # rho=80%
		printConfig
		updateConfig ${CONFDIR}/omnetpp.ini.template ${CONFDIR}/omnetpp.ini
		rm -r $CONFDIR/results/*
		runsim $NALOGFILE "${config[NAPPS]} ${config[NSERVERS]}"
	done
fi

if [ -n "$NSLOGFILE" ]
then
	echo "*** SCALATEST: NSERVERS ***"
	echo "# NApps NServers elapsed[s] user[s] sys[s] mem[KB] retval" > $NSLOGFILE
	for ns in $NSERVERS
	do
		config["NAPPS"]=$DEFNAPPS
		config["NSERVERS"]=$ns
		config["INTERVAL"]=$(echo "scale=6; 1/${config[NSERVERS]}"|bc)
		config["TSERVICE"]="0.8" # rho=80%
		printConfig
		updateConfig ${CONFDIR}/omnetpp.ini.template ${CONFDIR}/omnetpp.ini
		rm -r $CONFDIR/results/*
		runsim $NSLOGFILE "${config[NAPPS]} ${config[NSERVERS]}"
	done
fi

gnuplot scala-graph.gnuplot
