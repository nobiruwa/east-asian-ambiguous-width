#!/usr/bin/env python
# -*- coding: utf-8 -*-
#Usage: call this from create_el.sh
import re
import sys

# 引数をオープン
filename = sys.argv[1]
infile = open(filename)


# マッチ文字列を作成
# <>
r = re.compile("<U[0-9A-Fa-f]+>")

def hex(codepoint):
    # <UXXXX> => #xXXXX
    m = re.search("[0-9A-Fa-f]+", codepoint)
    return "#x" + str(m.group(0))

def hex_assoc(start, end):
    return "(" + hex(start) + " . " + hex(end) + ")"

elements = []
for line in infile: # readline()と等価、改行文字を含む
    s = line.strip() # 改行文字を取り除く
    if (s[-1] == "2"):
        codepoints = r.findall(s)
        if len(codepoints) == 2:
            e = hex_assoc(codepoints[0], codepoints[1])
            elements.append(e)
        elif len(codepoints) == 1:
            e = hex(codepoints[0])
            elements.append(e)

with open("my-utf-8-eaw-fullwidth.el", 'w') as outfile:
    outfile.write("(defvar full-width-table\n")
    
    outfile.write("'(") # start paren of list
    inner = "\n".join(elements)
    outfile.write(inner)
    outfile.write(")") # end paren of list

    outfile.write(")") #end paren of defvar

    outfile.write("""
(defun set-east-asian-ambiguous-width (width)
(dolist (range
         full-width-table)
  (set-char-table-range char-width-table range width))
  (set-char-table-range char-width-table #x00AC 1)
  ;; overwrite
  (set-char-table-range char-width-table #x2010 1))
(set-east-asian-ambiguous-width 2)
    """)
