#! /bin/sh

sudo apt-get update
sudo apt-get -y install vim git mercurial sqlite golang language-pack-en-base language-pack-ja-base
# sudo dpkg-reconfigure locales

echo "export GOPATH=/home/vagrant/gocode" >> .bashrc
echo "export PATH=$PATH:/home/vagrant/gocode/bin" >> .bashrc

export GOPATH=/home/vagrant/gocode
mkdir /home/vagrant/gocode
cd /home/vagrant/gocode && go get github.com/robfig/revel
cd /home/vagrant/gocode && go get github.com/robfig/revel/revel
chown -R vagrant:vagrant /home/vagrant/gocode
