#!/bin/sh

mkdir -p output
echo "settings/my-utf-8-eaw-fullwidth.elを適用したときのchar-widthの値と"
echo "cygwinのminttyが定義するwcwidth()の値の違いを確認します。"
echo ""
echo "minttyのソースsrc/newlib/libc/string/wcwidth.cにある"
echo "ambiguous[]の{..., ...},という配列の中身をコピーし、"
echo "ambiguous_buffer.txtとして保存しました。"
echo ""
echo "ambiguous_buffer.txtを読み込み各ユニコード文字のコードポイントからchar-widthの値を計算します。"
echo "計算結果はoutput/char-width_emacs-default.txtに保存されます。"
echo "init.elをロードした後の計算結果はoutput/char-width_emacs-after-init-loaded.txtに保存されます。"
emacs -batch -l current-emacs-ambiguous-width.el
echo "Rangeの行を取り除き、output/char-width-list_default-emacs.txtに保存します"
grep -v "^Range" output/char-width_emacs-default.txt > output/char-width-list_default-emacs.txt
echo "See: output/char-width-list_default-emacs.txt."

