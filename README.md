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

# Key bindings and workflow

I tried to have a small set of key bindings, that fits a minimal
workflow following this paradigm:
1. one centered floating window to do the job (FOCUS WORK),
2. two side by side windows (HUNTING WORK),
3. two side by side windows (WEBDEV WORK),
4. two side by side windows (VIDEOMAKING WORK),
5. if you need more than 2 windows open in the same monitor, maybe
you're doing something the wrong way.

# Installation

In order to build dwm you need the `Xlib` header files.

Edit `config.mk` to match your local setup (`dwm` is installed into
the `/usr/local` namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install

# Running dwm

The login screen you have when you start your computer is managed by
the *display manager*.

*Ubuntu 18.04* by default uses `gdm3` as *display manager*.  When you
log into your session, `gdm3` tells the `X` server which *desktop
session* (and so which *window manager*) to use by reading **appropriate**
*config files*.

Note, that `gdm3` doesn't read the file `.xinitrc` as other programs
like `startx` would do.  So in order, to use `dwm` *window manager*
with `gdm3` as *display manager*, you have to put `exec dwm` at the
end of the config file `~/.xsessionrc` that will be read by `gdm3`.

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
