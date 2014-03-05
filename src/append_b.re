= poiupoiuiopu

== lkjlkjlkjklajfkl;sj

== kljasdfkljasweoriwpoierw


====[column]

初回の起動時のみ下記のようなERRORメッセージが表示されます。

//cmd{
ERROR 2014/03/03 07:32:04 build.go:84: src/revelFramework4Go/sampleBlogSite/app/controllers/gorp.go:4:2: cannot find package "code.google.com/p/go.crypto/bcrypt" in any of:
  /usr/lib/go/src/pkg/code.google.com/p/go.crypto/bcrypt (from $GOROOT)
  /home/vagrant/gocode/src/code.google.com/p/go.crypto/bcrypt (from $GOPATH)
//}

このエラーメッセージは、パスワードの暗号化のために指定したbcryptのバイナリーがgocode/pkgディレクトリ以下に存在していないために、表示されています。

//cmd{
.
└── linux_amd64
    ├── code.google.com
    │   └── p
    │       └── go.net
//}

revelを実行した後に先のディレクトリを確認すると、"go.crypto"が生成されていることが確認できます。
次回以降はERRORメッセージが表示されること無くRevel web frameworkを起動することが出来るようになります。

//cmd{
└── linux_amd64
    ├── code.google.com
    │   └── p
    │       ├── go.crypto
    │       └── go.net
//}
