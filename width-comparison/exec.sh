#!/bin/sh

echo Cモジュールのコンパイル
make clean && make
echo 'charmapsの<Uxxx>という文字列からxxxの部分を抽出します。'
python3 ambiguous_to_ambiguous2.py > ambiguous2.txt
echo '各ユニコード文字のコードポイントに対するwcwidth()の値を計算します。'
./display_wcwidth ambiguous2.txt > wcwidth.txt
echo '各ユニコード文字のコードポイントに対するchar-widthの値を計算します。'
emacs -Q -batch -l display_emacs_char-width.el "English" ambiguous2.txt > emacswidth.txt
echo '文字幅の計算結果をマージします。'
join wcwidth.txt emacswidth.txt > width_joined.txt
echo '文字幅のテーブルを作成します。'
python3 width_joined_to_html.py
