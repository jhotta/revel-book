#! /bin/sh

#if []; then
#	if [ -e ~/.ssh/known_hosts ]; then
#		rm ~/.ssh/known_hosts
#		touch ~/.ssh/known_hosts
#	fi
#elfi []; then
sed -e "/\[127.0.0.1\]\:2222/d" ~/.ssh/known_hosts > tmpfile
mv tmpfile ~/.ssh/known_hosts

#fi

vagrant up