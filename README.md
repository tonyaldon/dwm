# Suckless softwares

In suckless softwares, there is no config file.  If you want to make
some modifications/configurations of the software, you just have to
`clone` the project, make your modifications and rebuild the
software.  In the most basic case, simple modifications in the
`config.h` are enough.

You can read more about [the suckless philosophy](http://suckless.org/philosophy/).

This repository is basically just the [dwm](http://dwm.suckless.org/)
software with the [config.h](./config.h) modified and maybe some little
added patches.

# Requirements

In order to build dwm you need the Xlib header files.

# Installation

Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install

# Running dwm

Add the following line to your `.xinitrc` to start `dwm` using
`startx`:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

# Merge releases and bug fixes from the upstream repository

To `merge` the upstream repository, create a locale clone of the
upstream repository:

    git remote add upstream git://git.suckless.org/dwm
    git fetch upstream

To merge the master branch of the `upstream` repository into the
(your) master branch, run the commands:

    git fetch upstream
    git checkout master
    git merge upstream/master

Before merging, you might want to see the diff between your `master`
branch and the `upstream/master` branch.  Do do so, run the commands:

    git fetch upstream
    git diff upstream/master master
