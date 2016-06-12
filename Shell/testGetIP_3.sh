#!/bin/sh

if [ "`uname -s`" = "Linux" ]
then
        # eth1      Link encap:Ethernet  HWaddr 00:15:17:0B:A1:3F  
                  # BROADCAST MULTICAST  MTU:1500  Metric:1
                  # RX packets:0 errors:0 dropped:0 overruns:0 frame:0
                  # TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
                  # collisions:0 txqueuelen:1000 
                  # RX bytes:0 (0.0 b)  TX bytes:0 (0.0 b)

        # eth2      Link encap:Ethernet  HWaddr 00:24:81:E1:EB:70  
                  # inet addr:10.170.7.27  Bcast:10.170.7.255  Mask:255.255.255.0
                  # inet6 addr: fe80::224:81ff:fee1:eb70/64 Scope:Link
                  # UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
                  # RX packets:416500 errors:0 dropped:0 overruns:0 frame:0
                  # TX packets:284667 errors:0 dropped:0 overruns:0 carrier:0
                  # collisions:0 txqueuelen:1000 
                  # RX bytes:91759357 (87.5 Mb)  TX bytes:71065531 (67.7 Mb)
                  # Interrupt:169 Memory:f4000000-f4012800 

        ANINTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($1~/^eth1/ && $2~/inet/){print $1}}' | awk '{print $1}'`
        echo "XXXX 1 "$ANINTERFACE
        if [ "X$ANINTERFACE" = "X" ] ; then
            ANINTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($2~/inet/){print $1}}' | awk '{print $1}' | grep eth | tail -1`
            echo "XXXX 2 "$ANINTERFACE
        fi  

        tmp=`ifconfig $ANINTERFACE | grep inet | awk '{ print $2 }'| awk -F\: '{if ($2!="" ) print $2}'`
        echo "XXXX 3 "$tmp
else

        # check for the available network interfaces on this host first choice is bge1.
        ANINTERFACE=`ifconfig -a | grep : | grep -v ether | sed -e 's/^\([a-z]\{2,3\}[0-9]\):.*$/\1/' | grep bge1`
        echo "XXXX 4 "$ANINTERFACE
        if [ "X$ANINTERFACE" = "X" ] ; then
                ## can't get bge1 then get the last interface in the list.
                ANINTERFACE=`ifconfig -a | grep : | grep -v ether | sed -e 's/^\([a-z]\{2,3\}[0-9]\):.*$/\1/' | sed -e 's/^\([a-z][0-9]\{4\}[a-z][0-9]\):.*$/\1/'| tail -1`
                echo "XXXX 5 "$ANINTERFACE
        fi  

        ANINTERFACE=`echo $ANINTERFACE | $OS_AWK '{ print $1}' | sed -e 's/:/ /g' `
        echo "XXXX 6 "$ANINTERFACE
        tmp=`ifconfig $ANINTERFACE | grep inet | $OS_AWK '{ print $2 }'`
        echo "XXXX 7 "$tmp

fi 
