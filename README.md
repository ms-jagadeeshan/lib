<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p>

<h3 align="center">My Library</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/ms-jagadeeshan/lib.svg)](https://github.com/ms-jagadeeshan/lib/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/ms-jagadeeshan/lib.svg)](https://github.com/ms-jagadeeshan/lib/pulls)
[![License](https://camo.githubusercontent.com/ad9ce5472ad34d6dd6f4e048fa14924db6834c3c49b82715c876517624a7ed0f/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4343302d626c75652e737667)](/LICENSE)

</div>

---

<p align="center"> Few lines describing your project.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

This is my library functions to automate and enhance interface 
## 🏁 Getting Started <a name = "getting_started"></a>
### Prerequisites

Need curl or wget command(any one) to download the zip file.
Make sure you already have curl or wget.If you don't have install it.
Install curl using,

```
sudo apt install curl
```
or
Install wget using

```
sudo apt install wget
```
### Installing
- [Automatic class opener](#automatic_class_opener)
- [Lab Calculator](#lab_calculator)

1.Download zip file from github


```
curl -LO https://github.com/ms-jagadeeshan/lib/archive/master.zip
```
or
```
wget https://github.com/ms-jagadeeshan/lib/archive/master.zip
```
2.Extract the zip downloaded.

```
unzip -q master.zip -d ~ && mv lib-master lib
```
#### Automatic class opener <a name = "automatic_class_opener"></a>
To create this shortcut
Go to settings

<a href="https://imgur.com/V2CRvs4"><img src="https://i.imgur.com/V2CRvs4.png" title="source: imgur.com" /></a>

Search keyboard shortcuts & enter
<a href="https://imgur.com/VjNmtyy"><img src="https://i.imgur.com/VjNmtyy.png" title="source: imgur.com" /></a>

Scroll down and click + 
<a href="https://imgur.com/8rbchgL"><img src="https://i.imgur.com/8rbchgL.png" title="source: imgur.com" /></a>
1.Give shortcut name as your wish
<br>2.Enter this in command
```
gnome-terminal -e 'sh -c "~/lib/sh/automatic_class_joiner.sh ; sleep 5"'
```
3.Click set shortcut,set shortcut key as you wish
<br>
<a href="https://imgur.com/AgaPCG4"><img src="https://i.imgur.com/AgaPCG4.png" title="source: imgur.com" /></a>
<a href="https://imgur.com/5ZnFGfP"><img src="https://i.imgur.com/5ZnFGfP.png" title="source: imgur.com" /></a>

Note:Set a shortcut key which is not in use already.
#### Lab Calculator <a name="lab_calculator"></a>

##### via Terminal
Open your terminal by pressing Ctrl + Alt + T
<br>Change your directory to ~/lib/c++
```
cd ~/lib/c++
```
<br>Then create a txt file,and enter your input values as comma seperated
```
gedit something.txt &
```
<br>Then run the lab_calculator.cpp program by,
```
cd ~/lib/c++/ && g++ lab_calculator.cpp -o lab_calculator && ./lab_calculator
```

##### via GUI

You can use gui opening file,and IDE's for running program.
<a href="https://imgur.com/bXnVw15"><img src="https://i.imgur.com/bXnVw15.png" title="source: imgur.com" /></a>
<a href="https://imgur.com/o7IMmDM"><img src="https://i.imgur.com/o7IMmDM.png" title="source: imgur.com" /></a>


## 🎈 Usage <a name="usage"></a>

### Automatic class opener
Single 👆 , to join online class. Don't search for class link anymore.
<br>This program is solely for IIIDM kancheepuram students,please others don't use.
<br>
For batch A student the links are correct,but for Ec batch-2 students have to edit the link_provider.cpp to get correct link.
And also edit programming practice link to your link,(link given in link_provider.cpp is for 1-21 )
<br>
<a href="https://imgur.com/FNOcFC3"><img src="https://i.imgur.com/FNOcFC3.png" title="source: imgur.com" /></a>
Others students are required to insert their link in program named link_provider.cpp
<br>
If you finished setting correctly,Just click the short cut key to open you class.

### Lab Calculator
I know it is very annoying when calculating values for lab record.
<br>To make it simple this program is there for you.This program have many operators
and custom functions is in development.
You will get menu according to number of variables in your input.
Example input:
Let say you have 5 set of inputs with two variables mass and velocity
your should give input as
```
m1,v1
m2,v2
m3,v3
m4,v4
m5,v5
```

Important: Don't stop here,Do contribute to this repo.


## ✍️ Authors <a name = "authors"></a>

- [@ms-jagadeeshan](https://github.com/ms-jagadeeshan) - Idea & Initial work

See also the list of [contributors](https://github.com/kylelobo/ms-jagadeeshan/contributors) who participated in this project.
