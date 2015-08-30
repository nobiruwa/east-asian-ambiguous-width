#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import os
import sys

from string import Template


"""Create width_joined.html from width_table.txt.
Usage: ./width_table_to_html.py"""

# with open('resources/template.html') as template_file:
#     template_html = Template(template_file.read())

TEMPLATE_HTML = Template("""\
<html lang="ja">
  <head>
    <meta charset="UTF-8">
    <title>$title</title>
    <link rel="stylesheet" href="style.css" type="text/css" media="screen">
  </head>
  <body>
    <table>
      <tr>
        <th>HEX</th>
        <th>wcwidth</th>
        <th>emacs width</th>
        <th>Character</th>
      </tr>
      $rows
    </table>
    <script src="main.js"></script>
  </body>
</html>
""")

TEMPLATE_TR = Template("""\
<tr class="row">
  <td><span class="hex">$hex</span></td>
  <td><span class="wcwidth">$wcwidth</span></td>
  <td><span class="emacs-width">$emacs_width</span></td>
  <td><span class="char">$char</span></td>
</tr>
""")


def html_row(line):
    words = line.strip().split(' ')
    hex_value = words[0]
    wcwidth = words[1]
    emacs_width = words[2]
    char = '&#x' + words[0] + ';'
    return TEMPLATE_TR.substitute(hex=hex_value, wcwidth=wcwidth, emacs_width=emacs_width, char=char)

def htmlize(lines):
    rows = [html_row(line) for line in lines]
    html = TEMPLATE_HTML.substitute(title='East Asian Ambiguous Width Table',
                                    rows='\n'.join(rows))
    return html

def print_html(lines):
    print(htmlize(lines))


def main():
    if len(sys.argv) >= 2:
        with open(sys.argv[1]) as in_file:
            print_html(in_file)
    else:
        print_html(sys.stdin.readlines())

if __name__ == '__main__':
    main()
