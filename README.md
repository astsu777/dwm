# My build of DWM v6.2

![](https://hostr.co/file/Hqsf3ZJq0KmD/dwm-showcase.png)

This repository hosts the source code of my build of DWM (Dynamic Window Manager) from the [Suckless software](https://dwm.suckless.org/). It is based on DWM v6.2 and different patches have been applied in order to provide the features I liked. The list applied patches can be found in the *patches* folder. It features the following settings:

* Only active tags are visible (9 are available)
* Resizable gaps between screen edges and windows that can be toggled/resized with key bindings
* Multiple layouts are available: tile (master/stack), monocle, bottom stack + horizontal, centered master, spiral, dwindle, deck, grid (+ horizontal) and floating
* A simple status bar configured with a BASH script. The different scripts for the bar are not included in this repo but can be found [here](https://github.com/GSquad934/dotfiles/tree/master/local/bin/statusbar). <u>**Note**</u>: these scripts must be in your *$PATH* for the status bar to work. The script called *dwmbar* is the one triggering the status bar (add it to your *.xinitrc*)
* Adjustable bar height
* Ability to configure different layouts per tag
* Window swallowing. Example: a GUI program launched from the terminal will result in the terminal window to be hidden
* Ability to rotate windows in the stack (easy to re-arrange windows in any layouts)
* If you want to use DWMBlocks (I don't), this build is already patched to work with signal updating
* Ability to display coloured unicode characters such as emoticons

# Dependencies
The following packages are necessary in order to run this build of DWM properly:

* ttf-jetbrains-mono
* ttf-joypixels
* libxft-bgra (required only if you use my bar)
* dmenu (recommended)
* xterm (recommended)
* trayer (optional, only if you want a system tray)
* xlock (optional, only if you want a lock screen)

If you don't want to use custom emojis in the status bar, there is no need for package *libxft-bgra* (the standard *libxft* would suffice). *xterm* and *dmenu* are very recommended because those programs are hard-coded in my DWM configuration. *trayer* is totally optional but is the one I chose to hard-code in my DWM configuration.

# Installation
If you don't use my dotfiles, it is necessary to configure DWM to launch your preferred applications. In order to do this, modify the *config.def.h* file and look at the section starting at line **#162**: there are commented lines with several examples of applications (GUI & TUI). Simply modify these lines (and uncomment them) and adjust the key bindings and the commands to run. Everything is commented out because I actually use SXHKD to manage my applications.
Once you are ready to install DWM, type the following commands:

```
git clone --depth 1 https://github.com/GSquad934/dwm.git
cd dwm
sudo make clean install
```

If you want a nice DMenu to be integrated, you can install [my custom build](https://github.com/GSquad934/dmenu). If you want a nicer terminal than XTerm, you can also check out [my build of ST](https://github.com/GSquad934/st.git).

## Running DWM
If you don't use a login manager and need some inspiration for your *.xinitrc*, you can check out [mine](https://github.com/GSquad934/dotfiles/blob/master/config/X11/xinitrc).
If you use a login manager (such as *lightdm*), make sure to create a *dwm.desktop* file in */usr/share/xsessions/*. The file should contain the following:

```
[Desktop Entry]
Encoding=UTF-8
Name=Dwm
Comment=Dynamic window manager
Exec=dwm
Icon=dwm
Type=XSession
```

In order to auto-start some programs, make sure they are configured either in your *.xinitrc* file or in your *.profile* file.

# Key Bindings
I configured the key bindings that I like. They can all be found in the *config.def.h* file. Here is the full list and what they actually do:

* **MODKEY** has been configured to be the Super key (=Windows key)

| Key binding | Action |
| :--- | :--- |
| `MODKEY + RETURN` | opens terminal (xterm is the hard-coded one but it can be modified) |
| `MODKEY + SHIFT + RETURN` | opens run launcher (dmenu is the run launcher but it can be modified) |
| `MODKEY + SHIFT + c` | closes window with focus |
| `MODKEY + SHIFT + r` | reloads dwm |
| `MODKEY + SHIFT + q` | quits dwm |
| `MODKEY + 1-9` | switch focus to tag (1 to 9) |
| `MODKEY + SHIFT + 1-9` | send focused window to tag (1 to 9) |
| `MODKEY + j` | focus stack +1 (switches focus between windows in the stack) |
| `MODKEY + k` | focus stack -1 (switches focus between windows in the stack) |
| `MODKEY + SHIFT + j` | rotates stack +1 (rotates the windows in the stack) |
| `MODKEY + SHIFT + k` | rotates stack -1 (rotates the windows in the stack) |
| `MODKEY + h` | setmfact -0.05 (expands size of window) |
| `MODKEY + l` | setmfact +0.05 (shrinks size of window) |
| `MODKEY + z` | incrgaps +1 (increases the gaps) |
| `MODKEY + x` | incrgaps -1 (decreases the gaps) |
| `MODKEY + a` | toggles gaps (enable/disable) |
| `MODKEY + SHIFT + a` | resets the gaps to their default size |
| `MODKEY + i` | increases the number of master windows |
| `MODKEY + d` | decreases the number of master windows |
| `MODKEY + .` | focusmon +1 (switches focus next monitors) |
| `MODKEY + ,` | focusmon -1 (switches focus to prev monitors) |
| `MODKEY + b` | toggles the bar |
| `MODKEY + Tab` | cycles to the next layout |
| `MODKEY + SHIFT + Tab` | cycles to the previous layout |
| `MODKEY + SHIFT + Space` | toggles floating mode for focused window |
| `MODKEY + ALT + l` | locks the screen |
| `MODKEY + ALT + t` | displays the system tray |
| `MODKEY + ALT + SHIFT + t` | closes the system tray |


# Contact
You can always reach out to me:

* [Twitter](https://twitter.com/gaetanict)
* [Email](mailto:gaetan@ictpourtous.com)
