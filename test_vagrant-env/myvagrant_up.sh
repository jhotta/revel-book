#! /bin/sh

#if []; then
	vagrant destroy -f default
#fi

if [ `uname` = "Linux" ]; then

	if [ -e ~/.ssh/known_hosts ]; then
		ssh-keygen -R [127.0.0.1]:2222
	fi

elif [ `uname` = "Darwin" ]; then

	if [ -e ~/.ssh/known_hosts ]; then
		sed -e "/\[127.0.0.1\]\:2222/d" ~/.ssh/known_hosts > tmpfile
		mv tmpfile ~/.ssh/known_hosts
	fi

fi

vagrant up --provision
