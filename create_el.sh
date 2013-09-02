#!/bin/sh

grep 2$ WIDTH_FULL_WIDTH.txt > WIDTH_ONLY_FULL_WIDTH.txt
python3 charmaps_to_range.py WIDTH_ONLY_FULL_WIDTH.txt
