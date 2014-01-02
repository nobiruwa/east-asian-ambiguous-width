#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from string import Template


"""Create width_joined.html from width_joined.txt.
Usage: ./width_joined_to_html.py"""

def main():
    template_tr = Template('<tr><td>$hex</td><td>$wcwidth</td><td>$emacs_width</td><td>$char</td></tr>\n')
    rows = ''
    with open("width_joined.txt") as in_file:
        for line in in_file:
            words = line.strip().split(' ')
            hex_value = words[0]
            wcwidth = words[1]
            emacs_width = words[2]
            char = '&#x' + words[0] + ';'
            rows += template_tr.substitute(hex=hex_value, wcwidth=wcwidth, emacs_width=emacs_width, char=char)

            with open("template.html") as template_file:
                template_html = Template(template_file.read())
                html = template_html.substitute(title='East Asian Ambiguous Width Table',
                                                rows=rows)
                with open("width_joined.html", mode='w') as out_file:
                    out_file.write(html)

if __name__ == '__main__':
    main()
