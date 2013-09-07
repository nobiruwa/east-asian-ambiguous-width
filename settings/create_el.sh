#!/bin/sh

grep 2$ WIDTH_FULL_WIDTH.txt > WIDTH_ONLY_FULL_WIDTH.txt
python3 charmaps_to_set-char-width-table.py WIDTH_ONLY_FULL_WIDTH.txt
rm WIDTH_ONLY_FULL_WIDTH.txt
