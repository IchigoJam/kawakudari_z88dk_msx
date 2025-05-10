# kawakudari for z88dk/msx, openMSX

- [kawakudari.rom](https://ichigojam.github.io/kawakudari_z88dk_msx/kawakudari.rom)
- [RUN on WebMSX/CBIOS](https://webmsx.org/cbios/?ROM=https://ichigojam.github.io/kawakudari_z88dk_msx/kawakudari.rom)

## compile and run

for mac
```sh
sh c.sh kawakudari
```

## setup

setup [openMSX](https://openmsx.org/) and [z88dk](https://z88dk.org/site/)

### openMSX

for mac
```sh
brew install openmsx
```

### z88dk

for mac
```sh
cd
mkdir bin
curl -O http://nightly.z88dk.org/z88dk-osx-latest.zip
unzip z88dk-osx-latest.zip

cat >> ~/.zshrc
# Suppress message about using zsh
export BASH_SILENCE_DEPRECATION_WARNING=1

# Export z88dk path and environment
export PATH=${PATH}:${HOME}/bin/z88dk/bin
export ZCCCFG=${HOME}/bin/z88dk/lib/config
```

## related

- [kawakudari original](https://ichigojam.net/IchigoJam-firstgame.pdf)
- [kawakudari sdcc MSX](https://github.com/ichigojam/kawakudari_sdcc_msx)

