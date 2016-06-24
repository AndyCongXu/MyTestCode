#!/bin/sh

LocalFilePath=`~/1.txt`
LoacalIP=127.0.0.1
LoacalUsername=root
RemoteFilePath=/var/opt/fds/logs/
RemoteIP=10.170.7.194
RemoteUsername=root


#Send file to remote host
if [ -f $LocalFilePath ]; then
	scp -p $LocalFilePath $RemoteUsername@$RemoteIP:$RemoteFilePath
elif [ -d $LocalFilePath ]; then
	scp -r $LocalFilePath $RemoteUsername@$RemoteIP:$RemoteFilePath
fi

#Get file from remote host

if [ -f $RemoteFilePath ]; then
	scp -p $RemoteUsername@$RemoteIP:$RemoteFilePath $LocalFilePath
elif [ -d $RemoteFilePath ]; then
	scp -r $RemoteUsername@$RemoteIP:$RemoteFilePath $LocalFilePath
fi
