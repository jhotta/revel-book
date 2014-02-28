= BrawserにRevelサイトの画面を表示するまで

//lead{
Go言語を使ってRevel web frameworkが、起動できる環境を構築していきます。
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




==== OSの設定変更

あsdふぁsdふぁsdふぁsdf

==== Go言語のインストール

VirtualBox上に駆動しているubuntuの仮想マシンへsshを使ってアクセスします。

==== Revel web frameworkインストール

「=」「==」「===」の後に一文字空白をあけると見出しになります。


====[column] 

vargrant provisionの際にsshアクセスができなくなる対策:

//cmd{
$ vi ~/ssh/know_hosts 
//}

fileの中身の表示の中から、"[127.0.0.1]:2222"と記されているブロック(数行)を削除する。


