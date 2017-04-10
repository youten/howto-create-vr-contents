#@# VRコンテンツのつくりかた 技術書典2
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブ	ルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= VRコンテンツの作り方

== 全天球写真の撮影と閲覧

=== THETAとその仲間について

THETA@<fn>{ricoh-theta}はRICOH社のカメラで、コンパクトな棒状のユニットの表裏に魚眼レンズを搭載し、ワンショットで360度全天球の動画・静止画が撮れるものです。
スマートフォンとの連携アプリも出来が良く、USBやHDMIストリーミング、WiFi経由でのAPIなど関連したシステムを開発するためのIFも揃っており、なおかつコストパフォーマンスに優れた、この分野を楽しむ際にはマストバイの一品です。
母艦としてのスマートフォンの必要有無などの差がありますが、Samsung社のGear 360@<fn>{samsung-gear-360}やInsta360@<fn>{insta360-nano-air}のInsta Nano/Air、マスプロ電工社のKodak PIXPRO SP360シリーズ@<fn>{kodak-pixpro-sp360}やGoProも含めて全天球写真の撮れるカメラはラインナップが充実しつつあり、また、自分自身がぐるぐる回る必要がありますがCardboardカメラ@<fn>{cardboard-camera}など、スマートフォン単体でもアプリにて撮影が可能です。

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
以下、exeを動作させるbatファイル@<list>{exiftool-photosphere-bat}を掲載していますが、コマンドラインオプションには互換があるため、同様のオプションでmacOSでもメタデータを付与させることができると思われます。

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
よって、「適度に離れた正面にモデルをソロで配置し、あまり左右に動かないモーション」を適用し、正面に注視ポイントが集中する動画を作ることが肝となります。
例えば、中央に人が入らない鏡映しデュオモーションなどは残念ながらこの方式のステレオに向いていません。

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

パノラマモデルの視差ボーンを選択し、ボーン位置のX=0.3～0.4程度にすると、左右の視差が設定できます（@<img>{mmdm-03}）。
カメラからモデルの距離によって適切な視差は変わってきますので、0.3の弱めからチューニングすると良いと思います。
視差とのバランスが難しいですが、モデルそのものの倍率を調整してやることで、リアルのサイズに近づけるとリアリティを高めることができます。

//image[mmdm-03][視差ボーンへの視差設定][scale=0.75]{
//}

MikuMikuDomeMasterの初期設定では高解像度の出力時にキューブマップの解像度が不足しますので、AVI出力の直前に変更します。
具体的にはSub/MakeCubeUtils.incを開き、RT_SIZEを2048に、AA_Loopsを2に書き換え、MMEの再読み込み（MMEffectメニュー→すべて更新で実行）を行います。SSAO-Cubes.xなどを併用しているとかなり重くなりますが、気合で乗り越えてAVI出力を実施しましょう。
出力終了後にMakeCubeUtils.incを書き戻すのをお忘れなく。

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

※「Unityネイティブ対応のOpenVR＋SteamVR＋VRTK」と「Unityネイティブ対応のOculus＋Oculus Utilities＋VRTK」のサンプルを動かすまでの話を追記予定です。

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

