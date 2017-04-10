#@# VRコンテンツのつくりかた 技術書典2
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= はじめに

（n度目の）VR元年である2016年が過ぎ去って2年目、どちらかというとxR元年という2017年をお過ごしのみなさま、いかがおすごしでしょうか。筆者のyoutenと申します。
本書は、以下のような方をターゲットにしています。

 * 最新のVR状況についてざっと抑えたい
 * VRコンテンツがどのように作られているか知りたい
 * VRコンテンツを実際に作ってみたい

前半はVRそのものやVRデバイスやVRコンテンツの分類について、後半は具体的なVRコンテンツの作り方を掲載しています。

== 賞味期限とリポジトリ公開について

なお、本書は記載内容の賞味期限が切れてしまうことへのアップデート対応、あまり紙メディアが向いていないスクリーンショットが多くなりがちな開発環境の構築手順の追加を含め、初版以降のPDFと関連ファイル一式を全て以下のリポジトリで公開しております。
あらかじめご了承ください。

 * @<href>{https://github.com/youten/howto-create-vr-contents}
 ** Re:VIEWの素材一式、出力PDF、関連プロジェクトのソースコードを全て含む想定です。
 ** Android, Unity等の開発環境の構築手順についても、順次作成の上同リポジトリで公開したいと考えています。

本書のうち、私youtenが著作権を有する範囲のライセンスについては、文章はCC-BY 4.0@<fn>{cc-by-4}、ソースコードについてはApache License v2@<fn>{apache-license-v2}を適用します。

本書籍はRe:VIEWで作成されており、その設定ファイル等について、MITライセンス@<fn>{mit-license}に基づき「C89 初めてのRe:VIEW v2」リポジトリ@<fn>{techbooster-c89-review-v2}で公開されているものを利用させていただいております。

表紙他、ImagineVRのIrisモデルをIris ImagineGirlsユーザーライセンス(IGUL)に基づき利用させていただいております。

//image[imaginegirls-igul][ImagineGirlsユーザーライセンス(IGUL)][scale=0.50]{
//}

//footnote[mit-license][@<href>{https://opensource.org/licenses/MIT}]
//footnote[techbooster-c89-review-v2][@<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2}]
//footnote[imaginegirls][@<href>{http://imaginegirls.com/imaginegirls_user_license_jp/}]
//footnote[cc-by-4][@<href>{https://creativecommons.org/licenses/by/4.0/legalcode.ja}]
//footnote[apache-license-v2][@<href>{http://www.apache.org/licenses/LICENSE-2.0}]

