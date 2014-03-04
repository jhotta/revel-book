= 準備する環境

この本の対象とする読者にはマイクロソフト社製のOSを利用している人も多々いると思うが、私自身Windows XP以降マイクロソフト社製OSを利用していない。現状それらのOSがどのような状況になっているか把握できていないのだ。従ってこの本では、インストールや実行確認作業を仮想OS環境上のLinux OSで進めていくことにする。

又、基本的な操作はApple社製のOSから実施している。万が一この本で使っているツールがマイクロソフト社製のOS向けに存在しない場合は、操作の目的に合ったツールに切り替え、操作を完結して欲しい。

=== 仮想OS環境を実現するソフト

===== VirtualBox:
@<href>{https://www.virtualbox.org/}

VirtualBoxは、x86仮想化ソフトウェア・パッケージの一つで、米国オラクル社によって開発がすすめられています。
サポートされているホストOSはLinux、Mac OSX、Windows、Solarisです。
ゲストOSとしては、FreeBSD、Linux、OpenBSD、OS/2 Warp、Windows、Mac OS X Server、Solarisなどx86/x64アーキテクチャのOSであれば基本的には起動できます。
GPL ver.2で公開されているFOSSなので、無料で使用することが出来ます。

=== 仮想OS環境で利用するLinux OS

===== Ubuntu 13.10:

server 64bit
@<href>{http://www.ubuntu.com/download/server}

Ubuntuは、Debian GNU/LinuxをベースとしたLinuxディストリビューションの1つです。Ubuntuは、「誰にでも使いやすい最新かつ安定したOS」を目標にカノニカル社から支援を受けて開発されています。毎年4月, 10月に更新版がリリースされ、LTS(長期メンテナンス)バージョンは2年に一度リリースされ、12.04が直近バージョンになります。


=== 仮想OS環境とProvision(自動設定)ソフトの間を取り持つソフト

===== Vagarant:
@<href>{http://www.vagrantup.com/}

Vagrantは、仮想OS環境を設定したり、設定後の仮想マシンのイメージを作成指定くれるオープンソースのソフトウェアです。VirtualBoxやVMwareなどの仮想OS環境とPuppet, Chef, Ansibleなどの構成管理ツールの間を取り持って、再現性の高い管理環境を提供してくれます。

又、仮想OSの起動,設定,SSH通信,マシンイメージ作成などをコマンドラインから操作することができ、開発者の操作性に高い操作性を提供しています。


=== 仮想OSをProvision(自動設定)するソフト

===== Ansible:
@<href>{https://github.com/ansible/ansible/}

Puppet, Chefと同等なProvisionソフト。Puppet, Chefと異なり、クライアントソフトをインストールすること無く、設定対象環境のProvision作業を進めることができる。設定内容は、yaml形式で記述されている。