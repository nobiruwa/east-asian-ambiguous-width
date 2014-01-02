#!/usr/bin/env python3
# -*- coding:utf-8 -*-

import re

with open("ambiguous.txt") as in_file:
    for line in in_file:
        result = line.strip()
        result = re.sub(r'^<U', "", result)
        result = re.sub(r'>$', "", result)
        print(result)
