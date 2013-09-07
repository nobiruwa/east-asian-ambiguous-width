#!/usr/bin/env python3
# -*- coding:utf-8 -*-
# Usage: create_group.py WIDTH_FULL_WIDTH.txt

import re
import sys

def codepoint_to_number(codepoint):
    """convert codepoint string, for example <U2010>, to integer.
    Arguments:
    - `codepoint`: codepoint string
    """
    r = re.compile("<U([0-9A-F]+)>")
    m = r.search(codepoint)
    return int(m.group(1), 16)

f = open(sys.argv[1])

sets = []
set = []
sets.append(set)
for line in f:
    line = line.strip("\n").split(" ")
    codepoint = line[0]
    width = line[-1]
    if len(set) > 0:
        if (codepoint_to_number(set[-1][0]) + 1 != codepoint_to_number(codepoint)) \
        or set[0][1] != width:
            set = []
            sets.append(set)
    set.append((codepoint, width))
f.close()

for _set in sets:
    if (len(_set)) > 1:
        print(_set[0][0] + "..." + _set[-1][0] + " " + _set[0][1])
    elif (len(_set) == 1):
        print(_set[0][0] + " " + _set[0][1])
