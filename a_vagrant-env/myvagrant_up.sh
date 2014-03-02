#! /bin/sh

if [ `uname` = "Linux" ]; then

	if [ -e ~/.ssh/known_hosts ]; then
		rm ~/.ssh/known_hosts
		touch ~/.ssh/known_hosts
	fi

elif [ `uname` = "Darwin" ]; then

	if [ -e ~/.ssh/known_hosts ]; then
		sed -e "/\[127.0.0.1\]\:2222/d" ~/.ssh/known_hosts > tmpfile
		mv tmpfile ~/.ssh/known_hosts
	fi

fi

vagrant up
