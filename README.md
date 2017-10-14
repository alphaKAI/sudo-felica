# sudo-felica
`sudo-felica` is a fork of `sudo` with Felica based Authentication support on Linux.  
This software is inspired by [sudo-touchid](https://github.com/mattrajca/sudo-touchid).  
  

## Warning

* I'm not a security expert. This software may have fatal vulnerability, please use at your own risk.  

## Requirements

* Pasori device(Felica reader)
* libpafe - open source library for pasori
* jansson - JSON Library for C

### libpafe

```zsh
$ git clone https://github.com/rfujita/libpafe.git 
$ cd libpafe
$ ./configure
$ make
$ sudo make install
```

### jansson

```zsh
$ git clone https://github.com/akheron/jansson
$ cd jansson
$ ./configure
$ make
$ sudo make install
```


## Build

```zsh
$ git clone https://github.com/alphaKAI/sudo-felica
$ cd sudo-felica/sudo
$ ./configure --prefix=/path/to/install
$ make
$ sudo make install
```

## Configuration
`sudo-felica` need the setting file as JSON format.  
Please make the file as follows:  

```json
{
  "IDm": "IDm of Your card",
  "PMm": "PMm of Your card"
}
```

You have to get IDm and PMm of your card, please use `felica_dump_tools`.  
