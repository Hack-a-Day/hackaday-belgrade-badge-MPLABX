

This is a C framework built in MPLABX for the Hackaday | Belgrade conference badge

## Current State

Tested, fully working.

Users can easily manipulate the display and the user inputs using the
bh-badge-animate.c and bh-badge-animate.h files. No other files need to be
edited for basic badge manipulation. This is designed to be compatible with [a
software emulation version of the badge](https://github.com/Hack-a-Day/Belgrade_Badge_Demoscene).

For those who will be at the conference and working with the actual hardware,
you can go much deeper. Memory has been mapped to give you access to the
read and write buffers for the IR communications hardware, a random number
source, and more.

## Install the IDE, Compiler and Flasher

This repository is an MPLABX project. To compile a HEX file and to flash it to
the badge you need to install the following:

* [Microchip MPLAB X IDE](http://microchip.wikidot.com/mplabx:installation)
* [Microchip XC8 Compiler](http://microchip.wikidot.com/xc8:installation)
* Applicaiton to flash HEX file to badge:
    * __Windows__: Download microchip_hid_bootloader_v290a.7z [from this page](http://kair.us/projects/bootloader/index.html).
    
    * __Linux__: Download hid_bootloader.tar.bz2 using the [link in the middle of this page](http://elco.crsndoo.com/wordpress/2011/03/microchip-hid-bootloader-from-linux/)
        * Inside the build/ folder of that archive use:  ```./hid_bootloader /path/to/your.hex```
        
    * __OSX__: Untested. [Download this app from Microchip](https://www.dropbox.com/s/awoebbgdmmo1w4v/HIDBootloader.app.zip?dl=0)

Of course, don't forget to clone this repostiory:

```git clone https://github.com/Hack-a-Day/hackaday-belgrade-badge-MPLABX.git```

## Bootloader/Kernel

There are different hardware revisions of the Hackaday | Belgrade conference badge.
For this, and ease of hacking, the badge is running a hybrid bootloader/kernel
written by Voja Antonic. This C framework is carefully crafted to adhere to the
bootloader/kernel specification.

### Memory Map

Memory is fully mapped in the HaD_Badge.h file. This provides access to the buffer
being scanned into the badge's display (Buffer[16]) and to fully debounced button
scanning (KeyEdge) whose bits will be set when a press is debounced and must be
unset by software.

This is mapped to use Voja Antonic's modified bootloader that handles
all hardware features. C code interacts with his bootloader through absolute memory locations.
