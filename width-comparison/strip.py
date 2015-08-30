#!/usr/bin/env python3
# -*- coding:utf-8 -*-

import re
import sys


def strip(lines):
    for line in lines:
        result = re.sub(r'(^\s*<U|>\s*$)', '', line)
        print(result)


def main():
    if len(sys.argv) >= 2:
        with open(sys.argv[1]) as in_file:
            strip(in_file)
    else:
        strip(sys.stdin.readlines())


if __name__ == '__main__':
    main()
