C++

# 実行手順

1. モジュールのビルド
　 <Windowsの場合>
　　Visual Studio 2017で以下のslnファイルを読み込みビルドしてください。
　　DicApp\DicApp.sln

　 <Windows以外の場合>
　　以下のファイルを環境に合わせて取り込みビルドしてください
　　DicApp\DicApp\DicApp.cpp

2. データファイルの用意
   ワークフォルダに「dictionary_data.txt」というテキストファイルを作成します。
　 エンコード種類：SJIS

   テキストに「上手」追加して保存します。


3. 実行後、コンソールに"上手"と表示されたら成功です。
   ※Shift_JISで出力されます。


# 注意事項
1. ソースコードのエンコードの変更
　Mac環境で文字化けが発生するため、DicApp.cppのエンコードをSJISからUTF-8に変更しています
