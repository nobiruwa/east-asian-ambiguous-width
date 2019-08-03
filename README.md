# east-asian-ambiguous-width

## charmaps

`settings/charmaps/UTF-8-EAW-FULLWIDTH.gz`で、文字幅をロケール依存ではなく私の好みに置き換えてしまいます。

UTF-8.gzとの差分を`settings/charmaps/UTF-8-EAW-FULLWIDTH.gz.diff`に出力してあります。

### 参考

- <http://www.unicode.org/Public/UNIDATA/EastAsianWidth.txt>
- <https://github.com/hamano/locale-eaw>

## Cygwin

`settings/cygwin/mintty_force_use_xcwidth.diff`にあるように、minttyのソースコードにおいて文字幅をロケール依存ではなく私の好みに置き換えてしまいます。

## emacs

`settings/emacs/output/my-utf-8-eaw-fullwidth.el`で、文字幅をロケール依存ではなく私の好みに置き換えてしまいます。

## wsl-terminal

minttyのオプションでは、ロケールを`ja_JP`にしましょう。
Linuxのロケールは`en_US`でも構いません。
