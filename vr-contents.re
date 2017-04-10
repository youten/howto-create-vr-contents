#@# VRコンテンツ開発入門
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
また、表紙他、ImagineVRのIrisモデルをIris ImagineGirlsユーザーライセンス(IGUL)に基づき利用させていただいております。

//image[imaginegirls-igul][ImagineGirlsユーザーライセンス(IGUL)][scale=0.50]{
//}

//footnote[imaginegirls][@<href>{http://imaginegirls.com/imaginegirls_user_license_jp/}]
//footnote[cc-by-4][@<href>{https://creativecommons.org/licenses/by/4.0/legalcode.ja}]
//footnote[apache-license-v2][@<href>{http://www.apache.org/licenses/LICENSE-2.0}]

= 2016年のVRについて

== VRと視覚のリアリティ

最初に、学術的にも、文化的にも、昨今のムーヴメントのみを切り取っても、いろいろな考え方ができるVR（Virtual Realityの略、ヴァーチャルリアリティ）というものについて、最初に「ぼくの考える昨今のVRについて」述べておくことにより、本書で扱うVRについて定義しておきたいと思います。

Virtual Realityとは、直訳では「仮想の、事実上の現実感」です。広義には実際に実物がそこにあるかのように人間に感じさせる技術全般を意味します。その技術体系は人間の五感に即して分類することができます。

例えば、聴覚で言えばそもそも蓄音機に始まった「録音し、再生する」ことそのものは、あたかもその人がそこで喋っているように、ある演奏が目の前で行われているかのように感じさせるVR技術そのものです。
普及して日常生活となった「イヤホンやヘッドホン、スピーカーセットなどでステレオの音楽を聴く」という行為は、モノラルの音声と比較してよりRealityを再現したVRと言えると思います。

例として聴覚を挙げましたが、テレビやビデオ、化学調味料とインスタント食品、ゲームのバイブレーションなど、他の視覚・嗅覚・味覚・触覚についても、それぞれRealityを記録・再生・伝達する基礎技術があって、組み合わせると高い現実感を生み出せることを、みなさんはすでに日常生活で体験していると思います。

8割とか9割とか言われていますが、人間は外界の情報を主に視覚から得ており、昨今のVRムーヴメントは、この視覚の現実感の再現が以下のように、技術的にとても高いレベルで、しかもそれなりの低コストでできるようになったことをトリガとして始まっています。

 * 3D CG技術の進歩によって発達した、適切な立体感を生み出す、左右の目への別の映像の表示
 * スマートフォンの普及によって安価になったジャイロ、高い応答性能を持つ高解像度・高ピクセル密度ディスプレイと、それを扱う姿勢予測プログラムなどが深く連携した高いリフレッシュレートと応答速度によって実現される、頭の振りに追従した映像の切り替え
 * 高度なレンズ工作技術による広い視野角の確保と、Oculus Rift DK1によって確立された、ディスプレイに表示する映像を予めレンズにあわせて樽型に歪めておくことによる自然な見え方の実現

少しまわりくどい書き方になってしまいましたが、噛み砕くと以下の通りです。

 * 遠くのものが遠くに、近くのものが近くに見える
 * 顔を向けたら向いた方向のものが見える
 * 広い範囲が自然に見える

これらの視覚のリアリティについて、まだ現実世界とはいくらかのギャップが残っていますが、それを埋めるいくつかの技術検討は進められており、さらに20年を待つことなく、5年程度でもう一段階上のレベルに到達することが期待できる話を少ししておきます。

レンズで拡大してしまっていることもあり、StarVR@<fn>{starvr}の5Kでもまだ十分ではないと言われる解像度については、その網目感についてはPSVRの開口率の高い液晶で解像度にたよらず解決されています。スマートフォン向けにもWQHDから4Kの世界が見え始めており、高解像度化・低コスト化が期待できます。ジャパンディスプレイはVR向けに高解像度・高リフレッシュレート・高応答速度を兼ね備えた液晶を開発、サンプル出荷したと発表しました@<fn>{jdi-vr-display}。

VR HMD（ヘッドマウントディスプレイ）内での視線検出は、先駆けとしてFOVEが先日出荷されましたが、Viveの開発元であるHTCがSMIと提携して取り組んでおり@<fn>{htc-smi-eye-tracking}、先日のGDC2017ではViveに組み込んだプロトタイプのデモが展示され@<fn>{htc-smi-gdc-vive-demo}、その技術はSteamが公開しているOpenVRにも対応予定であることが発表されています。
光学的機構の制限もあり、現行のVR HMDでいわゆる「横目」をした際に見えづらい問題が完全に解決するわけではないのですが、人間が視線を向けた中央部分と比べて、周辺部の解像認識はぼけていることを利用して、視線の向いた部分のみ高解像度にするフォービエイティッド・レンダリングにより、今後の4K超え解像度・リフレッシュレート120Hz時代のうなぎのぼりに要求されるグラフィックパフォーマンスを下支えしてくれることでしょう。

//footnote[starvr][@<href>{http://www.starvr.com/}]
//footnote[jdi-vr-display][VR専用の超高精細・高速応答　液晶ディスプレイの開発 @<href>{http://www.j-display.com/news/2016/20161121.html}]
//footnote[htc-smi-eye-tracking][SMI Launches HTC Vive with High Performance Eye Tracking @<href>{https://www.smivision.com/news/smi-launches-htc-vive-with-high-performance-eye-tracking/}]
//footnote[htc-smi-gdc-vive-demo][GDC 2017: SMI Eye Tracking in an HTC Vive @<href>{https://www.youtube.com/watch?v=HtU-Y9g6Trw}]

== 2016年のVR

ここまでで、視覚に関するここ2,3年のVR技術特徴について大雑把に紹介しました。続けて、直近1年間、2016年の話を少し振り返っておきます。

さきほど、「頭の振りに追従した映像の切り替え」と記載しましたが、この頭の向きだけの追従をヘッドトラッキングといいます。
現実世界では左右や前後に移動した分だけ映像も左右にずれたり、近づいたり遠ざかったりしますが、この「頭の移動に追従した映像の切り替え」をポジショントラッキングといい、これに高度に対応したデバイスが2016年、市販が開始されました。

その代表と言える3つのデバイスと、ポジショントラッキングの方式と特徴について、以下におおかまに説明します。

 * 2016年3月28日 Oculus Rift発売
 ** ヘッドマウントユニット・コントローラに赤外線LEDを搭載、周囲にカメラセンサを配置し読み取るOutside-In方式。
 ** 複数のカメラに対応し、3つの配置で概ねルームスケールを実現。センサが前方2つのみの際にはヘッドマウントユニット上のLED配置上、少し後ろ振り向きに弱い。
 * 2016年4月5日 HTC Vive発売
 ** ヘッドマウントユニット・コントローラに赤外線センサを搭載、周囲に配置したユニットから赤外線レーザーを照射し読み取らせる。"LightHouse"という名前がついている。
 ** 対角線上に配置した2機のレーザー照射ユニットで最大4.5m x 4.5mと広くルームスケール@<fn>{room-scale}を実現。原理上、他のViveセットの隣接配備によるレーザー混線に弱い。レーザーを吸収する黒い布壁でがんばる。
 * 2016年10月13日 PlayStation VR発売
 ** ヘッドマウントユニット・コントローラにカラーLEDを搭載、RGBステレオカメラによる読み取りにより位置を測定する。PS Move + PS Cameraとその技術を流用しており、他2つに比べ機構上トラッキング範囲は狭く、光源サイズの大きさにひきずられた低い精度をジャイロで補正しており、それなりに発生するドリフトに対しては必死に手元でのカメラリセット操作により人力補正が必要であり、また、外界の照明環境の影響がかなり大きい。

設置環境やコンテンツに依存しますし、主観ではあるのですがポジショントラッキングについてまとめると、以下の通りです。

 * Oculus Riftは立ったりステップしたりできる
 * HTC Viveは歩き回れる
 * PSVRは座って首が自由に振れる

//footnote[room-scale][部屋内を自由に歩き回れる、の意。Viveの"LightHouse"が実現したものとしての表現されたことが初出、今ではViveに限定せずVR用語として定着。]

また、個人的には2016年の大事な出来事として、Oculus RiftのAsynchronous Spacewarp@<fn>{asynchronous-spacewarp}対応を挙げたいと思います。
これは90FPSでの描画が間に合わなかった際に、半分の45FPSの描画結果から間のフレームを補完する技術で、1フレームを描画するのにかけられる時間に大きく効いてきます。

 * 90FPSを維持しなくてはいけない
 ** 1/90 = 0.011...
 ** 1枚11ms以下で描かないといけない
 * 45FPSも許容される
 ** 1/45 = 0.022...
 ** たまに遅れても1枚22ms以下で描ければいい

1msを1日と考えると、「11日後の納期必達」だったのが突然「22日以内に納品すればいい」になったような話です。これにより、Oculus Riftは動作スペック要件を引き下げることに成功しました。
前述のフォービエイティッドレンダリングや、GTX 1080 TiがGTX 1080より35%速い@<fn>{gtx-1080-ti}話などを考えると、世界はもう一段階上のVR体験にいい感じに向かっているのでは、と期待できませんか。

//footnote[asynchronous-spacewarp][@<href>{https://developer.oculus.com/blog/asynchronous-spacewarp/}]
//footnote[gtx-1080-ti][NVIDIA、圧倒的な GeForce GTX 1080 Ti を発表、これまでで最速のゲーミング GPU @<href>{http://www.nvidia.co.jp/object/geforce-gtx-1080-ti-fastest-gaming-gpu-20170303-jp.html}]

= VRコンテンツについて

== VRコンテンツの分類

さて、駆け足で視覚のRealityと現在までのその再現技術について撫でてきましたが、VRコンテンツの話に入っていきましょう。

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
ただし、"3D"はともかく"2D"は直感的とは言いがたく、聴覚に対する音声のモノラル/ステレオにあわせて視覚に対する画像のモノラル/ステレオという表現が良いのでは、と考えています。
リアルタイムに左右の目に別の映像を用意することができるリアルタイムレンダリングのコンテンツでモノラルのものはあまりありませんが、プリレンダリングのコンテンツで、実写映像など、モノラルのコンテンツも数多く存在します。

圧倒的なPlayStation VRの知名度を考慮するに、ゲームがVR技術を代表するコンテンツとは言えそうですが、YouTube、GoogleフォトやFacebookなど、既存のサービスが360度メディアに対応していく流れを見るに、VRという特別な枠の中で分類ではなく、ゲーム・写真・映像などの既存メディア@<fn>{sound-media-vr}にVR技術を用いた要素が追加され、それぞれでRealityが増していく流れがある、と捉えるほうが良さそうな気がしています。

//footnote[sound-media-vr][本書では前述の通り、視覚を中心に取り上げていますが、バイノーラル技術を用いた音声コンテンツが大好きな筆者としてはSpatial Audio側の進化も楽しみにしており、ヘッドホンにスマートフォンを装着するとか、ジャイロ搭載ヘッドホンのメジャー化にも期待しています。]

== プリレンダリングのフォーマットについて

プリレンダリングのコンテンツは作り方の違いにより、実写とCGに分けられることは前述しましたが、静止画・動画メディアファイルとしての格納フォーマットは多岐に渡ります。
主には、世界地図でお馴染みの「球をどのように平面に投影するか」という投影（projection）の話と、あとはステレオのために左右の目のためのデータをどのように格納するかという話でフォーマットが決まります。

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

円周魚眼の円形画像を四角に収めたもので、魚眼レンズによる撮影画像として、名称の通りプラネタリウムのようなドーム状に投影するためのフォーマットとして著名なものです。半球ですので理論上はどの方向でも良いのですが、VRコンテンツとしては真正面を球の頂点とし、水平方向と鉛直方向の比が1:1の正方形のものがメジャーです。
これは、180度をカバーする魚眼レンズを、左右の目の幅だけ離して2つ並べたカメラで撮影すると、正面方向については完全に人間の視覚を再現するだけのステレオ映像として記録・再生することができるからです。

=== Cubemap

球を立方体に投影したもので、ファイルフォーマットとしては展開図の正面・後ろ・上・下・左・右の6面を横に直列した形式になっているものが多いです。3DCGの環境マップやスカイマップではメジャーな方式ですが、自然界の極座標の変化に対して情報量の波ができるため、VRコンテンツとしてはあまり採用されていません。

=== フォーマットの向き不向き

YouTubeが360度動画としてブラウザでのドラッグによる2D上での操作、VR環境での天球描画にモノラル・ステレオ含め対応したことにより、Equirectangularがデファクトスタンダードのフォーマットとして定着した感がありますが、正面がコンテンツの中心であり後方部分に情報の無いフォーマットでは残りの領域は無駄になってしまいます。変化のない（例えば黒く塗りつぶされた）領域は動画のファイルサイズとしては影響がほぼありませんが、再生側でデコードしてVRAMへ転送して…といった際には解像度はしっかり限界に影響してしまいます。

現時点でフラッグシップのスマートフォンであっても4Kの3840x2160の60FPSがハードウェア側の限界であり（ディスプレイが4Kに満たないのですからそれ以上のデコード能力が不要なのは当然です）、たとえば4KのEquirectangular（縦横比2:1）のステレオでは3840x1920x2、Top-Bottomの上下配置とすると、動画の解像度は3840x3840となります。このサイズを60FPS再生は厳しく、30FPSで再生できてればかなり出来の良い（柔軟に処理をがんばっている）モバイルデバイスだと考えてください。

そこで、この解像度の限界をどうにか避けるべく、前方にのみ情報が集中するコンテンツはEquirectangularでの360度ではなく、前方180度の半球を左右に並べた180度サイドバイサイドの[○][○]ようなフォーマットが現在一時的に主流になりつつあります。

これらのいわゆる「VR動画」についても2016年は元年と言える花開いた年でした。
まだまだIPD（瞳孔間距離）を考慮した適切な視差の追求や、十分な解像度の確保ができていない@<fn>{youtube-vr-japan}ものが多い印象ですが、徐々に世間要望が高解像度のステレオ動画に収束しつつある印象です。Insta360 Pro@<fn>{insta360-pro}が楽しみです。

//footnote[youtube-vr-japan][近距離でまったく像を結べなくなる広すぎるIPDや、THETAソースから劣化ありで加工しているような低解像度の動画をビジネス目的でYouTubeにアップロードしている方々は、高品質の4Kステレオをガンガン放り込んでくるお隣の国を早く見習ってほしいものです…]
//footnote[insta360-pro][Insta360 Pro @<href>{https://www.insta360.com/product/insta360-pro}。ちなみに筆者はInsta360 Proは高価すぎて躊躇したため、TwoEyes VR @<href>{https://www.kickstarter.com/projects/244975696/twoeyes-vr-360-camera}に期待しています。]

== PSVRでのVR動画再生とLittlstar

さて、先ほど2016年VR元年の3大VRデバイスとして紹介したPSVRですが、いわゆる「VR動画」の再生プラットフォームとしてはかなり厳しいものでした。そこにLittlstarという素晴らしいアプリが登場して2017年3月、全てを解決した話をご紹介します。

 * 2016.10 PSVR発売：PS4のもともとの動画再生能力であるProfile 4.2（2048x1080）にひきずられ、モノラルフルHDのEquirectangularまで再生に対応、ステレオ再生非対応。
 * 2016.11 PS4Pro発売：変化なし。
 * 2017.01 YouTubeアプリがバージョンアップ@<fn>{psvr-youtube-verup}：「バーチャルリアリティ動画(3Dの360度動画)」の視聴に対応。
 * 2017.03 360度動画コンテンツ配信プラットフォームLittlstarのアプリがローカルコンテンツのサイドロード再生に対応@<fn>{psvr-littlstar-update-sideload}：3Kクラスの180度/360度ステレオ動画の再生が可能に。
 * 2017.03 PS4Proのメディアプレイヤーで4K動画の再生に対応：ただしステレオに非対応、Littlstarに届かず。

//footnote[psvr-youtube-verup][PS VRでYouTubeの360度動画視聴が可能に！ PS4®『YouTube』バージョン1.10アップデート、配信開始！ @<href>{https://www.jp.playstation.com/blog/detail/4406/20170120-psvr.html}]
//footnote[psvr-littlstar-update-sideload][Side Loading Now Available on the PS VR App @<href>{https://medium.com/@littlstarmedia/side-loading-now-available-on-the-ps-vr-app-fe362f6c3e94}]

360度パノラマ映像などのVRコンテンツを体験できるプラットフォームLittlstar（リトルスター）がLittlstar VR CinemaというPSVR向けアプリ@<fn>{littlstar-psvr}を提供@<fn>{littlstar-psstore}しており、これがアップデートでサイドロードという、USBメモリ等経由でのローカルコンテンツ再生に対応しました。

主にはアダルト界隈が盛り上がっていおりますが、自前でコンテンツ生成組にもかなり嬉しい話で、2017年には前述の通り種々のハードウェアリリースなどに押されて、全天球ステレオ動画のCGM化が進むと考えており、良いタイミングで出てくれてありがたい話です。

動画フォーマットやファイルパス・ファイル命名規則がそれなりに細かい@<fn>{littlstar-doc-sideloading}ので注意してください。また、GPUを利用したソフトウェアデコードと思われますが、PS4無印とPS4 Proで快適に再生できる解像度が大きく違うことに注意してください。筆者がPS4Pro + PSVR環境で試した限りでは、以下の通りの印象です。

 * H.264エンコーダ：x264で目標ビットレートに14-16Mbpsあたりを設定
 * ビットレート：15Mbps程度が上限、20Mbpsは相当オプションに気を使う必要がありそう
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

そして「ヘッドマウントユニットを装着したまま」という観点ではつい先日、Gear VRの体験をFacebookにライブストリーミングできるようになりました@<fn>{gearvr-facebook-livestreaming}が、個人的には世間要望を満たすにはこれでは不十分で「ゲーム画面をせいぜい一時停止するぐらいでFacebookのタイムラインを確認する」とか、「斜め下を向いたらTwitterのタイムラインのビューが合成されており、シームレスに閲覧することができる」とか、今楽しんでいるVR体験とは直接関係のないソーシャルタスクの並列実行環境が必要だと思っています。

VRゲームとブラウジングとTwitterをヘッドマウントユニットを外すことなく同時にやりたいのです。

//footnote[gearvr-facebook-livestreaming][Introducing Rooms 1.2 and Oculus Events for Gear VR @<href>{https://t.co/WVjKJmS7xr}]

= VRデバイスの紹介

== 代表的なVRデバイス

ここでは、代表的な@<fn>{major-vr-device}VRデバイスを紹介します。いわゆるハイエンドに該当する3デバイスについてはポジショントラッキングについて前述済みのため、かんたんに済ませています。

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

全てのAndroid・iPhoneスマートフォンに対応していると思われがちですが、いわゆるローエンドのデバイスはジャイロセンサ非搭載のため非対応であったり、高解像度の動画のデコードやゲームアプリにてCGをリアルタイムレンダリングするGPUパワーが不足することとなり、2,3年以内に発売したミドルレンジ以上のスペック向けとお考えください。

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

Gear VRとの大きな違いはストアアプリがGoogle Playであること、Androidアプリのapkのインストールに特別な署名が要らないため、ストア外サードパーティapk配布の夢が（通常のAndroidアプリと同様に）あることです。

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
 * Daydream：Android（5〜12万円） + Daydream View（10,000円）
 ** Pixel XLは高級品ですが、他にもDadyream ready機が増えつつあること、Daydream Viewは$79ですが輸入する必要があります。
 * Gear VR：Galaxy（5万〜10万円） + Gear VR（10,000〜15,000円）
 ** 母艦として国内で型落ちのGalaxyを狙うとコスパフォがよくなります。
 * Oculus Rift：PC（GTX1050Ti, 8万円） + RiftとTouchセット（77,000円）
 * HTC Vive：PC（GTX1060, 10万円） + Vive（10万円）
 * PSVR：PS4 Pro（5万円） + PSVR Camera同梱（5万円） + PSMove 2本（14,000円）

こう並べてみると分かりますが、トータルコストとして10〜20万円の枠できれいに並んでおり、肝心のコストパフォーマンスについては母艦となるPCやスマートフォン、PS4を別の目的でも利用するかどうかがポイントとなります。

= VRコンテンツの作り方

== 全天球写真の撮影と閲覧

=== THETAとその仲間について

THETA@<fn>{ricoh-theta}はRICOH社のカメラで、コンパクトな棒状のユニットの表裏に魚眼レンズを搭載し、ワンショットで360度全天球の動画・静止画が撮れるものです。
スマートフォンとの連携アプリも出来が良く、USBやHDMIストリーミング、WiFi経由でのAPIなど関連したシステムを開発するためのIFも揃っており、なおかつコストパフォーマンスに優れた、この分野を楽しむ際にはマストバイの一品です。
母艦としてのスマートフォンの必要有無などの差もありますが、Samsung社のGear 360@<fn>{samsung-gear-360}やInsta360@<fn>{insta360-nano-air}のInsta Nano/Air、マスプロ電工社のKodak PIXPRO SP360シリーズ@<fn>{kodak-pixpro-sp360}やGoProも含めて全天球写真の撮れるカメラはラインナップが充実しつつあり、また、自分自身がぐるぐる回る必要がありますがCardboardカメラ@<fn>{cardboard-camera}など、スマートフォン単体でもアプリにて撮影が可能です。

//footnote[ricoh-theta][@<href>{https://theta360.com/ja/}]
//footnote[samsung-gear-360][@<href>{http://www.samsung.com/jp/consumer/mobilephone/gear/gear/SM-C200NZWAXJP}]
//footnote[insta360-nano-air][@<href>{https://www.insta360.com/}]
//footnote[kodak-pixpro-sp360][@<href>{http://www.maspro.co.jp/products/pixpro/about-sp360/}]
//footnote[cardboard-camera][@<href>{https://play.google.com/store/apps/details?id=com.google.vr.cyclops&hl=ja}]

=== Googleフォトとメタデータ

さて、全天球写真・映像が徐々に身近なものになりつつありますが、これを楽しむメディア管理方法として、Googleフォトをオススメしておきます。

 * スマートデバイスからの自動バックアップ・アップロードに対応
 * アルバム・個別のきめ細かな単位での共有公開が可能
 * PC・モバイルブラウザには専用のビューが提供され、さらにDaydreamでは全天球コンテンツのみを快適に閲覧が可能

//image[google-photo-uwaoka][GoogleフォトでのTHETA画像閲覧][scale=1.00]{
//}

//image[daydream-google-photo][DaydreamでのGoogleフォト画像閲覧][scale=1.00]{
//}

具体的にどのような表示となるかについて、Googleフォトで旧上岡小学校の写真を共有公開しています@<fn>{google-photo-uwaoka}のでよければそちらを確認願います。

//footnote[google-photo-uwaoka][@<href>{https://goo.gl/photos/yzNVv6GGz7xUMWgn9}]

さて、THETA等で撮影した写真を直接Googleフォトにアップロードする際には問題がないのですが、ぼかし加工や写真ではなくCGでの生成後にGoogleフォトにアップロードする際には、全天球画像であることを表すメタデータを付与する必要がありますので、これについても述べておきます。

正式にはGoogleストリートビューガイドのPhoto Sphere XMP メタデータ@<fn>{google-streetview-guide-metadata}を参照ください。
PanoTwinsで紹介されている@<fn>{panotwins-photosphere}通り、メタデータを付与する手段はいくつかありますが、ツールのバージョン相性などがあり、ExifTool@<fn>{exiftool}のバイナリをダウンロードし、コマンドラインバッチとして起動する方法で筆者は成功しました。
以下、exeを動作させるbatファイル@<list>{exiftool-photosphere-bat}の説明になりますが、コマンドラインオプションには互換があるため、同様のオプションでmacOSでもメタデータを付与させることができると思われます。

//list[exiftool-photosphere-bat][photosphere.bat - Googleフォト向けにメタデータを付与するbatファイル]{
FOR %%A IN (%*) DO (
"C:\YOUR_EXE_EXTRACT_PATH\exiftool.exe" ^
-ProjectionType="equirectangular" ^
-UsePanoramaViewer="True" ^
-"PoseHeadingDegrees<$exif:GPSImgDirection" ^
-"CroppedAreaImageWidthPixels<$ImageWidth" ^
-"CroppedAreaImageHeightPixels<$ImageHeight" ^
-"FullPanoWidthPixels<$ImageWidth" ^
-"FullPanoHeightPixels<$ImageHeight" ^
-CroppedAreaLeftPixels="0" ^
-CroppedAreaTopPixels="0" %%A
)
PAUSE
//}

以上のようなbatファイルを用意して、対象のjpgファイルをドラッグアンドドロップすると必要なメタデータが付与されますので、Googleフォトにアップロードして確認してください。
360度モードになってぐりぐり回すことができれば成功しています。

//footnote[google-streetview-guide-metadata][Photo Sphere XMP メタデータ @<href>{https://developers.google.com/streetview/spherical-metadata?hl=ja}]
//footnote[panotwins-photosphere][PanoTwins How to add mandatory Photo Sphere meta data to an equirectangular image @<href>{https://t.co/KbSq7QpT7J}]
//footnote[exiftool][@<href>{http://owl.phy.queensu.ca/~phil/exiftool/}]

== VR動画のレンダリング

前述したいわゆるVR動画の作成について、魚眼レンズのカメラを2台並べて撮影したものをステッチングしたり、Blender@<fn>{blender-stereo-camera}などの3Dモデリングソフトから出力したり、あるいはUnityやUnreal Engineなどのゲームエンジンからの出力などがありますが、「利用ユーザ層の特性により、PCや3Dモデリングについて専門的な知識を有しない初心者向けのドキュメントが数多くインターネット上で公開されている」という観点で随一である、MikuMikuDanceを用いたVR動画の生成方法についてここではとりあげます。

//footnote[blender-stereo-camera][Blender Manual - Stereo Camera @<href>{https://docs.blender.org/manual/en/dev/game_engine/camera/stereo.html}]

=== MikuMikuDanceとMikuMikuDomeMaster

//image[mmd-mmdm-2][MikuMikuDomeMaster利用例][scale=1.00]{
//}

MMDことMikuMikuDance@<fn>{mikumikudance}は3DCGムービー作成ツールですが、そのMMD向けにCaeru氏が公開しているMikuMikuDomeMaster@<fn>{mikumikudomemaster}ツールを使うと、@<img>{mmd-mmdm-2}のようなVR動画向けのエフェクトを実現することができます。

//footnote[mikumikudance][@<href>{http://www.geocities.jp/higuchuu4/}]
//footnote[mikumikudomemaster][MikuMikuDomeMaster作業中20160417 @<href>{https://twitter.com/Caeru_Odin/status/721653643036897280}]

では、MikuMikuDomeMasterでのステレオVR動画の作成方法について、ざっとご紹介します。

MikuMikuDomeMasterのステレオは視差設定にあわせカメラを左右に並べた方式となっているため、正面のみ正しく立体視が可能となります。
よって、「適度に離れた正面にモデルをソロで配置し、あまり左右に動かないモーション」を適用し、正面に注視ポイントが集中する動画を作ることがキモとなります。例えば、中央に人が入らない鏡映しデュオモーションなどは残念ながらこの方式のステレオに向いていません。

そこを踏まえた素材を用意した上で、空の新規MMDプロジェクトにモデル・背景・モーションを読み込みます。
AVIの出力サイズは、以下のように設定してください。いずれもステレオ設定で、モノラルの際には縦横いずれかのピクセル数が半分となります。

 * FreeVRPlayer（Cardboard）, Samsung VR（Gear VR）, SKYBOX VR Player（Daydream）, Littlstar（PSVR）など、ローカル再生向け
 ** Equirectangular360度Top-Bottomはアスペクト比1:1で設定
 *** ハイスペックスマホ・PS4 Pro向け：2560x2560
 *** ミドルレンジスマホ・ProでないPS4向け：1440x1440
 ** DomeMaster-SBS（サイドバイサイド）180度はアスペクト比2:1で設定
 *** ハイスペックスマホ・PS4 Pro向け：3200x1600
 *** ミドルレンジスマホ・ProでないPS4向け：1920x960
 * YouTubeアップロード向けステレオはアスペクト比16:18で設定
 ** Equirectangular360度Top-Bottom
 *** 可能であれば4K、2160Pステレオで：3840x4320
 *** 制作環境上、4Kが困難な際には：1920x2160

次に、MikuMikuDomeMaster内、DomeMaster.pmxを読み込み、MMEffect→エフェクトファイル割り当てよりMainタブはDomeMaster.pmx以外のチェックを外します（@<img>{mmdm-01}）。

//image[mmdm-01][DomeMaster.pmxのみMainに残す][scale=0.75]{
//}

続けて、Equirectangularであれば読み込んだpmxのモデル名「パノラマ」から、DM-PanoモーフをPano側に設定します。DomeMasterの際にはDM-PanoモーフをDM側に設定した後、天頂を向いているのを角度にX=90.0を設定することで正面に回すことができます（@<img>{mmdm-02}）。

//image[mmdm-02][DM-Panoモーフをいずれかの端に設定][scale=0.75]{
//}

パノラマモデルの視差ボーンを選択し、ボーン位置のX=0.3～0.4程度にすると、左右の視差が設定できます（@<img>{mmdm-03}）。カメラからモデルの距離によって適切な視差は変わってきますので、0.3の弱めからチューニングすると良いと思います。
視差とのバランスが難しいですが、モデルそのものの倍率を調整してやることで、リアルのサイズに近づけるとリアリティを高めることができます。

//image[mmdm-03][視差ボーンへの視差設定][scale=0.75]{
//}

MikuMikuDomeMasterの初期設定では高解像度の出力時にキューブマップの解像度が不足しますので、AVI出力の直前に変更します。
具体的にはSub/MakeCubeUtils.incを開き、RT_SIZEを2048に、AA_Loopsを2に書き換え、MMEの再読み込み（MMEffectメニュー→すべて更新で実行）を行います。SSAO-Cubes.xなどを併用しているとかなり重くなりますが、気合で乗り越えてAVI出力を実施しましょう。出力終了後にMakeCubeUtils.incを書き戻すのをお忘れなく。

AviUtl + x264guiExなどでmp4にエンコードした後は、お手持ちの環境でお楽しみください。
YouTube等、動画プラットフォームへの投稿公開はモデル・モーション・背景等素材のライセンスに十分にお気をつけて！

=== YouTubeのVR対応について

YouTubeは順番に、「360度動画」「ステレオ360度のVR動画」「360度動画・VR動画における360度空間音声（Spatial Audio）」に対応するようになりました。
空間音声（Spatial Audio）は3D音声や立体音響などとも言われ、顔の位置・向きにあわせた音が聞こえることを示します。
GoogleはYouTube向けに、前後左右4chの音声トラックを格納する仕様を採用・提案しています@<fn>{spatial-audio-youtube}。

この、YouTubeの仕様に基づいたVR動画の作成方法については、原則サイトで公開されている手順に沿えば良いのですが、「ソースはアスペクト比1:1にしてください」と書いてある割にどうやら今現在でも「16:9の左右映像をTop-Bottomで結合した16:18の動画」をアップロードする必要があることに留意願います@<fn>{aspect-16-9-issue}。

//footnote[spatial-audio-youtube][360 度動画や VR 動画で空間音声を使用する @<href>{https://support.google.com/youtube/answer/6395969?hl=ja}]
//footnote[vr-video-youtube][バーチャル リアリティ動画のアップロード @<href>{https://support.google.com/youtube/answer/6316263?hl=ja}]
//footnote[aspect-16-9-issue][申し訳ありません、最近追試できていないので確認します…]

== VRTKでHTC ViveとOculus Rift向け

=== VRTKとは

//image[vrtk-01][VRTK - Virtual Reality Toolkit][scale=0.85]{
//}

VRTK@<fn>{virtual-reality-toolkit}はVirtual Reality Toolkitの略で、VRアプリ開発に必要な便利な機能を提供するUnity向けライブラリです。
VR空間での移動、ポインタによるオブジェクト選択、触る・掴むといった操作や2D・3Dのボタン・レバー・ドア・引き出しなどを簡単に実現します。

他プラットフォームへの対応も準備はされているようですが、現状HTC ViveとOculus Rift両方に対応しており、VRTKに任せられる範囲は任せてしまうのが良いと考えられます。

※「Unityネイティブ対応のOpenVR＋SteamVR＋VRTK」と「Unityネイティブ対応のOculus＋Oculus Utilities＋VRTK」のサンプルを動かすまでの話を記載予定です。

//footnote[virtual-reality-toolkit][@<href>{https://vrtoolkit.readme.io/}]

== UnityでCardboard/Daydream向け
=== Google VR SDKとUnityのVR Native対応について

Daydreamの発表直後に、それまでCardboard SDKという名前だったものはGoogle VR SDKへと名称が変更となりました。
また、それと同時にUnityがDaydream/Cardboard 両VRプラットフォームにNative対応することが発表されました。
ちなみに、Unityでの「Native対応」というのは「特別なパッケージを追加でimportすることなく、その機能を利用することができるようになる」ことを表します。

2016年9月にDaydream Technical PreviewというDaydream向けに特別の対応がなされたUnityが公開され、Unity5.4.2f2-GVR13までバージョンアップされました。その後、2016年12月から始まったUnity 5.6 betaに引き継がれ、先日2016年4月頭、Unity 5.6が正式にリリースされました。

//footnote[daydream-technical-preview][DAYDREAM TECHNICAL PREVIEW AVAILABLE NOW @<href>{https://blogs.unity3d.com/jp/2016/09/22/daydream-technical-preview-available-now/}]
//footnote[unity-56-beta][UNITY 5.6 BETA IS NOW AVAILABLE @<href>{https://blogs.unity3d.com/jp/2016/12/13/unity-5-6-beta-is-now-available/}]

それでは、そのCardboard/DaydreamにNative対応した現時点最新のUnity 5.6.0f3にて、THETAで撮影したEquirectangular写真を閲覧するシンプルなアプリを作ってみましょう。
UnityとAndroid SDKのセットアップ手順は割愛しますが、Daydream向けのアプリを作るにはtarget API 24（Android 7.0 Nougat）のAndroid SDKコンポーネントが必要なため、ダウンロードしておきます。

UnityのGoogle VR Native対応で含まれる機能と、Google VR SDK for Unityが別パッケージとして提供する機能について、Google VR SDK@<fn>{google-vr-sdk-for-unity}公式サイトにFeaturesとして明確に区別して記載されていますが、Daydream Controllerや、Unityエディタ上で首振りなどのVR操作のエミュレートなど、実質Google VR SDK for Unityパッケージのimportは必須と思われます。
（Google VR SDKをimportしていない状態でプレビュー再生を行うと、Unityエディタがフリーズしました。）

//footnote[google-vr-sdk-for-unity][Google VR SDK for Unity @<href>{https://developers.google.com/vr/unity/}]

EquirectangularメディアのUnityでの扱い方については、warapuri氏のUnityとOculusで360度パノラマ全天周動画を見る方法【無料編】@<fn>{warapuri-360panorama}を参照ください。
メディアの投影先である天球モデル「Sphere100.fbx」をダウンロードしておきます。

//footnote[warapuri-360panorama][@<href>{https://t.co/gk7avi4Hqj}]

アプリ作成手順はざっと以下の通りです。

//image[daydream-equi-01][Unityエディタプロジェクト全体図][scale=1.00]{
//}

 * 新規3Dプロジェクトを"Hello560f3"で作成、Sceneを"Main"として保存。
 * Build Settingsから"Main"をScenes In Buildに追加、AndroidにSwitch Platform。
 * PlayerSettingsから、Company Nameを適当なものに変更。
 * Resolution and Presentation中のOrientationをLandscape Leftに変更。
 * Other Settings中のVirtual Reality SupportedのチェックをON、DaydreamまたはCardboardを追加。
 ** DaydreamとCardboardの2つをセットするとDaydreamでクラッシュするようになります。VRモードのenabled切り替えまわりに起因する模様@<fn>{gvr-unity-sdk-issue492}ですが、解決方法はわかりませんでした。
 ** VR Entry Flowという「デバイスをヘッドセットに挿入してください」画面フローとCardboard互換に関する説明ページ@<fn>{google-vr-entry-flow}を見る限り、両対応のアプリは考慮されているようですが…
 * Package Nameを"youten.redo.vr.Hello560f3"に変更。
 * Minimum API LevelはCardboard向けにはAndroid 4.4 KitKat (API level 19)あたりを設定、Daydream向けにはAndroid 7.0 Nougat (API level 24)を設定します。
 * 試した機種がARM機のみのため、Device FilterをFAT(ARMv7 + x86)からARMv7に変更。
 * 前述の天球モデル"Sphere100.fbx"をドラッグアンドドロップでAssetsに追加。
 ** Hierarchyに追加し、ScaleをX=-10 Y=10 Z=10で法線を反転させるためにXだけマイナスにして配置。
 * THETAで撮影したEquirectangular写真を"equi.jpg"にリネームし、Assetsにドラッグアンドドロップで追加。
 ** 先ほどHierarchyに追加したSphere100にドラッグしてTextureに設定、GIやLightの影響を受けないようにShaderをstandardからUnlit/Textureに変更しておきます。
 * CameraのTransformはX=0 Y=0 Z=0に変更し、Directional Lightは削除します。

//footnote[gvr-unity-sdk-issue492][OPENGL NATIVE PLUG-IN ERROR: GL_INVALID_VALUE: Numeric argument out of range #492 @<href>{https://github.com/googlevr/gvr-unity-sdk/issues/492}]
//footnote[google-vr-entry-flow][VR Entry Flow @<href>{https://developers.google.com/vr/daydream/guides/vr-entry}]

//image[daydream-equi-02][天球モデル・THETA写真・Google VR SDKを取り込み][scale=0.75]{
//}

//image[daydream-equi-03][Sphere100のScale設定][scale=0.75]{
//}

Cardboard向けビルドはGalaxy S6（SC-05G, Android 6.0.1）で、Daydream向けビルドはPixel XL（Android 7.1.1）で動作確認、とくに問題はなさそうです@<fn>{google-vr-sdk-1-10-bug}。

//footnote[google-vr-sdk-1-10-bug][Google VR SDK v1.10で発生していたCardboard向けの残念なパフォーマンス低下もなさそうでした。]

//image[daydream-equi-04][Equirectangular写真閲覧アプリ画面][scale=0.85]{
//}

Daydreamの素敵なヘッドトラッキングを確認できたところで、続けてコントローラも動かしてみましょう。

//image[daydream-gvrdemo-01][GVRDemo Scene][scale=0.75]{
//}

古いバージョンのGoogle VR SDKではDaydreamコントローラのデモSceneが独立していたのですが、最新バージョンv1.30ではCardboard時代からおなじみのワープするCubeを探すデモSceneがDaydreamコントローラにも対応しています。

//image[daydream-gvrdemo-02][いつものCube探しゲームもDaydreamコントローラで快適に][scale=0.85]{
//}

