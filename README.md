# EternalResourceExtractor

![Build Status](https://github.com/PowerBall253/EternalResourceExtractor/actions/workflows/build.yml/badge.svg)

Small C++ utility to extract files from a DOOM Eternal .resources file.

## Features

* Supports launching from command line with arguments, double clicking on it, and dragging and dropping.
* ~2-3x faster than QuickBMS on extracting files.
* Standalone, does not require any additional files.
* Lighter than QuickBMS and other extraction tools.
* Supports Windows, Linux and macOS.

## Usage

The syntax for the CMD is:

```
EternalResourceExtractor.exe [path to .resources file] [out path] [options]
```

The supported options are:

* `-h`, `--help`: Displays the help message and exits.
* `-q`, `--quiet`: Silences output during the extraction process.
* `-f`, `--filter=FILTERS`: Indicates a pattern the filename must match to be extracted,  using `*` for matching various characters and `?` to match exactly one. You can also prepend a `!` at the beginning of a filter to indicate it must not be matched, and separate various filters with a `;`.
* `-r`, `--regex=REGEXES`: Similar to `-f`, but allows full ECMAScript-style regular expressions to be passed.

You can also double click on it or drag and drop the .resources file to get started.

## Compiling

NOTE: The static libs from the Oodle SDK are needed to build this project.

The project uses CMake to compile. It also needs MSVC or the MinGW toolchain on MSYS to compile on Windows.

First clone the repo by running:

```
git clone https://github.com/PowerBall253/EternalResourceExtractor.git
```

Then, create a `lib` folder in the repo and place your Oodle static libraries on it. It should look like this:

```
lib/oo2core_win64.lib
lib/liboo2corelinux64.a
lib/liboo2coremac64.a
```

Then, generate the makefile by running:

```
cmake -B "build" # Append "-G 'MSYS Makefiles'" on MSYS
```

Afterwards you can build with:

```
cmake --build "build" --config Release
```

Finally, on Linux and macOS you can run

```
strip "build/EternalResourceExtractor"
```

to reduce the binary's filesize.

The EternalResourceExtractor executable will be in the `build` folder in Linux/MinGW/macOS and in the `build\Release` folder in MSVC.

## Credits

* aluigi: For the QuickBMS resource extractor script for The New Colossus.
* One of infogram's friends: For editing the script to work with DOOM Eternal.
