#!/bin/sh

if [ "X$INTERFACE" = "X" ] ; then   ## if bge1 was not avaiable get the last interface in the list
    INTERFACE=`ifconfig -a | grep : | grep -v ether | sed -e 's/^\([a-z]\{2,3\}[0-9]\):.*$/\1/' | sed -e 's/^\([a-z][0-9]\{4\}[a-z][0-9]\):.*$/\1/'| tail -1` 
    echo 'XXXX 1 '$INTERFACE
fi

#Added for TR HG73648 doesn't support virtual IP during installation
INTERFACE=`echo $INTERFACE | awk '{ print $1}' | sed -e 's/:/ /g' `
    echo 'XXXX 2 '$INTERFACE

if [ "X$IP_ADDRESS_TRAFFIC" = "X" ]
then
    IP_ADDRESS_TRAFFIC=`ifconfig $INTERFACE | grep inet | awk '{ print $2 }'`
    echo 'XXXX 3 '$IP_ADDRESS_TRAFFIC
fi
