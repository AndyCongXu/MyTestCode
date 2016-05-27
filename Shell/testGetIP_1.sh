#!/bin/sh

INTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($1~/^eth1/ && $2~/inet/){print $1}}' | awk '{print $1}'`
echo 'XXXX 1 '$INTERFACE
if [ "X$INTERFACE" = "X" ] ; then
INTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($2~/inet/){print $1}}' | awk '{print $1}' | grep eth | tail -1`
echo 'XXXX 2 '$INTERFACE
fi

if [ "X$INTERFACE" = "X" ] ; then
INTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($1~/^bond1/ && $2~/inet/){print $1}}' | awk '{print $1}'`
echo 'XXXX 3 '$INTERFACE
fi
if [ "X$INTERFACE" = "X" ] ; then
INTERFACE=`ifconfig -a | awk 'BEGIN{RS="";FS="\n"}{if($2~/inet/){print $1}}' | awk '{print $1}' | grep bond | tail -1`
echo 'XXXX 4 '$INTERFACE
fi
if [ "X$INTERFACE" = "X" ] ; then
INTERFACE="127.0.0.1"
echo 'XXXX 5 '$INTERFACE
else
echo 'XXXX 6 '$INTERFACE
INTERFACE=`ifconfig $INTERFACE | grep inet | awk '{ print $2 }'| awk -F\: '{if ($2!="" ) print $2}'`
#INTERFACE=`ifconfig eth10 | grep inet | awk '{ print $2 }'| awk -F\: '{if ($2!="" ) print $2}'`
echo 'XXXX 7 '$INTERFACE
fi

echo 'XXXX 8 '$INTERFACE