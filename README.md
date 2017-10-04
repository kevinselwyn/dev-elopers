# /dev/elopers

Linux pseudo-device that dispenses timeless Steve Ballmer knowledge

## Installation

First, install the necessary packages:

```bash
sudo apt-get install make module-assistant linux-headers-`uname -r`
```

Then, install the device:

```bash
sudo make install
```

To uninstall the device:

```bash
sudo make uninstall
```

To install using [Vagrant](https://www.vagrantup.com/):

```bash
vagrant up && vagrant ssh
sudo make install
```

## Usage

```
$ cat /dev/elopers | mplayer -cache 1024 -
```

![Steve Ballmer](https://i.imgur.com/gbHzjkD.gif)

## Acknowledgements

All credit to Mr. Ballmer, his sweaty shirt, and semantic satiation.