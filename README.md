# My build of DWM v6.2
### Plain DWM, without my status bar:
![](https://hostr.co/file/eyxPVmx6tchb/dwm-nodotfiles-nobar.png)

### DWM with my status bar:
![](https://hostr.co/file/FuVucpNJHOSO/dwm.png)

This repository hosts the source code of my build of DWM (Dynamic Window Manager) from the [Suckless software](https://dwm.suckless.org/). It is based on DWM v6.2 and different patches have been applied in order to provide the features I liked. The list applied patches can be found in the *patches* folder. It features the following settings:

* Only active tags are visible (9 are available)
* Resizable gaps between screen edges and windows that can be toggled/resized with key bindings
* Multiple layouts are available: tile (master/stack), monocle, bottom stack + horizontal, centered master, spiral, dwindle, deck, grid (+ horizontal) and floating
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
* libxft-bgra (regular *libxft* won't work if you use my status bar --> DWM will crash)
* dmenu
* st
* trayer (optional, only if you want a system tray)
* xlock (optional, only if you want a lock screen)

If you don't want to use custom emojis in the status bar, there is no need for package *libxft-bgra* (the standard *libxft* would suffice). *st* and *dmenu* are very recommended because those programs are hard-coded in my DWM configuration. *trayer* is totally optional but is the one I chose to hard-code in my DWM configuration.

If you want a nice DMenu to be integrated, you can install [my custom build](https://github.com/GSquad934/dmenu). You can also check out [my build of ST](https://github.com/GSquad934/st.git) for a nice terminal emulator.

# Installation
If you don't use my dotfiles, it is necessary to configure DWM to launch your preferred applications. In order to do this, modify the *config.def.h* file and look at the section starting at line **#162**: there are commented lines with several examples of applications (GUI & TUI). Simply modify these lines (and uncomment them) and adjust the key bindings and the commands to run. Everything is commented out because I actually use SXHKD to manage my applications.
Once you are ready to install DWM, type the following commands:

```
git clone --depth 1 https://github.com/GSquad934/dwm.git
cd dwm
sudo make clean install
```

<u>**Note**</u>: this DWM installation can be fully automated by using my [bootstrap](https://github.com/GSquad934/bootstrap) script (you can just DWM which will also install dmenu and st).

# Running DWM
If you don't use a login manager, you can start the graphical environment with the command *startx* (package "*xorg-xinit*" required) and a properly configured *.xinitrc* file. If you want some inspiration for your *.xinitrc*, you can check out [mine](https://github.com/GSquad934/dotfiles/blob/master/config/X11/xinitrc).
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

# Status Bar
By default, DWM has a very plain bar with almost no information in it. The status bar can be customized with one/several BASH script(s). Here is what mine looks like:

![](https://hostr.co/file/jHQRjOaMMQ9t/dwm-statusbar.png)

* 📦 0 : indicates how many updates are available (script: *dwmupdates*)
* 🖥 24% ▃ : indicates the CPU usage. The bar will fill-up if the CPU is used more (script: *dwmcpu*)
* 🧠 0.61GB/1.93GB : indicates the RAM usage (script: *dwmmemory*)
* ⬇  7.9MB ⬆  48KB : indicates the download/upload network traffic usage (script: *dwmnet*)
* 💾 5.0G (18%) : indicates the disk space usage where "/" is mounted. Other disks can be added by modifying the script (script: *dwmdisk*)
* 🌡 0 : indicates the CPU temperature. (script: *dwmtemp*)
* 🔊 100% : indicates the volume level. The icon will change depending on the volume level (script: *dwmvol*)
* 🕒 Mon, February 22 14:31 : indicates the current day, date and time in 24H format (script: *dwmclock*)

The different scripts for my bar are not included in this repo but can be found [here](https://github.com/GSquad934/dotfiles/tree/master/local/bin/statusbar). <u>**Note**</u>: these scripts must be in your *$PATH* for the status bar to work. The script called *dwmbar* is the one launching the status bar (add it to your *.xinitrc*) while all the other ones are used to retrieve the different information.

# Wallpapers
I use *feh* to setup my wallpapers randomly as it is the simplest way to do it. I store all my wallpapers in a single directory and then starts *feh* when running X with the following commands in my *.xinitrc*:

```
feh --bg-fill --no-fehbg --randomize <PATH_TO_WALLPAPERS_DIRECTORY>
```

If you want a set of nice wallpapers, I have some stored in this [repository](https://github.com/GSquad934/wallpapers).

# Contact
You can always reach out to me:

* [Twitter](https://twitter.com/gaetanict)
* [Email](mailto:gaetan@ictpourtous.com)
