# mycat

`mycat` is a simple reimplementation of the UNIX `cat` command in C.
It can print the contents of files to standard output and supports an optional `-n` flag to number output lines.

## Features

- Concatenate and print files to standard output.
- If no file is specified, reads from `stdin`.
- Option `-n` prefixes each line with its line number.
- Lightweight and written in standard C.

---

## Requirements

- A C compiler (e.g., `gcc` or `clang`)
- `make` utility

## Build steps

Clone the repository:

```bash
git clone https://github.com/yourusername/mycat.git
```

Enter repository:

```bash
cd mycat
```

Install:

```bash
sudo make install COMPILER=... BIN_PATH=..., default COMPILER=gcc and BIN_PATH=/usr/local/bin
```

Uninstall:

```bash
sudo make uninstall BIN_PATH=..., default BIN_PATH=/usr/local/bin
```

## Usage

```bash
mycat [OPTIONS] [FILE...]
```

Options:

- `-n` number all output lines
