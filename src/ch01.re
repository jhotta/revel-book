= BrawserにRevelサイトの画面を表示するまで

//lead{
Go言語とRevel web frameworkが、実行できる環境を構築していきます。
//}


== ソフトウェアのインストールと仮想マシンイメージの設定

=== VitualBoxの準備

VirtualBoxは、x86仮想化ソフトウェア・パッケージの一つで、米国オラクル社によって開発がすすめられています。
サポートされているホストOSはLinux、Mac OSX、Windows、Solarisです。
ゲストOSとしては、FreeBSD、Linux、OpenBSD、OS/2 Warp、Windows、Mac OS X Server、Solarisなどx86/x64アーキテクチャのOSであれば基本的には起動できます。
GPL ver.2で公開されているFOSSなので、無料で使用することが出来ます。

この本では、このソフトを利用し学習ベースとなるLinuxOSを起動することにします。
VirtualBoxは、以下の@<href>{https://www.virtualbox.org/wiki/Downloads, URL}のページからダウンロードできます。目的のコンピューターのOSに適応したVirtualBoxのパッケージをダウンロードしインストールしていください。

//indepimage[virtualbox_dl][VirtualBoxのダウンロードページ]


=== Vagrantによる環境設定

==== 仮想マシンイメージの準備 

==== vagrantfileの準備

==== Go言語のインストール

VirtualBox上に駆動しているubuntuの仮想マシンへsshを使ってアクセスします。


最初の段落です。
この行も同じ段落です。

次の段落です。

２行以上以上空いていても１行空いているのと同様に処理します。


==== Revel web frameworkインストール

「=」「==」「===」の後に一文字空白をあけると見出しになります。


====[column] コラムについて

見出しの先頭に「[column]」と書くと、そこはコラムになります。