#!/bin/sh

emacs -batch -l current-emacs-ambiguous-width.el
emacs -batch -l current-emacs-ambiguous-width.el
grep -o " \(1\|2\)$" char-width_emacs.txt > char-width-list_emacs.txt
echo "See: char-width-list_emacs.txt."

