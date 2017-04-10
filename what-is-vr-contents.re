#@# VRコンテンツのつくりかた 技術書典2
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= VRコンテンツとは

== VRコンテンツの分類

さて、駆け足で視覚のRealityと現時点でのその再現技術について撫でてきましたが、VRコンテンツの話に入っていきましょう。

VRコンテンツは、姿勢に応じた視界の変化を予め描いておく「プリレンダリング」と、その都度描画する「リアルタイムレンダリング」の大きく2つに分けることができます。前者は「実写やCGの映像コンテンツ」後者は「ゲーム」に代表されますが、ハイブリッドも可能です。

 * プリレンダリング
 ** 実写
 ** CG
 * リアルタイムレンダリング
 ** ゲーム@<fn>{vr-game}
 ** プリレンダリングメディアとのハイブリッド

//footnote[vr-game][ゲームについては、「インタラクティブ性があり、ユーザの入力により結果が変化しうるコンテンツ」ぐらいの広い定義をイメージしてください。]

これらそれぞれに左右の目に同じ絵を見せるモノラルと、左右の目に視差を考慮した違う絵を見せるステレオのものがあります。
モノラルを2D、ステレオを3Dと表現することもあります。
ただし、"3D"はともかく"2D"は直感的とは言いがたく、聴覚に対する音声のモノラル/ステレオにあわせて視覚に対する画像の"モノラル"/"ステレオ"という表現が良いのでは、と考えています。
リアルタイムに左右の目に別の映像を用意することができるリアルタイムレンダリングのコンテンツでモノラルのものはあまりありませんが、プリレンダリングのコンテンツで、実写映像など、モノラルのコンテンツも数多く存在します。

圧倒的なPlayStation VRの知名度を考慮するに、ゲームがVR技術を代表するコンテンツとは言えそうですが、YouTube、GoogleフォトやFacebookなど、既存のサービスが360度メディアに対応していく流れを見るに、VRという特別な枠の中で分類ではなく、ゲーム・写真・映像などの既存メディア@<fn>{sound-media-vr}にVR技術を用いた要素が追加され、それぞれでRealityが増していく流れがある、と捉えるほうが良さそうな気がしています。

//footnote[sound-media-vr][本書では前述の通り、視覚を中心に取り上げていますが、バイノーラル技術を用いた音声コンテンツが大好きな筆者としてはSpatial Audio側の進化も楽しみにしており、ヘッドホンにスマートフォンを装着するとか、ジャイロ搭載ヘッドホンのメジャー化にも期待しています。]

== プリレンダリングのフォーマットについて

プリレンダリングのコンテンツは作り方の違いにより、実写とCGに分けられることは前述しましたが、静止画・動画メディアファイルとしての格納フォーマットは多岐に渡ります。
主には、世界地図でお馴染みの「球をどのように平面に投影するか」という投影（projection）の話と、あとはステレオのために左目用・右目用それぞれ別々のデータをどのように格納するかという話でフォーマットが決まります。

SamsungのGalaxy Gear VR向け動画再生アプリ、Samsung VRのFAQ@<fn>{samsung-vr-faq-url}に掲載されたフォーマット一覧の説明が、アニメーションGIFによる図解がわかりやすく、バリエーションも多く直感的にどんなものがあるか理解しやすいため、ここで紹介しておきます。

//image[samsung-vr-faq][Samsung VR FAQ][scale=0.90]{
//}

//footnote[samsung-vr-faq-url][Samsung VR FAQ @<href>{https://samsungvr.com/portal/content/faq_tech_gear_vr}]

=== Equirectangular（360度全天球）

//image[equirectangular-theta][モノラルEquirectangular画像例][scale=0.65]{
//}

投影方法としては正距円筒図法とも言われ、球の天頂と底の頂点を表面に沿って縦に割き、ぐいっと長方形になるように伸ばした開いたものです。
筆者の初遭遇はAndroid 4.2のPhoto Sphere@<fn>{android-42-photo-sphere}で、RICOH THETAが定着させていつのまにやらVR向けのフォーマットとしてもデファクトとなった印象です。

//footnote[android-42-photo-sphere][Photo Sphere, the new camera experience on Nexus 4 @<href>{https://www.youtube.com/watch?v=0poff-mHQ4Q}]

=== DomeMaster（円周魚眼180度半球）

//image[domemaster-sbs-mmdm][サイドバイサイドのステレオDomemaster画像例][scale=0.65]{
//}

円周魚眼の円形領域を四角に収めたもので、魚眼レンズによる撮影画像として、名称の通りプラネタリウムのようなドーム状に投影するためのフォーマットとして著名なものです。
半球ですので理論上はどの方向でも良いのですが、VRコンテンツとしては真正面を球の頂点とし、水平方向と鉛直方向の比が1:1の正方形のものがメジャーです。
これは、180度をカバーする魚眼レンズを、左右の目の幅だけ離して2つ並べたカメラで撮影すると、正面方向については完全に人間の視覚を再現するだけのステレオ映像として記録・再生することができるからです。

=== Cubemap

球を立方体に投影したもので、ファイルフォーマットとしては展開図の正面・後ろ・上・下・左・右の6面を横に直列した形式になっているものが多いです。
3DCGの環境マップやスカイマップではメジャーな方式ですが、自然界の極座標の変化に対して情報量の波ができるため、VRコンテンツのフォーマットとしては少しマイナーなものです。

=== フォーマットの向き不向き

YouTubeが360度動画としてブラウザでのドラッグによる2D上での操作、VR環境での天球描画にモノラル・ステレオ含め対応したことにより、Equirectangularがデファクトスタンダードのフォーマットとして定着した感があります。
しかし、Equirectangular例えば正面がコンテンツの中心であり、後方部分に情報の無いフォーマットでは残りの領域が無駄になってしまいます。
変化のない（例えば黒く塗りつぶされた）領域は動画のファイルサイズとしては影響がほぼありませんが、再生側でデコードしてVRAMへ転送して…といった際には解像度はしっかり限界に影響してしまいます。

このあたり、現時点でフラッグシップのスマートフォンであっても4Kの3840x2160の60FPSがハードウェア側の限界であり（ディスプレイが4Kに満たないのですからそれ以上のデコード能力が不要なのは当然です）、たとえば4KのEquirectangular（縦横比2:1）のステレオでは3840x1920x2、Top-Bottomの上下配置とすると、動画の解像度は3840x3840となります。
このサイズを60FPS再生は厳しく、30FPSで再生できてればかなり出来の良い（柔軟に処理をがんばっている）モバイルデバイスだと考えてください。

そこで、この解像度の限界をどうにか避けるべく、前方にのみ情報が集中するコンテンツはEquirectangularでの360度ではなく、前方180度の半球を左右に並べた180度サイドバイサイドの[◯][◯]のようなフォーマットが現在一時的に主流になりつつあります。

これらのいわゆる「VR動画」についても2016年は元年と言える花開いた年でした。
まだまだIPD（瞳孔間距離）を考慮した適切な視差の追求や、十分な解像度の確保ができていない@<fn>{youtube-vr-japan}ものが多い印象ですが、徐々に世間のニーズが高解像度のステレオ動画に収束しつつある印象です。
Insta360 Pro@<fn>{insta360-pro}が非常に楽しみです。

//footnote[youtube-vr-japan][近距離でまったく像を結べなくなる広すぎるIPDや、THETAソースから劣化ありで加工しているような低解像度の動画をビジネス目的でYouTubeにアップロードしている方々は、高品質の4Kステレオをガンガン放り込んでくるお隣の国を早く見習ってほしいものです…]
//footnote[insta360-pro][Insta360 Pro @<href>{https://www.insta360.com/product/insta360-pro}。ちなみに筆者はInsta360 Proは高価すぎて躊躇したため、TwoEyes VR @<href>{https://www.kickstarter.com/projects/244975696/twoeyes-vr-360-camera}に期待しています。]

== PSVRでのVR動画再生とLittlstar

さて、先ほど2016年VR元年の3大VRデバイスとして紹介したPlayStation VRですが、いわゆる「VR動画」の再生プラットフォームとしてはかなり厳しいものでした。そこにLittlstarという素晴らしいアプリが登場して2017年3月、全てを解決した話をご紹介します。

 * 2016.10 PSVR発売：PS4のもともとの動画再生能力であるProfile 4.2（2048x1080）にひきずられ、モノラルフルHDのEquirectangularまで再生に対応、ステレオ再生非対応。
 * 2016.11 PS4Pro発売：変化なし。
 * 2017.01 YouTubeアプリがバージョンアップ@<fn>{psvr-youtube-verup}：「バーチャルリアリティ動画(3Dの360度動画)」の視聴に対応。
 * 2017.03 360度動画コンテンツ配信プラットフォームLittlstarのアプリがローカルコンテンツのサイドロード再生に対応@<fn>{psvr-littlstar-update-sideload}：3Kクラスの180度/360度ステレオ動画の再生が可能に。
 * 2017.03 PS4Proのメディアプレイヤーで4K動画の再生に対応：ただしステレオに非対応、Littlstarに届かず。

//footnote[psvr-youtube-verup][PS VRでYouTubeの360度動画視聴が可能に！ PS4®『YouTube』バージョン1.10アップデート、配信開始！ @<href>{https://www.jp.playstation.com/blog/detail/4406/20170120-psvr.html}]
//footnote[psvr-littlstar-update-sideload][Side Loading Now Available on the PS VR App @<href>{https://medium.com/@littlstarmedia/side-loading-now-available-on-the-ps-vr-app-fe362f6c3e94}]

360度パノラマ映像などのVRコンテンツを体験できるプラットフォームLittlstar（リトルスター）がLittlstar VR CinemaというPSVR向けアプリ@<fn>{littlstar-psvr}を提供@<fn>{littlstar-psstore}しており、これがアップデートでサイドロードという、USBメモリ等経由でのローカルコンテンツ再生に対応しました。

主にはアダルト界隈が盛り上がっていおりますが、自前でのコンテンツ生成組にもかなり嬉しい話で、2017年には前述の通り種々のハードウェアリリースなどに押されて、全天球ステレオ動画のCGM化が進むと考えており、良いタイミングで出てくれてありがたい話です。

動画フォーマットやファイルパス・ファイル命名規則がそれなりに細かい@<fn>{littlstar-doc-sideloading}ので注意してください。
また、GPUを利用したソフトウェアデコードと思われますが、PS4無印とPS4 Proで快適に再生できる解像度が大きく違うことに注意してください。
筆者がPS4Pro + PSVR環境で試した限りでは、以下の通りの印象です。

 * H.264エンコーダ：x264で目標ビットレートに14-16Mbpsあたりを設定
 * ビットレート：15Mbps程度が上限、カタログスペックの20Mbpsは相当オプションに気を使う必要がありそう
 * 360度ステレオEquirectangular：Top-Bottomで2560x1280x2の2560x2560あたりが上限
 * 180度ステレオ前方天球Side-by-Side：1600x1600x2の3200x1600あたりが上限
 * 動画を投影した球の中でカメラの位置が移動する擬似ポジトラが実現されており、動画との相性がよければ没入感に貢献する

//footnote[littlstar-psvr][LITTLSTAR.COM - PSVR @<href>{http://littlstar.info/psvr/#psvr-content}]
//footnote[littlstar-psstore][PlayStation - Store Littlstar VR Cinema @<href>{https://store.playstation.com/#!/cid=UP8821-CUSA06120_00-JPPS400000000001}]
//footnote[littlstar-doc-sideloading][PlayStation VR Video Sideloading @<href>{http://docs.littlstar.com/display/CG/PlayStation+VR+Video+Sideloading}]

== プリレンダとリアルタイムのハイブリッド

プリレンダリングメディア同士をインタラクティブなネイティブのUIで繋いだハイブリッドと呼べるものが最近、定着してきました。
複数のメディアを有機的に繋ぐことができるバーチャルツアー機能・タグ機能を追加したハコスコ@<fn>{hacosco-virtualtour}やインフィニットループのGrooon@<fn>{infiniteloop-grooon}、静止画・動画素材を元にブラウザ向けWebVRや個別のネイティブアプリなど、複数のプラットフォーム向けにブラウザ上からコンテンツを作成できるInstaVR@<fn>{instavr}などで提供されるものがこれに該当します。

//footnote[hacosco-virtualtour][ハコスコアプリにバーチャルツアー機能・タグ機能を追加 @<href>{https://hacosco.com/2016/09/virtualtour/}]
//footnote[instavr][InstaVR @<href>{http://jp.instavr.co/}]
//footnote[infiniteloop-grooon][Grooon @<href>{https://www.infiniteloop.co.jp/blog/2017/04/grooon-release/}]

このようなハイブリッドは、現行先行しているプラットフォームが基本的な部分は概ね完成させており、方式としてはすぐに習熟を迎えると思っています。
そして、この流れのもう少し先を見ると、2017年はWebVRにてネイティブ部分を排除した、「ブラウザ内完結」が始まるのではないでしょうか。

2016年末から、Gear VR専用ブラウザSamsung Internet@<fn>{samsung-internet}のWebVRの対応、Oculus開発のCarmelブラウザ@<fn>{oculus-carmel}の発表とGear VR向け開発者版プレビューのリリース、Chrome for AndroidがDaydream向けにWebVR対応と、（Cardboardより一つ上の）高品質なスマートフォンモバイルVR環境に次々とWebVRの正式対応の波がやってきています。
スタンドアロンのヘッドマウントユニットを装着したまま、追加でアプリをインストールすることなく、さまざまなVRコンテンツを渡り歩いて体験することができる世界が今年はやってきます（やっていきましょう）。

//footnote[samsung-internet][Samsung Internet @<href>{https://www.oculus.com/experiences/gear-vr/849609821813454/}]
//footnote[oculus-carmel][Carmel Developer Preview Launches Today @<href>{https://developer.oculus.com/blog/carmel-developer-preview-launches-today/}]
//footnote[chrome-daydream][Experience Virtual Reality on the web with Chrome @<href>{https://blog.google/products/chrome/experience-virtual-reality-web-chrome/}]

そして「ヘッドマウントユニットを装着したまま」という観点ではつい先日、Gear VRの体験をFacebookにライブストリーミングできるようになりました@<fn>{gearvr-facebook-livestreaming}が、個人的にはニーズを満たすにはこれでは不十分で「ゲーム画面をせいぜい一時停止するぐらいでFacebookのタイムラインを確認する」とか、「斜め下を向いたらTwitterのタイムラインのビューが合成されており、シームレスに閲覧することができる」とか、今楽しんでいるVR体験とは直接関係のないソーシャルタスクの並列実行環境が必要だと思っています。

VRゲームとブラウジングとTwitterをヘッドマウントユニットを外すことなく同時にやりたいのです。

//footnote[gearvr-facebook-livestreaming][Introducing Rooms 1.2 and Oculus Events for Gear VR @<href>{https://t.co/WVjKJmS7xr}]



