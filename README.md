# east-asian-ambiguous-width

## charmaps

`settings/charmaps/UTF-8-EAW-FULLWIDTH.gz`で、文字幅をロケール依存ではなく私の好みに置き換えてしまいます。

UTF-8.gzとの差分を`settings/charmaps/UTF-8-EAW-FULLWIDTH.gz.diff`に出力してあります。

### 使い方

1. charsetファイル`UTF-8-EAW-FULLWIDTH.gz`を`/usr/share/i18n/charmaps/`に配置します。
2. `/etc/locale.gen`でロケールに対するcharsetとして`UTF-8-EAW-FULLWIDTH`を設定します。
3. `locale-gen`を実行します。

```bash
$ ls /usr/share/i18n/charmaps/UTF-8-EAW-FULLWIDTH.gz
/usr/share/i18n/charmaps/UTF-8-EAW-FULLWIDTH.gz
$ grep FULLWIDTH /etc/locale.gen
en_US.UTF-8 UTF-8-EAW-FULLWIDTH
ja_JP.UTF-8 UTF-8-EAW-FULLWIDTH
$ sudo locale-gen
Generating locales (this might take a while)...
  en_US.UTF-8-EAW-FULLWIDTH... done
  ja_JP.UTF-8-EAW-FULLWIDTH... done
Generation complete.
```

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
