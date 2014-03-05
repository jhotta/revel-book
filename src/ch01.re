= Revelで開発するための環境の準備

//lead{
Go言語を使ってRevelが、起動できる環境を構築していきます。
//}


== 各種ソフトウェアのインストール

=== VitualBoxのインストール

この本では、VirtualBoxを利用してベースとなるLinuxOSを起動することにします。
VirtualBoxは、以下の@<href>{https://www.virtualbox.org/wiki/Downloads, ページURL}からダウンロードできます。

今作業しているPCのOSに適応したVirtualBoxのパッケージを、このサイトからダウンロードします。

//image[vb_dl][VirtualBoxのダウンロードページ]{
//}

先にダウンロードしたVirtualBoxのインストールファイルをダブルクリックし、ポップアップメニューの指示に従ってVirtualBoxをインストルします。

//image[vb_inst1][インストール図1]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVirtualBoxをインストルします。

//image[vb_inst2][インストール図2]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVirtualBoxをインストルします。

//image[vb_inst3][インストール図3]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVirtualBoxをインストルします。


=== Vagrantのインストール

VirtualBoxは直接操作しても特に問題はなのですが、仮想OS環境を効率よく操作すると共に基本環境の構築の再現性を上げるために、今回はVagrantを使用することにします。

Vagrantは、以下の@<href>{http://www.vagrantup.com/downloads.html, ページURL}からダウンロードできます。

今作業しているPCのOSに適応したVirtualBoxのパッケージを、このサイトからダウンロードします。

//image[vg_dl][Vagrantのダウンロードページ]{
//}

先にダウンロードしたVirtualBoxのインストールファイルをダブルクリックし、ポップアップメニューの指示に従ってVirtualBoxをインストルします。

//image[vg_inst1][インストール図1]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVagrantをインストルします。

//image[vg_inst2][インストール図2]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVagrantをインストルします。

//image[v_inst3][インストール図3]{
//}

ダウンロードしたファイルをダブルクリックし、ポップアップメニューの指示に従いVagrantをインストルします。

インストールが完了したところで、Vagrantの操作をするするためにコンソールを起動します。OSXであれば、terminalを実行し、コマンドを入力することになります。



//cmd{
$ vagrant --version
//}

以下の内容が表示されれば、Vagrantのインストールは終了です。

//cmd{
Vagrant 1.4.3
//}


=== 仮想マシンイメージの準備 

http://www.vagrantbox.es/

//image[v_inst3][インストール図3]{
//}

今回は、"Official Ubuntu 13.10 daily Cloud Image amd64 (Development release, No Guest Additions)"と書かれている仮想マシンメージをVagrantの管理下にインポートして使うことにします。

コマンドの基本は以下のフォーマットになります。

//cmd{
$ vagrant box add {title} {url}
//}

今回は、ubuntuコミュニティーが提供している	先の仮想イメージのurlを指定し、ubuntuをtitleに指定し、Vagrant管理下にダウンロードしてきます。

//cmd{
$ vagrant box add ubuntu \
http://cloud-images.ubuntu.com/vagrant/saucy/current/\
saucy-server-cloudimg-amd64-vagrant-disk1.box
//}

上記のコマンドを実行すると、下記の内容がターミナルウインドーに表示され、仮想OS用のイメージの登録が終了します。

//cmd{
Downloading box from URL: http://cloud-images.ubuntu.com/vagrant/saucy/current/saucy-server-cloudimg-amd64-vagrant-disk1.box
Extracting box...te: 1131k/s, Estimated time remaining: --:--:--)
Successfully added box 'ubuntu' with provider 'virtualbox'!
//}

万が一、仮想OSのイメージ登録に失敗した場合やイメージが不要になった場合は、以下のlistコマンドで確認の上、削除できます。

//cmd{
$ vagrant box list
$ vagrant box revmove {title}
//}

それでは、vagrantに必要なファイルを置いておくディレクトリーを作ることにします。	

//cmd{
$ mkdir ~/vagrant-env
$ cd ~/vagrant-env
//}

下記のフィーマットのコマンドを使ってVagarantfileを生成します。

//cmd{
$ vagrant init {title}
//}

{title}の部分には、先ほど指定した仮想OSイメージ名を指定しコマンドを実行します。

//cmd{
$ vagrant init ubuntu
//}

下記のような実行か結果が表示されている確認してください。

//cmd{
A `Vagrantfile` has been placed in this directory. You are now
ready to `vagrant up` your first virtual environment! Please read
the comments in the Vagrantfile as well as documentation on
`vagrantup.com` for more information on using Vagrant.
//}

それでは、ここで仮想OSを起動してみます。

//cmd{
$ vagrant up
//}

画面は、流れるように進んでいきます。最終的には以下のような内容の画面が表示されていることを確認してください。

//cmd{
Bringing machine 'default' up with 'virtualbox' provider...
[default] Importing base box 'ubuntu'...
[default] Matching MAC address for NAT networking...
[default] Setting the name of the VM...
[default] Clearing any previously set forwarded ports...
[default] Clearing any previously set network interfaces...
[default] Preparing network interfaces based on configuration...
[default] Forwarding ports...
[default] -- 22 => 2222 (adapter 1)
[default] Booting VM...
[default] Waiting for machine to boot. This may take a few minutes...
[default] Machine booted and ready!
[default] The guest additions on this VM do not match the installed version of
VirtualBox! In most cases this is fine, but in rare cases it can
prevent things such as shared folders from working properly. If you see
shared folder errors, please make sure the guest additions within the
virtual machine match the version of VirtualBox you have installed on
your host and reload your VM.

Guest Additions Version: 4.2.16
VirtualBox Version: 4.3
[default] Mounting shared folders...
[default] -- /vagrant
//}

仮想OSが起動している夜なら、sshで仮想環境にアクセスすることにします。

//cmd{
$ vagrant ssh
//}

以下のコマンドが、表示されているでしょうか？

//cmd{
Please report a bug if this causes problems.
Welcome to Ubuntu 13.10 (GNU/Linux 3.11.0-17-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

  System information as of Wed Feb 26 04:07:30 UTC 2014

  System load:  0.98              Processes:           86
  Usage of /:   2.6% of 39.34GB   Users logged in:     0
  Memory usage: 28%               IP address for eth0: 10.0.2.15
  Swap usage:   0%

  Graph this data and manage this system at:
    https://landscape.canonical.com/

  Get cloud support with Ubuntu Advantage Cloud Guest:
    http://www.ubuntu.com/business/services/cloud

0 packages can be updated.
0 updates are security updates.

vagrant@vagrant-ubuntu-saucy-64:~$
//}

ここまでで、Vagarantによってコントロールできる仮想環境ができました。
それでは、仮想OS環境のシェルから、本体のシェルも戻ります。

//cmd{
$ exit
//}

本体のシェルに戻ったところで、仮想OSの環境を停止します。

//cmd{
$ vagrant halt
//}

====[column] 

コマンドプロンプトの直前に下記のようなWARNINGが表示された場合:

//cmd{
_____________________________________________________________________
WARNING! Your environment specifies an invalid locale.
 This can affect your user experience significantly, including the
 ability to manage packages. You may install the locales by running:

   sudo apt-get install language-pack-UTF-8
     or
   sudo locale-gen UTF-8

To see all available language packs, run:
   apt-cache search "^language-pack-[a-z][a-z]$"
To disable this message for all users, run:
   sudo touch /var/lib/cloud/instance/locale-check.skip
_____________________________________________________________________
//}


Mac側でTerminalの設定の確認:

//image[mac_ssh][OSX terminalの設定]{
Settings > Advanced > Set locale environment variables on startup にチェックマークがある。
//}

概要:

Mac側でTerminalのlocaleにLC_CTYPE=UTF-8が設定がされ、Ubuntuが解釈できないので以下のような警告が場合があります。

解決策:

"Set locale environment variables on startup"の前にあるチェエクマークを外してください。

=== ansibleのインストール

OSXにHomebrewが事前にインストールされていることを前提にansibleのインストールを進めていきます。

//cmd{
$ brew install ansible
//}

下記のようなインンストールが進行しビールジョッキの行が表示されれば、インストールは順調に完了したと推測できます。


//cmd{
==> Downloading https://github.com/ansible/ansible/archive/v1.4.5.tar.gz
Already downloaded: /Library/Caches/Homebrew/ansible-1.4.5.tar.gz
==> Downloading https://pypi.python.org/packages/source/p/pycrypto/pycrypto-2.6.
Already downloaded: /Library/Caches/Homebrew/ansible--pycrypto-2.6.tar.gz
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5/libexec
==> Downloading https://pypi.python.org/packages/source/P/PyYAML/PyYAML-3.10.tar
Already downloaded: /Library/Caches/Homebrew/ansible--pyyaml-3.10.tar.gz
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5/libexec
==> Downloading https://pypi.python.org/packages/source/p/paramiko/paramiko-1.11
Already downloaded: /Library/Caches/Homebrew/ansible--paramiko-1.11.0.tar.gz
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5/libexec
==> Downloading https://pypi.python.org/packages/source/M/MarkupSafe/MarkupSafe-
Already downloaded: /Library/Caches/Homebrew/ansible--markupsafe-0.18.tar.gz
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5/libexec
==> Downloading https://pypi.python.org/packages/source/J/Jinja2/Jinja2-2.7.1.ta
Already downloaded: /Library/Caches/Homebrew/ansible--jinja2-2.7.1.tar.gz
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5/libexec
==> python setup.py install --prefix=/usr/local/Cellar/ansible/1.4.5
==> Caveats
Set PYTHONPATH if you need Python to find the installed site-packages:
  export PYTHONPATH=/usr/local/lib/python2.7/site-packages:$PYTHONPATH
==> Summary
🍺  /usr/local/Cellar/ansible/1.4.5: 763 files, 8.8M, built in 13 seconds
//}

ここで、ansibleの動作確認をしてみます。

//cmd{
$ ansible --version
//}

以下のようにバージョンが表示されれば、インストールは成功しています。

//cmd{
ansible 1.4.5
//}


== 仮想マシンイメージの設定

=== Vagrantfileの準備

VirtualBoxの動作の設定、仮想OSの設定変更、アプリの自動でインストールのために、Vagrantを実行するディレクトリを初期化した際に出来上がったVagrantfileを編集していきます。

完成後のVagrantfileは、次のようになります。

//listnum[Vagrantfile_fnl][完成した Vagrantfile]{
# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

  config.vm.box = "ubuntu"
  config.vm.network :forwarded_port, guest: 9000, host: 9000

  config.vm.provision "ansible" do |ansible|
    ansible.playbook = "playbook.yml"
  end

end
//}

==== VitrualBoxの動作設定

自動で出来上がったVagrantfileのコメント部分を削除すると次のようになるはずです。

//listnum[Vagrantfile_org][オリジナル Vagrantfile]{ 
# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "ubuntu"
end
//}

次の行は、Vagrantfileが利用するAPIのバージョンの指定をしています。
//emlist{ 
VAGRANTFILE_API_VERSION = "2"
//}

ここで示したdo ~ endの間にVirtualBoxが起動してくる際にオプションとして指定する項目を記述していきます。
//emlist{ 
Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

end
//}

"vagarant init"で生成した素のVagrantfileでは、生成時に指定した"ubuntu"のマシンイメージのみが指定されています。

//emlist{ 
config.vm.box = "ubuntu"
//}


オリジナルのVagrantfileの内容が把握出来たところで、追加の設定を記述していくことにします。


==== 待ち受けPortのforwading設定

仮想OS上に起動されてたRevelがブラウザーのリクエストに反応するために待ち受けているPort番号を、VirtualBoxのPort番号と関連付けをすることにします。

//emlist{
config.vm.network :forwarded_port, guest: 9000, host: 9000
//}


==== OSの設定変更

ポート番号の関連付けが済んだ後の設定作業は、ansibileを使って進めることにします。

//emlist{
config.vm.provision "ansible" do |ansible|
  ansible.playbook = "playbook.yml"
end
//}

provisionツールのansibleを利用することを宣言し、ansibleによって仮想OSを設定する内容がplaybook.ymlに記述されていることを宣言しています。


=== playbook.yamlの準備

Vagrantfileに設定内容の詳細を記述するファイルとして宣言しておいたplaybook.yamlの準備することにします。

完成後のplaybook.yamlは、次の様な内容になります。ansibleが、このファイルの内容を上から順番に処理し、仮想OS環境に設定変更実施しアプリケーションをインストールします。

//listnum[playbook][playbook.yaml]{
---
- hosts: all

  user: vagrant
  tasks:

    - name: "update hosts"
      copy: src=files/hosts
            dest=/etc/hosts
            owner=root
            group=root
            mode=644
            backup=yes
      sudo: yes

    - name: "apt-get install golang"
      apt:  pkg=golang
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install git"
      apt:  pkg=git
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install mercurial"
      apt:  pkg=mercurial
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install sqlite"
      apt:  pkg=sqlite
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install slibsqlite3-dev"
      apt:  pkg=libsqlite3-dev
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install language-pack-en-base"
      apt:  pkg=language-pack-en-base
      sudo: yes

    - name: "apt-get install language-pack-ja-base"
      apt:  pkg=language-pack-ja-base
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "apt-get install tree"
      apt:  pkg=tree
            update_cache=yes
            cache_valid_time=3600
      sudo: yes

    - name: "update bashrc"
      copy: src=files/.bashrc
            dest=/home/vagrant/.bashrc
            owner=vagrant
            group=vagrant
            mode=644
            backup=yes

    - name: "mkdir gocode"
      command:  mkdir /home/vagrant/gocode
                creates=/home/vagrant/gocode

    - name: "go get github.com/robfig/revel"
      shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode 
              && go get github.com/robfig/revel
              creates=/home/vagrant/gocode/src/github.com/robfig/revel

    - name: "go get github.com/robfig/revel/revel"
      shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
              && go get github.com/robfig/revel/revel
              creates=/home/vagrant/gocode/bin/revel

    - name: "go get github.com/coopernurse/gorp"
      shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
              && go get github.com/coopernurse/gorp
              creates=/home/vagrant/gocode/src/github.com/coopernurse/gorp

    - name: "go get github.com/mattn/go-sqlite3"
      shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
              && go get github.com/mattn/go-sqlite3
              creates=/home/vagrant/gocode/src/github.com/mattn/go-sqlite3

    - name:  "revel new myapp"
      shell:  export GOPATH=/home/vagrant/gocode && && cd /home/vagrant/gocode
              && revel  run myapp
              creates=/home/vagrant/gocode/src/myapp
//}

ansbileでは、各設定項目をタスクと呼びます。
タスクは、次のような書式になります。

//emlist{
- name: [タスクの名前]
  [使用するモジュール]: [モジュールで規定された書式]
  [オプション]: [オプションで指定されて書式]
//}

タスクの名前は、自由に付けても大丈夫です。使用するモジュールやオプションの詳細は、ansibleドキュメントサイト URL:@<href>{http://docs.ansible.com/}を参考にしてください。  


==== hostsの設定

この本を執筆している期間中何度か、ubuntuのpackageをアップデートするためのリポジトリーサーバのIPアドレスの解決がDNS経由ではできなくなるケースがありました。期間中DNSでは安定しなかったため、ubuntuのリポジトリーサーバーのIPアドレス情報を/etc/hostsに静的に追記し、その情報を基にapt-getのコマンドがリポジトリーサーバの名前解決をするようにしました。

仮想OS環境の/etc/hostsを上書きするためのファイルを転送するためにansibleのcopyモジュール使用します。

//emlist{
- name: "update hosts"
  copy: src=files/hosts
        dest=/etc/hosts
        owner=root
        group=root
        mode=644
        backup=yes
  sudo: yes
//}

/etc/hostsは上書きは、root権限が必要なのでsudoの権限オプションも設定してます。


==== Go言語のインストール

Go言語のインストールは、ubuntu標準のパッケージを使用することにします。 
従って、ansbileのaptモジュールを使ってインストールすることにします。  

//emlist{
    - name: "apt-get install golang"
      apt:  pkg=golang
            update_cache=yes
            cache_valid_time=3600
      sudo: yes
//}

update_cache, cache_valid_timeはオプションの設定でパッケージのupdateの頻度をコントロールしています。


==== DBその他のdebパッケージのインストール

apt-getでGo言語のパッケージをインストールした後は、Revelを利用するのに必要になるソフトウェアのパッケージをインストールしています。

各タスクのnameの部分に設定した内容の作業を、それぞれ実行しています。

 * apt-get install git
 * apt-get install mercurial
 * apt-get install sqlite
 * apt-get install slibsqlite3-dev
 * apt-get install language-pack-en-base(localeによるエラーの対策)
 * apt-get install language-pack-ja-base(localeによるエラーの対策)
 * apt-get install tree (ディレクトリのtree表示させるため)


==== Revelインストール

Revelのインストールは、ドキュメントサイトの
@<href>{http://robfig.github.io/revel/tutorial/gettingstarted.html, Getting Startedページ}を参考に進めていくことにします。

次は、仮想OSにsshでアクセスした際にの起動ShellにGO言語の環境PATHが設定されいるように~/.bashrcを上書記します。
.bashrcも、hostsと同様にcopyモジュールを使って転送することにします。
~/vagrant-env/files/ディレクトリに仮想OS環境へ転送するための.bashrcを設置しておきます。

//emlist{
- name: "update bashrc"
  copy: src=files/.bashrc
        dest=/home/vagrant/.bashrc
        owner=vagrant
        group=vagrant
        mode=644
        backup=yes
//}

転送元の.bashrcは、ubuntuの一般的な.bashrcに下記の3行を追記したもになります。
実際に変更した.bashrcのサンプルは付録Aに掲載してあります。

GOPATHは、GO言語の環境PATHで自由に決めることが出来ます。ここで決めたPATHに合わせてGO言語用のディレクトリを作ることに成ります。又、$GOPATH/binには、GO言語のビルド後の
バイナリーファイルが保存されます。従って、Shellの実行PATHに、このbinディレクトリーも追加しておきます。

//emlist{
# golang env
export GOPATH=/home/vagrant/gocode
export PATH=$PATH:/home/vagrant/gocode/bin
//}

先に指定したGOPATHに基づいてディレクトリを作ります。
既に該当のある場合は再度ディレクトリを作らないように、createsオプションを指定しておきます。

//emlist{
- name: "mkdir gocode"
  command:  mkdir /home/vagrant/gocode
            creates=/home/vagrant/gocode
//}

次のブロックは、"go get github.com/robfig/revel"のシェルコマンドを実行しています。
このシェルコマンドは、githubよりrevelのソースを取得し、$GOPATH/src以下に保存してくれます。
既に該当のある場合は再度ディレクトリを作らないように、createsオプションを指定しておきます。

//emlist{
- name: "go get github.com/robfig/revel"
  shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode 
          && go get github.com/robfig/revel
          creates=/home/vagrant/gocode/src/github.com/robfig/revel
//}

次のブロックは、"go get github.com/robfig/revel/revel"のシェルコマンドを実行しています。
このシェルコマンドは、$GOPATH/bin以下に、revelのバイナリを生成してくれます。
既に該当のある場合は再度ディレクトリを作らないように、createsオプションを指定しておきます。

//emlist{
- name: "go get github.com/robfig/revel/revel"
  shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
          && go get github.com/robfig/revel/revel
          creates=/home/vagrant/gocode/bin/revel
//}

BDを使用しない場合は、ここまでRevelの終了。


==== DB(Sqlite)を使用するためのGO言語関連パッケージのインストール

今回は、DBも使用したいので引き続きDB関連パッケージをインストールすることにします。

次のブロックは、"go get github.com/coopernurse/gorp"のシェルコマンドを実行しています。
このシェルコマンドは、GO言語からDBを操作するためのORMのようなgorpモジュールをgithubより取得し、$GOPATH/src以下に保存してくれます。
既に該当のある場合は再度ディレクトリを作らないように、createsオプションを指定しておきます。

//emlist{
- name: "go get github.com/coopernurse/gorp"
  shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
          && go get github.com/coopernurse/gorp
          creates=/home/vagrant/gocode/src/github.com/coopernurse/gorp
//}

次のブロックは、"go get github.com/mattn/go-sqlite3"のシェルコマンドを実行しています。
このシェルコマンドは、GO言語からsqliteを使用するためのドライバーモジュールをgithubより取得し、$GOPATH/src以下に保存してくれます。
既に該当のある場合は再度ディレクトリを作らないように、createsオプションを指定しておきます。

//emlist{
- name: "go get github.com/mattn/go-sqlite3"
  shell:  export GOPATH=/home/vagrant/gocode && cd /home/vagrant/gocode
          && go get github.com/mattn/go-sqlite3
          creates=/home/vagrant/gocode/src/github.com/mattn/go-sqlite3
//}

これで、DBも扱える環境も含めてインストールするための、Vagrantfileが完成しました。 


=== Revelを起動

今回は、プロビジョンのプションを付けて仮想OSをvagrantから起動します。

//cmd{
$ vagrant up --provision  
//}

起動の途中に、sshで使用するRSA keyに関する問合せがありますので、"yes"と入力してください。
プロビジョンのプロセスが終了するまでには、しばらく時間がかかります。次のような実行結果が表示されれば終了です。

//cmd{
Bringing machine 'default' up with 'virtualbox' provider...
[default] Clearing any previously set forwarded ports...
[default] Clearing any previously set network interfaces...
[default] Preparing network interfaces based on configuration...
[default] Forwarding ports...
[default] -- 22 => 2222 (adapter 1)
[default] -- 9000 => 9000 (adapter 1)
[default] Booting VM...
[default] Waiting for machine to boot. This may take a few minutes...
[default] Machine booted and ready!
[default] Mounting shared folders...
[default] -- /vagrant
[default] Running provisioner: ansible...

PLAY [all] ******************************************************************** 

GATHERING FACTS *************************************************************** 
The authenticity of host '[127.0.0.1]:2222 ([127.0.0.1]:2222)' can't be established.
RSA key fingerprint is e7:a6:12:c6:ef:17:90:c9:69:46:c0:4a:83:b8:fb:0c.
Are you sure you want to continue connecting (yes/no)? yes
ok: [default]

TASK: [update hosts] ********************************************************** 
changed: [default]

TASK: [apt-get install golang] ************************************************ 
changed: [default]

TASK: [apt-get install git] *************************************************** 
changed: [default]

TASK: [apt-get install mercurial] ********************************************* 
changed: [default]

TASK: [apt-get install sqlite] ************************************************ 
changed: [default]

TASK: [apt-get install slibsqlite3-dev] *************************************** 
changed: [default]

TASK: [apt-get install language-pack-en-base] ********************************* 
changed: [default]

TASK: [apt-get install language-pack-ja-base] ********************************* 
changed: [default]

TASK: [apt-get install tree] ************************************************** 
changed: [default]

TASK: [update bashrc] ********************************************************* 
changed: [default]

TASK: [mkdir gocode] ********************************************************** 
changed: [default]

TASK: [go get github.com/robfig/revel] **************************************** 
changed: [default]

TASK: [go get github.com/robfig/revel/revel] ********************************** 
changed: [default]

TASK: [go get github.com/coopernurse/gorp] ************************************ 
changed: [default]

TASK: [go get github.com/mattn/go-sqlite3] ************************************ 
changed: [default]

PLAY RECAP ******************************************************************** 
default                    : ok=16   changed=15   unreachable=0    failed=0 
//}

プロンプトが戻ってきたら、本体OSから仮想OSにsshで接続します。

//cmd{
$ vagrant ssh
$ ls
//}

先ほど確認したubuntuのログイン画面が表示され、lsマンドを実行したところでgocodeのディレクトリーが表示されていることを確認します。

gocodeディレクトリーに移動し、Revelを使って開発していくためのディレクトリー構成の雛形を生成することにします。

//cmd{
$ cd ~/gocode
$ revel new myapp
//}

~/gocode/src/myappディレクトリ以下に次のような雛形が生成されました。

//cmd{
.
├── app
│   ├── controllers
│   │   └── app.go
│   ├── init.go
│   └── views
│       ├── App
│       │   └── Index.html
│       ├── debug.html
│       ├── errors
│       │   ├── 404.html
│       │   └── 500.html
│       ├── flash.html
│       ├── footer.html
│       └── header.html
├── conf
│   ├── app.conf
│   └── routes
├── messages
│   └── sample.en
├── public
│   ├── css
│   │   └── bootstrap.css
│   ├── img
│   │   ├── favicon.png
│   │   ├── glyphicons-halflings.png
│   │   └── glyphicons-halflings-white.png
│   └── js
│       └── jquery-1.9.1.min.js
└── tests
    └── apptest.go

12 directories, 18 files
//}

myappを起動してみます。

//cmd{
$ revel run myapp
//}

本体OSでブラウザーを起動し、http://localhost:9000にアクセスします。
次のような画面がブラウザーに表示されれば、始めてのRevelは完成です。


//image[result_page][myapp完成ページ]{
//}

== Githubでソースコードを管理するための準備  



