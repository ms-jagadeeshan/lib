<h1 align="center">Class joiner v2</h1>

---

## Prerequisites

Check whether you have "git", by doing the following:
```
git --version
```
If you don't have, install using
```
sudo apt-get install git
```

## Installing
Clone this repository using git clone(Skip this if you already cloned)


```
git clone https://github.com/ms-jagadeeshan/lib.git
```
To get the latest version,
```
cd ~/lib
git pull
```
Now open terminal and change directory to lib/class-joiner-v2
<br>
And run this command
```
sh ./install.sh
```
## How it works

- classjoiner.cpp - checks current time and open the link if class is there. This is command line utility, to know more details of its function, run this in terminal
```
classjoiner --help
```
- cjdaemon.sh - This is the daemon program and starts automatically after booting, it launches classjoiner program and goes to sleep for 1 hour , again launches class joiner program and continues.
- The symlink of both the program are created in ~/.local/bin 
- And the .desktop file of cjdaemon is created in ~/.config/autostart and .desktop file of classjoiner is created in ~/.local/share/applications
<br>
<img src="image1.png">
<br>

### Credits
<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>