# cutie

intrusive thought: make a portable audio player (specific to my own desires)

totally not a project yet

## daisy

i'm trying to use libDaisy and libFLAC++!
i just don't know how to integrate the latter

### setup

install the Daisy toolchain: https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment#1-install-the-toolchain

```sh
git submodule update --init
cd libDaisy
make

# no idea what to do with `flac` yet
# ... insert instructions for libFLAC++

cd src
make
```

## ideas

- sheet metal case
  - maybe 3d-printed or CNC'd out of some other material to improve resistance to moisture etc?
- e-ink display
  - shows info about currently playing song
  - also serves as a menu when selecting something to play, etc.
- hardware buttons
  - slide switch to lock/unlock buttons (think ipod)
  - next/prev buttons
  - need at least two more buttons for enter/back i think
  - vol up/down? or maybe keep that hardware based?
- micro SD card slot (maybe 2x) for media storage
  - should be plenty fast for reading FLAC files, fairly cheap and available hardware
  - SD card reading stack is probably a lot easier than my previous idea of M.2 storage
- additional eMMC (or similar) storage (unknown how big this needs to be)
  - records playback history
    - when connected to a computer a command line interface can export this and register to last.fm/libre.fm/etc.
    - when exported, the internal history is no longer needed and cleared (to hopefully reduce space requirements for the storage)
- internal rechargable battery with enough capacity for (hopefully) ~12 hours playback 
  - viable battery options will be apparent once we know the rest of the stack; if a huuuuge battery is needed for 12 hours, we'll have to settle on something smaller, but i want at least like.. 6 hours of playback on a single charge :pray:
- "good" DAC
- "good" amplifier (i want it to at least comfortably drive my DT 770 Pro, 80 ohm headphones)
- 1/4" TRS output
- FLAC support only
- focus on playing back albums, folder structure will likely be significant
- [Daisy](https://www.electro-smith.com/daisy/daisy) might be a viable platform to build off of, although i'm unsure if FLAC playback can be achieved :eyes:
  - DAC should be plenty sufficient for most use cases (16/24 bit, up to 96kHz)
  - the Daisy Pod seems to drive my headphones (when powered by usb :shrug:)
