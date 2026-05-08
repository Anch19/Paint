# PixelPaint – Lightweight Image Editor in C

## Introduction

**PixelPaint** is a lightweight image editing application written primarily in **C**, developed as a university systems programming project. The project focuses on low-level image manipulation, modular software design, and implementing graphical operations from scratch.

The application provides core image editing features such as image loading/saving, flood fill operations, and GUI interaction while maintaining a clean modular structure. The project demonstrates concepts including memory management, image processing, file handling, and GUI integration in C.

This repository highlights practical experience with:

* Systems programming in C
* Modular software architecture
* Image processing algorithms
* GUI integration
* Makefile-based project builds
* Testing and debugging workflows

---

# Features

* Load and save image files
* Flood fill (paint bucket) functionality
* Basic image editing operations
* GUI support with fallback implementation
* Modular architecture using separate source/header files
* Automated build process using Makefile
* Test setup for validating functionality

---

# Project Structure

```bash
Paint/
├── src/
│   ├── main.c
│   ├── gui.c
│   ├── gui.h
│   ├── gui_caller.c
│   ├── gui_caller.h
│   ├── gui_caller_fallback.c
│   ├── image_edit.c
│   ├── image_edit.h
│   ├── flood_fill.c
│   ├── flood_fill.h
│   ├── file_io.c
│   ├── file_io.h
│   ├── structures.h
│   └── util.h
│
├── test/
├── .vscode/
├── Makefile
├── convert.sh
└── test.png
```

---

# Core Components

## Image Processing

Handles pixel-level image manipulation and editing operations.

### Files

* `image_edit.c`
* `image_edit.h`

Responsibilities:

* Pixel modifications
* Image transformations
* Editing logic

---

## Flood Fill Algorithm

Implements the classic paint bucket/flood fill functionality.

### Files

* `flood_fill.c`
* `flood_fill.h`

Responsibilities:

* Region detection
* Recursive/iterative fill operations
* Color replacement logic

---

## File I/O

Responsible for reading and writing image data.

### Files

* `file_io.c`
* `file_io.h`

Responsibilities:

* Loading images
* Saving edited output
* File handling

---

## GUI Layer

Provides graphical interaction and GUI abstraction.

### Files

* `gui.c`
* `gui.h`
* `gui_caller.c`
* `gui_caller_fallback.c`

Responsibilities:

* Rendering
* Event handling
* GUI abstraction and fallback support

---

# Technologies Used

* **C** – Core application development
* **Makefile** – Build automation
* **Shell scripting** – Utility and conversion scripts
* **Python** – Supporting utilities/testing

---

# Building the Project

## Clone the Repository

```bash
git clone https://github.com/Anch19/PixelPaint.git
cd Paint
```

## Build

```bash
make
```

## Run

```bash
./paint
```

> Note: Executable name may vary depending on the Makefile configuration.

---

# Example Workflow

1. Open an image
2. Apply edits or flood fill operations
3. Save the modified image
4. Verify output using test assets

---

# Learning Outcomes

This project was developed to strengthen understanding of:

* Low-level programming in C
* Dynamic memory management
* Modular code organization
* File handling and parsing
* Algorithm implementation
* GUI integration in native applications
* Collaborative development using Git and GitHub

---

# Future Improvements

Potential future enhancements include:

* Additional drawing tools
* Undo/redo system
* Multi-format image support
* Improved GUI experience
* Performance optimization for large images
* Advanced filters and transformations



# Author

**Antriksh Chaudhary**


