#!/bin/sh

grep 2$ resources/WIDTH_FULL_WIDTH.txt > /tmp/WIDTH_ONLY_FULL_WIDTH.txt
python3 charmaps_to_set-char-width-table.py WIDTH_ONLY_FULL_WIDTH.txt
rm /tmp/WIDTH_ONLY_FULL_WIDTH.txt
