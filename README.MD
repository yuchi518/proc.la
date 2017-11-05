# proc.la

proc.la is a biological and cloudable language.

  - Procedure is a lambed, sometimes.

## Features

  - Easy to write a cloud base application.

## Tech

Many new frameworks are involved in this project:

* [platform] - Platform liberary is a c library, it try to provide cross-platform API.
  * type - int8/16/32/63, uint8/16/32/63, etc.
  * memory management - Support auto-release function. 
* [dybuf] - 
* [MMO] - Memory managed object framework.
    * Inheritable structure and functions. (mmo.h)
    * MMObject hierarchy. (mmo_ext.h)
    * Serialization. (mmo_pack.h)
* [uthash]

## Installation


```sh
$ cmake
```

## Development (TODO)

* AST Error detection
  * Error line
  * Interrupt flow when error
  * Fix crash if syntax error
* Variable conversion
* Serialization (Packer/Unpacker)
* Unicode/UTF-8 support

## License
GPLv2

