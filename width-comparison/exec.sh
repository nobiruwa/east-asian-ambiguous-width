#!/bin/sh

mkdir -p output

echo Cモジュールのコンパイル
# make clean && make
meson setup bin --wipe && meson compile -C bin

echo 'charmapsの<Uxxx>という文字列からxxxの部分を抽出します。'
python3 strip.py resources/ambiguous_charmaps.txt > output/ambiguous_chars.txt

echo '各ユニコード文字のコードポイントに対するwcwidth()の値を計算します。'
bin/display_wcwidth output/ambiguous_chars.txt > output/wcwidth.txt

echo '各ユニコード文字のコードポイントに対するchar-widthの値を計算します。'
emacs -Q -batch -l display-emacs-char-width.el "English" output/ambiguous_chars.txt > output/emacswidth.txt

echo '文字幅の計算結果をマージします。'
join output/wcwidth.txt output/emacswidth.txt > output/widthtable.txt

echo '文字幅のテーブルを作成します。'
python3 htmlize.py output/widthtable.txt > output/widthtable.html
cp resources/style.css output/
cp resources/main.js output/
