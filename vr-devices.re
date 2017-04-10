#@# VRコンテンツのつくりかた 技術書典2
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= VRデバイスの紹介

== 代表的なVRデバイス

ここでは、代表的な@<fn>{major-vr-device}VRデバイスを紹介します。いわゆるハイエンドに該当する3デバイスについてはその最大の特徴であるポジショントラッキングの特徴について前述済みのため、かんたんに済ませています。

//image[vr-hmd-photo][VRデバイスのヘッドマウントユニット][scale=1.00]{
//}

//footnote[major-vr-device][ここに載っていないデバイスは素人は避けたほうが無難です。もっと言うと、玄人が積極的に避けています。]

=== Google Cardboard

Google Cardboard@<fn>{google-cardboard}は、ダンボールにアクリル製レンズをはめ込んだGoogle製のVRデバイスです。初出はGoogle I/O 2014です。
開発元のGoogleが設計図を無償で公開したため、クローンが多数存在します。

Google CardboardはAndroidやiPhoneのスマートフォンを母艦とします。
レンズがはめ込まれた箱をViewerといいますが、このViewerで様々なサイズのスマートフォンをサポートすべく、レンズからスマートフォンのスクリーンまでの長さ、左右のレンズ間の長さ、レンズの歪み係数などの様々なパラメータを表現したProfileという概念をもっており、Profileを示すQRコードを生成できるサイト@<fn>{viewer-profile-generator}も公開されています。
Google VR SDKはこのProfileのQRコードを読み込んでViewerを設定できるUI・機能を持ち、設定されたProfileに応じた適切な左右の画面描画を行います。
Google Cardboard互換と思われるVRゴーグルにてQRコードが見当たらない場合は、自分で測定の上QRコードを生成して読み込みましょう。

全てのAndroid・iPhoneスマートフォンに対応していると思われがちですが、いわゆるローエンドのデバイスはジャイロセンサ非搭載のため非対応であったり、高解像度の動画のデコードやゲームアプリにてCGをリアルタイムレンダリングするGPUパワーが不足することとなり、2,3年以内に発売したミドルレンジ以上のデバイスでお楽しみください。

//footnote[google-cardboard][@<href>{https://vr.google.com/cardboard/}]
//footnote[viewer-profile-generator][Viewer Profile Generator @<href>{https://vr.google.com/cardboard/viewerprofilegenerator/}]

=== ハコスコ 一眼

ハコスコ 一眼@<fn>{hacosco}はハコスコ社製のダンボールとフレネルレンズで構成された、一眼の覗き込み箱です。
ハコスコ社は一眼のものの他、Cardboard v2クローンを含む二眼の製品も販売しており@<fn>{hacosco-product}、アプリ・プラットフォームは一眼・二眼両方をサポートしています。

ハコスコ 一眼の特徴はなんといっても立体視に関する脳の成長への影響や、顔そのものの大きさに起因するIPD調節機構の制限などから7歳や13歳といった視差あり二眼のVRデバイスのような年齢制限の必要がなく、全年齢に対応していることです。
ただし、ステレオではなくとも十分な没入感を得ることができるため、お子様の利用時にはまわりの方がよく気をつけてあげる必要があります。

//footnote[hacosco][@<href>{http://hacosco.com/}]
//footnote[hacosco-product][@<href>{http://hacosco.com/product/}]

=== Galaxy Gear VR

Galaxy Gear VR@<fn>{galaxy-gear-vr}は、Samsung製のVRデバイスです。
Oculusと共同開発でAndroidプラットフォームの制限を避けるべくヘッドマウントユニット側に専用のセンサを搭載し、高度な姿勢予測による、ハイエンドデバイスと同等の快適なヘッドトラッキングを実現します。
SamsungのGalaxyシリーズスマートフォンのみが母艦となる制限がありますが、2017年4月現時点で日本国内で発売されているモバイル向けVRプラットフォームとしては最も性能が良いものであり、Galaxyシリーズのスマートフォンをお持ちの方であれば買って損はない一品です。

また、Daydreamの登場で一つメリットが先行されていたコントローラについては、新型のGear VRで同等と思われるコントローラが同梱されること、そのコントローラに対応する70の新しいアプリが予定されていることが発表されました@<fn>{galaxy-gear-vr-controller}。

//footnote[galaxy-gear-vr][@<href>{http://www.samsung.com/jp/product/gearvr/}]
//footnote[galaxy-gear-vr-controller][Mobile VR Is Better than Ever @<href>{https://www.oculus.com/blog/mobile-vr-is-better-than-ever/}]

=== Daydream

Daydream@<fn>{google-daydream}は、Googleの新しいVRプラットフォームです。
Cardboardで全てのAndroidデバイスに高度なVR体験を提供することは難しいと考えたGoogleが、専用ビューワとコントローラ、スマートフォン母艦に高いチップ・センサ性能を要件とし、AndroidプラットフォームにVRのための専用の仕組みを搭載することを組み合わせ、Daydreamプラットフォームを作り上げました。

ビューワ部分はレンズさえ互換性があればCardboardと同等なこと、コントローラはハードウェアとしてはそれなりにシンプルなBLE HIDデバイスで、唯一強い縛りになると思われたチップ・センサ性能もどうやら2017年以降のAndroid 7.0 Nougat搭載フラッグシップ機であれば満たしており、世界一のスマートフォンシェアを誇るAndroidとGoogleパワーにより順調に広まっていきそうです。

ただし、残念ながら2017年4月現在日本国内で対応スマートフォンの発売は予定されておらず、ヘッドマウントユニット+コントローラのセットであるDaydream Viewも輸入する必要があります。
それでも、2017年3月頭から日本でもDaydreamストアアプリが正常に利用できるようになったことや、グローバルモデルではDaydream対応であろう新しいAndroidデバイスの国内発売の情報が出てきており、夏までには日本でも正式にDaydreamが楽しめるようになると期待しています。

ちなみにその性能ですが、ヘッドトラッキング性能についてはGear VRと概ね同等で、初めからコントローラありきのホーム・ストアアプリの融合の完成度が高い印象です。Googleフォト、Google StreetView、YouTubeとおなじみのアプリのVRバージョン、SKYBOX VR Player@<fn>{daydream-skybox-vr-player}による快適なローカル動画の再生と、ゲームを含めずともCardboardとは一線を画したVR体験を楽しむことができます。

Gear VRとの大きな違いはストアアプリがGoogle Playであること、AndroidアプリのapkのインストールにGear VRのように特別な署名が必要などの制限がないため、ストア外サードパーティapk配布の夢が（通常のAndroidアプリと同様に）あることです。

//footnote[google-daydream][@<href>{https://vr.google.com/daydream/}]
//footnote[daydream-skybox-vr-player][SKYBOX VR Player @<href>{https://play.google.com/store/apps/details?id=xyz.skybox.player&hl=ja}]

//image[vr-controller-photo][VRデバイスのコントローラ][scale=1.00]{
//}

=== Oculus Rift

Oculus Rift@<fn>{oculus-rift}は、Oculus社製のVRデバイスです。
手のさまざまな状態を入力することができるOculus Touchというコントローラがサポートされています。
RiftとTouchのセットで76,600円と値下げも行われて、ViveとPSVRの間にいろいろな意味ですっぽり定着した感があります。

//footnote[oculus-rift][@<href>{https://www.oculus.com/rift/}]

=== HTC Vive

HTC Vive@<fn>{htc-vive}は、HTC社製のVRデバイスです。
棒状のコントローラが付属する他、Vive Trackerというトラッキングしたいものに取り付けるオプショナルデバイスが先日購入できるようになりました。
単純にオリジナルデバイスをVR空間上に登場させる使い方の他、IKと組み合わせて安価なモーショントラッキングに使えることなどが期待されています。

//footnote[htc-vive][@<href>{https://www.vive.com/jp/}]

=== PlayStation VR

PlayStation VR@<fn>{playstation-vr}は、SIE社製のVRデバイスです。
コンシューマゲームハードであるPlayStation 4の付属品で、単体では動作しません。
これまであげてきたデバイスの中では唯一、開発機としては使えません。
メガネユーザでも抜群に装着しやすい構造とディスプレイの品質の高さが特徴です。
前述のLittlstarの他、サマーレッスンやRez Infiniteなど、PS4とPS4 Proでグラフィック品質の変わるタイトルもあり、ぜひ母艦としてはPS4 Proを用意したいところです。

//footnote[playstation-vr][@<href>{http://www.jp.playstation.com/psvr/}]

== 購入費用について

これまで上げてきたVRデバイス環境の購入費用について、母艦となるPCやスマートフォンもあわせてまとめると、以下のようになります。

 * Cardboard・ハコスコ：Android（5〜10万円）またはiPhone（8〜12万円） + Cardboard互換品/ハコスコ（1,000円〜5,000円）
 * Daydream：Android（6〜12万円） + Daydream View（10,000円）
 ** Pixel XLは高級品ですが、他のDadyream ready機が増えつつあります。Daydream Viewは$79ですが輸入する必要があります。
 * Gear VR：Galaxy（5万〜10万円） + Gear VR（10,000〜15,000円）
 ** 母艦として国内で型落ちのGalaxyを狙うとコスパフォがよくなります。
 * Oculus Rift：PC（GTX1050Ti, 8万円） + RiftとTouchセット（77,000円）
 * HTC Vive：PC（GTX1060, 10万円） + Vive（10万円）
 * PSVR：PS4 Pro（5万円） + PSVR Camera同梱版（5万円） + PSMove 2本（14,000円）

こう並べてみると分かりますが、トータルコストとして10〜20万円の枠できれいに並んでおり、肝心のコストパフォーマンスについては母艦となるPCやスマートフォン、PS4を別の目的でも利用するかどうかがポイントとなります。

