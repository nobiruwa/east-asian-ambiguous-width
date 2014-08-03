# settings/
## Emacs
First of all, create elisps.

    $ create_el.sh

## Emacs on Debian
Copy a charmap file.

    $ sudo cp UTF-8-EAW-FULLWIDTH.gz /usr/share/i18n/charmaps/

Add the following lines into `/etc/locale.gen`.

    en_US.UTF-8 UTF-8-EAW-FULLWIDTH
    ja_JP.UTF-8 UTF-8-EAW-FULLWIDTH

Run locale-gen.

    $ sudo locale-gen

Copy elisp into load-path directory.

    $ cp my-utf-8-eaw-fullwidth.el your-load-path/

Load `my-utf-8-eaw-fullwidth.el` into init.el

    (load "my-utf-8-eaw-fullwidth")

## Emacs on cygwin
Build  mintty-1.1.3 after applying `mintty_force_use_xcwidth.diff` to xcwidth.c.  
Then, copy the following files into load-path directory.

    $ cp my-utf-8-eaw-fullwidth_cygwin.el your-load-path/

Load `my-utf-8-eaw-fullwidth_cygwin.el`

    (load "my-utf-8-eaw-fullwidth_cygwin")
