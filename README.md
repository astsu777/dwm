# My build of DWM v6.5
![](https://i.postimg.cc/HsPmxQYW/screenshot-20210324-008.png)

This repository hosts the source code of my build of DWM (Dynamic Window Manager) made by [Suckless software](https://dwm.suckless.org/). It is based on DWM v6.5 and different patches have been applied in order to provide the features I like. The list of applied patches can be found in the *patches* folder. It features:

* Only active tags are visible (9 are available on every screen)
* Resizable gaps between screen edges and windows that can be toggled/resized with key bindings
* Multiple layouts are available: tile (master/stack), monocle, bottom stack + horizontal, centered master, spiral, dwindle, deck, grid (+ horizontal) and floating
* Adjustable bar height
* Ability to configure different layouts per tag
* Ability to rotate windows in the stack (easy to re-arrange windows in any layouts)
* Ability to display colored unicode characters such as emoticons
* The status bar defined with 'xsetroot' remains on a single monitor (primary one by default)
* Supports EWMH to allow window switching with *rofi* even if a window is on another tag/monitor (window gets the focus)
* Toggles floating/fullscreen/sticky modes for the focused window
* Floating windows can set to open at the center of the screen using rules

# Dependencies
The following packages are necessary in order to run this build of DWM properly:

* ttf-jetbrains-mono
* noto-fonts-emoji
* libxft

The following software are not mandatory but recommended:

* dmenu (hard-coded run launcher)
* st (hard-coded terminal emulator)
* trayer (optional, only if you want a system tray)
* slock (optional, only if you want a lock screen)

If you want a nice DMenu to be integrated, you can install [my custom build](https://github.com/astsu777/dmenu). You can also check out [my build of ST](https://github.com/astsu777/st) for a nice terminal emulator. Finally, [my build of *slock*](https://github.com/astsu777/slock) can be used as a nice lock screen.

# Installation
If you don't use my dotfiles, it is necessary to configure DWM to launch your preferred applications. In order to do this, modify the *config.def.h* file and look at the section starting at line **#162**: there are commented lines with several examples of applications (GUI & TUI). Simply modify these lines (and uncomment them) and adjust the key binding/commands to run. Everything is commented out because I actually use *SXHKD* to manage my applications.

Once you are ready to install DWM, type the following commands:

```
git clone --depth 1 https://github.com/astsu777/dwm.git
cd dwm
sudo make clean install
```

<u>**Note**</u>: this DWM installation can be fully automated by using my [bootstrap script](https://github.com/astsu777/bootstrap).

# Running DWM
If you don't use a login manager, you can start the graphical environment with the *startx* command (package "*xorg-xinit*" required) and a properly configured *.xinitrc* file. If you want some inspiration for your *.xinitrc*, you can check out [mine](https://github.com/astsu777/dotfiles/blob/master/config/X11/xinitrc).

If you use a login manager (such as *lightdm*), make sure to create a *dwm.desktop* file in */usr/share/xsessions/*. The file should contain the following:

```
[Desktop Entry]
Encoding=UTF-8
Name=DWM
Comment=Dynamic Window Manager
Exec=dwm
Icon=dwm
Type=XSession
```

In order to auto-start some programs, make sure they are configured either in your *.xinitrc* file or in your *.profile* file. It is also possible to use *.xprofile* when using a login manager to auto-start some programs. **WARNING**: login managers will not read your environment variables. This means you need to provide full path to programs or set the *$PATH* environment variable.

# Key Bindings
I configured the key bindings that I like. They are all configured in the *config.def.h* file. Here is the full list and what they actually do:

* **MODKEY** has been configured to be the Super key (=Windows key)

| Key binding | Action |
| :--- | :--- |
| `MODKEY + RETURN` | opens terminal (st is the hard-coded one but it can be modified) |
| `MODKEY + SHIFT + RETURN` | opens run launcher (dmenu is the run launcher but it can be modified) |
| `MODKEY + SHIFT + c` | closes window with focus |
| `MODKEY + SHIFT + r` | reloads dwm |
| `MODKEY + SHIFT + q` | quits dwm |
| `MODKEY + 1-9` | switch focus to tag (1 to 9) |
| `MODKEY + CTRL + 1-9` | show windows of multiple tags (1 to 9) |
| `MODKEY + CTRL + SHIFT + 1-9` | show focused window on multiple tags (1 to 9) |
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
| `MODKEY + SHIFT + f` | toggles fullscreen mode for focused window |
| `MODKEY + SHIFT + s` | toggles sticky mode for focused window |
| `MODKEY + Space` | toggles floating |
| `MODKEY + ALT + l` | locks the screen |
| `MODKEY + CTRL + t` | displays the system tray |
| `MODKEY + CTRL + SHIFT + t` | closes the system tray |

# Status Bar
By default, DWM has a very plain bar with almost no information in it. The status bar can be customized with one/several *BASH* script(s). Here is what mine looks like:

![](https://i.postimg.cc/c1YPrSvV/screenshot-20210807-039.png)

* 📦 0 : indicates how many updates are available (script: *dwmupdates*)
* 📰 0 : indicates the number of unread news if newsboat is installed (script: *dwmnews*)
* 🖥 0% : indicates the CPU usage (script: *dwmcpu*)
* 🧠 4% : indicates the percentage or used RAM (script: *dwmmemory*)
* ⬇  0B ⬆  0B : indicates the download/upload network traffic usage. It will automatically change B/KB/MB depending on the usage (script: *dwmnet*)
* 💾 45G/103G : indicates the disk space usage where "/" is mounted. Other disks can be added by modifying the script (script: *dwmdisk*)
* 🌡️ 66.0°C : indicates the CPU temperature when sensors can be read (script: *dwmtemp*)
* 🔌 100% : indicates the battery level when a battery is detected (script: *dwmbattery*)
* 🔇 50% : indicates the volume level. The icon will change depending on the volume level (script: *dwmvol*)
* 🌩️ +20°C : indicates the current weather (script: *dwmweather*)
* 🕒 Sat August 07 18:35 : indicates the current day, date and time in 24H format (script: *dwmclock*)

The different scripts for the bar are included in the *statusbar* folder. These scripts must be in your *$PATH* for the status bar to work. The script called *dwmbar* is the one launching the status bar (add it to either your *.xinitrc*/*.profile*/*.xprofile* file) while all the other ones are used to retrieve the different information.

<u>**Note**</u>: the folder called *statusbar-txt* contain script that will only display text and no emoji.

# Wallpapers
I use *feh* to setup my wallpapers randomly as it is the simplest way to do it. I store all my wallpapers in a single directory and then starts *feh* when running X with the following command:

```
feh --bg-scale --no-fehbg --randomize <PATH_TO_WALLPAPERS_DIRECTORY>
```

If you want a set of nice wallpapers, I have some stored in this [repository](https://github.com/astsu777/wallpapers).

# Contact
You can always reach out to me:

* [Twitter](https://twitter.com/astsu777)
* [Email](mailto:gaetan@ictpourtous.com)
