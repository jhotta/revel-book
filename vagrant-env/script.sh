#! /bin/sh

sudo apt-get update
sudo apt-get -y install golang git mercurial sqlite

mkdir /home/vagrant/gocode

export GOPATH=/home/vagrant/gocode
echo 'export GOPATH=~/gocode' >> .bashrc
cd /home/vagrant/gocode && go get github.com/robfig/revel
cd /home/vagrant/gocode && go get github.com/robfig/revel/revel
echo 'export PATH="$PATH:$GOPATH/bin"' >> .bashrc