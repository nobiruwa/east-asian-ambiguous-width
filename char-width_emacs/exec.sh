#!/bin/sh

echo "settings/my-utf-8-eaw-fullwidth.elを適用したときのchar-widthの値と"
echo "cygwinのminttyが定義するwcwidth()の値の違いを確認します。"
echo ""
echo "minttyのソースsrc/newlib/libc/string/wcwidth.cにある"
echo "ambiguous[]の{..., ...},という配列の中身をコピーし、"
echo "ambiguous_buffer.txtとして保存しました。"

echo "ambiguous_buffer.txtを読み込み各ユニコード文字のコードポイントからchar-widthの値を計算します。計算結果はchar-width_emacs.txtに保存されます"
emacs -batch -l current-emacs-ambiguous-width.el
echo "width-averageの行を取り除き、char-width-list_emacs.txtに保存します"
grep -o " \(1\|2\)$" char-width_emacs.txt > char-width-list_emacs.txt
echo "See: char-width-list_emacs.txt."

