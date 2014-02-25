= BrawserにRevelサイトの画面を表示するまで

//lead{
Go言語を使ってRevel web frameworkが、起動できる環境を構築していきます。
//}


== ソフトウェアのインストールと仮想マシンイメージの設定

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


=== Vagrantによる環境設定

==== Vagrantのインストール

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


//cmd{
$ vagrant --version
//}

以下の内容が表示されれば、Vagrantのインストールは終了です。

//cmd{
Vagrant 1.4.3
//}


==== 仮想マシンイメージの準備 

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

上記のコマンドを実行すると、下記の内容がターミナルウインドーに表示され、登録が終了します。

//cmd{
WARN: Unresolved specs during Gem::Specification.reset:
      ffi (>= 1.0.11, ~> 1.0)
WARN: Clearing out unresolved specs.
Please report a bug if this causes problems.
Downloading box from URL: http://cloud-images.ubuntu.com/vagrant/saucy/current/saucy-server-cloudimg-amd64-vagrant-disk1.box
Extracting box...te: 1131k/s, Estimated time remaining: --:--:--)
Successfully added box 'ubuntu' with provider 'virtualbox'!
//}

ここに解説を書く!

//cmd{
$ vagrant box revmove {title}
//}

ここに解説を書く!

//cmd{
$ mkdir ~/vagrant-env
$ cd ~/vagrant-env
//}

ここに解説を書く!

//cmd{
$ vagrant init {title}
//}

ここに解説を書く!

//cmd{
$ vagrant init vagrant-env
//}

ここに解説を書く!

//cmd{
$ vagrant up
//}

ここに解説を書く!

//cmd{
こんな内容のが表示される。
//}

ここに解説を書く!

//cmd{
$ vagrant ssh
//}

ここに解説を書く!

//cmd{
sshの接続結果を表示
//}

ここに解説を書く!


==== Vagrantfileの準備


=== Go言語のインストール

VirtualBox上に駆動しているubuntuの仮想マシンへsshを使ってアクセスします。


最初の段落です。
この行も同じ段落です。

次の段落です。

２行以上以上空いていても１行空いているのと同様に処理します。


=== Revel web frameworkインストール

「=」「==」「===」の後に一文字空白をあけると見出しになります。


====[column] コラムについて

見出しの先頭に「[column]」と書くと、そこはコラムになります。