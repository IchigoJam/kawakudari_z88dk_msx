# kawakudari for z88dk/msx, openMSX

## setup

setup [openMSX](https://openmsx.org/) and [z88dk](https://z88dk.org/site/)

### openMSX

```sh
brew install openmsx
```

### z88dk

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

## compile and run

```sh
sh c.sh kawakudari
```
