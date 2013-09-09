(defvar full-width-table
'(
(#x1100 . #x115F)
(#x2329 . #x232A)
(#x2E80 . #x3029)
(#x3030 . #x303E)
(#x3041 . #x3096)
(#x309B . #xA4C6)
(#xAC00 . #xD7A3)
(#xF900 . #xFAD9)
(#xFE10 . #xFE19)
(#xFE30 . #xFE6B)
(#xFF01 . #xFF60)
(#xFFE0 . #xFFE6)
(#x00020000 . #x0002A6D6)
(#x0002F800 . #x0002FA1D)
#x2010
(#x2013 . #x2016)
(#x2018 . #x2019)
(#x201C . #x201D)
(#x2020 . #x2022)
(#x2024 . #x2027)
#x2030
(#x2032 . #x2033)
#x2035
#x203B
#x203E
#x2074
#x207F
(#x2081 . #x2084)
#x20AC
#x2103
#x2105
#x2109
#x2113
#x2116
(#x2121 . #x2122)
#x2126
#x212B
(#x2153 . #x2154)
(#x215B . #x215E)
(#x2160 . #x216B)
(#x2170 . #x2179)
#x2189
(#x2190 . #x2199)
(#x21B8 . #x21B9)
#x21D2
#x21D4
#x21E7
#x2200
(#x2202 . #x2203)
(#x2207 . #x2208)
#x220B
#x220F
#x2211
#x2215
#x221A
(#x221D . #x2220)
#x2223
#x2225
(#x2227 . #x222C)
#x222E
(#x2234 . #x2237)
(#x223C . #x223D)
#x2248
#x224C
#x2252
(#x2260 . #x2261)
(#x2264 . #x2267)
(#x226A . #x226B)
(#x226E . #x226F)
(#x2282 . #x2283)
(#x2286 . #x2287)
#x2295
#x2299
#x22A5
#x22BF
#x2312
(#x2460 . #x24E9)
(#x24EB . #x254B)
(#x2550 . #x2573)
(#x2580 . #x258F)
(#x2592 . #x2595)
(#x25A0 . #x25A1)
(#x25A3 . #x25A9)
(#x25B2 . #x25B3)
(#x25B6 . #x25B7)
(#x25BC . #x25BD)
(#x25C0 . #x25C1)
(#x25C6 . #x25C8)
#x25CB
(#x25CE . #x25D1)
(#x25E2 . #x25E5)
#x25EF
(#x2605 . #x2606)
#x2609
(#x260E . #x260F)
(#x2614 . #x2615)
#x261C
#x261E
#x2640
#x2642
(#x2660 . #x2661)
(#x2663 . #x2665)
(#x2667 . #x266A)
(#x266C . #x266D)
#x266F
(#x269E . #x269F)
(#x26BE . #x26BF)
(#x26C4 . #x26CD)
(#x26CF . #x26E1)
#x26E3
(#x26E8 . #x26FF)
#x273D
#x2757
(#x2776 . #x277F)
(#x2B55 . #x2B59)
(#x3248 . #x324F)
(#xFE00 . #xFE0F)
#xFFFD
(#x0001F100 . #x0001F10A)
(#x0001F110 . #x0001F12D)
(#x0001F130 . #x0001F169)
(#x0001F170 . #x0001F19A)
(#x000E0100 . #x000E01EF)))
(defun set-east-asian-ambiguous-width (width)
(dolist (range
         full-width-table)
  (set-char-table-range char-width-table range width))
  (set-char-table-range char-width-table #x00AC 1)
  ;; overwrite
  (set-char-table-range char-width-table #x2010 1))
(set-east-asian-ambiguous-width 2)
    
