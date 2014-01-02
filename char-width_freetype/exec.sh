#!/bin/sh

echo "wcwidthの返却値、VL Gothicフォントのグリフが持つ文字幅、"
echo "emacsのchar-widthの値(settings/my-utf-8-eaw-fullwidth.elを適用した場合)を"
echo "比較します。"
echo ""
echo "ambiguousな幅を持つユニコード文字のコードポイントとemacsのchar-widthの値を"
echo "C言語の配列としてcharlist.hにまとめました。"
echo "C言語モジュールのコンパイル"
make clean && make
echo "文字幅の比較結果をambiguous_width_comparison.txtに出力します"
./ambiguous_width_comparison "/usr/share/fonts/truetype/vlgothic/VL-Gothic-Regular.ttf" > ambiguous_width_comparison.txt
