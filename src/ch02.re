= デモアプリケーション


//lead{
Go言語とRevel web frameworkが、実行できる環境を構築していきます。
//}


//indepimage[imgsample][想い]


== VirtualBoxとubuntuのインストール

読者の皆さんの作業内容を統一するために今回は、virtualbox にLinux OS をインストールし、その上で作業を進めることにします。


=== VitualBoxの準備

VirtualBoxは、x86仮想化ソフトウェア・パッケージの一つで、米国オラクル社によって開発がすすめられています。
サポートされているホストOSはLinux、Mac OSX、Windows、Solarisです。
ゲストOSとしては、FreeBSD、Linux、OpenBSD、OS/2 Warp、Windows、Mac OS X Server、Solarisなどx86/x64アーキテクチャのOSであれば基本的には起動できます。
GPL ver.2で公開されているFOSSなので、無料で使用することが出来ます。

この本では、このソフトを利用し学習ベースとなるLinuxOSを起動することにします。
VirtualBoxは、以下の@<href>{https://www.virtualbox.org/wiki/Downloads, URLのページ}からダウンロードできます。目的のコンピューターのOSに適応したVirtualBoxのパッケージをダウンロードしインストールしていください。

==== VirtualBoxのダウンロードページ:

@<href>{https://www.virtualbox.org/wiki/Downloads, https://www.virtualbox.org/wiki/Downloads}


=== ubuntuのインストール

今回は、VirtualBox上のOSにsshで接続し作業することにします。従って、ubuntu 13.10 64bit server版をインストールすることにします。

インストールの詳細に関しては、○○○○○○○○○○○○○○○○してください。	

==== ubuntu 13.10 server 64bit版ISOイメージのダウンロードページ:

@<href>{http://www.ubuntu.com/download/server, http://www.ubuntu.com/download/server}


== Go言語のインストール

VirtualBox上に駆動しているubuntuの仮想マシンへsshを使ってアクセスします。


最初の段落です。
この行も同じ段落です。

次の段落です。

２行以上以上空いていても１行空いているのと同様に処理します。


== Revel web frameworkインストール

「=」「==」「===」の後に一文字空白をあけると見出しになります。


====[column] コラムについて

見出しの先頭に「[column]」と書くと、そこはコラムになります。


== 実行に必要な環境変数の設定

番号のない箇条書きは「*」を使います。前後に空白を入れて下さい。

 * 1つ目
 * 2つ目
 * 3つ目
