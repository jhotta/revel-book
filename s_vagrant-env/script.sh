#! /bin/sh

# DNSでhost名からIPアドレスの検索が出来てないときのためにセットする。
echo "91.189.92.200 archive.ubuntu.com" >> /etc/hosts
echo "91.189.92.200 security.ubuntu.com" >> /etc/hosts
echo "192.30.252.131 github.com" >> /etc/hosts
echo "74.125.235.129 code.google.com" >> /etc/hosts

# Ubuntuパッケージのインストール
sudo apt-get update
sudo apt-get -y install git mercurial sqlite libsqlite3-dev golang language-pack-en-base language-pack-ja-base tree
# sudo dpkg-reconfigure locales

# gocodeへのパスの設定
echo "export GOPATH=/home/vagrant/gocode" >> .bashrc
echo "export PATH=$PATH:/home/vagrant/gocode/bin" >> .bashrc


# revelを実行するための環境をインポート
export GOPATH=/home/vagrant/gocode
mkdir /home/vagrant/gocode
cd /home/vagrant/gocode && go get github.com/robfig/revel
cd /home/vagrant/gocode && go get github.com/robfig/revel/revel
cd /home/vagrant/gocode && go get github.com/coopernurse/gorp
cd /home/vagrant/gocode && go get github.com/mattn/go-sqlite3
cd /home/vagrant/gocode && go get github.com/robfig/revel/revel
cd /home/vagrant/gocode/src && git clone https://github.com/jhotta/revelFramework4Go.git 

# gocodeディレクトリーの所有権を変更
chown -R vagrant:vagrant /home/vagrant/gocode
