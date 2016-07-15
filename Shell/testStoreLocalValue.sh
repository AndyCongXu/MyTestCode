#!/bin/sh

EXPORTFILE=/install/site.export
save_var()
{
        var=$1
        value_input=$2

        echo 'XXXX var= '$var
        echo 'XXXX value_input= '$value_input

        oldvalue=`cat $EXPORTFILE | grep "^$var="`
        newvalue=`eval echo \\$$var`
        echo 'XXXX oldvalue= '$oldvalue
        echo 'XXXX newvalue= '$newvalue

        if [ "X$newvalue" = "X" ];then
                value=${value_input}
        else
                value=${newvalue}
        fi

        if [ "X$oldvalue" = "X" ];then
                echo "###$var set by $CALLED_NAME ###">>$EXPORTFILE
                echo "###$var###">>$EXPORTFILE
                echo "$var=$value">>$EXPORTFILE
                echo "export $var">>$EXPORTFILE
                echo "###$var###">>$EXPORTFILE
                export $1
        else
                if [ "X${oldvalue}" = "X${var}=${value}" ];then
                        :
                        #echo "###$var set same value by $CALLED_NAME ###">>$EXPORTFILE
                else
                        :
                        #echo "###$var set different value by $CALLED_NAME ###">>$EXPORTFILE
                        #echo "###the different value = $value ###">>$EXPORTFILE
                fi
        fi
}

getfirstInterface()
{
    var="${1}"
    tmp=`hostname -i`
    tmp=${tmp// /;}
    eval "$var='$tmp'" #Please keep this command
    echo 'XXXX [mpc install preconfig.sh] var '$var
}

getfirstInterface IP_ADDRESS_TRAFFIC
echo 'XXXX 1'$IP_ADDRESS_TRAFFIC
save_var IP_ADDRESS_TRAFFIC "$IP_ADDRESS_TRAFFIC"
echo 'XXXX 2'$IP_ADDRESS_TRAFFIC

