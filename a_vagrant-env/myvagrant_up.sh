#! /bin/sh

if [ -e ~/.ssh/known_hosts ]; then
	rm ~/.ssh/known_hosts
	touch ~/.ssh/known_hosts
fi

vagrant up