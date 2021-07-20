# STarTeX
Small GUI made for learning purposes and because 
I was a bit bored of always forgetting the name 
of the package I'm looking for, therfore this  is
what I told myself to justify learning Qt.

I'll keep improving the GUI as well as implementing 
more functionality and making releases for more 
platforms and maybe even different build systems, 
but this remains just a secondary project for me.

## Usage
1. Start the executable.
2. Select the TeX packages you will need or think will 
come in handy.
3. Click on generate document.
4. Get the files from `/generated` and compile 
them with TeX to find a functional example of all the 
packages you asked for.

## Build process
This should be very straightforward as I haven't 
altered anything from the qMake file, just use QtCreator
> I used QtCreator 4.15 Community edition

## Planned features
- [x] Basic application with some common configurations
- [x] Test responsive UI
- [ ] Generate examples for the packages
- [x] Release for Win32
- [ ] Configure a minimum window size
- [ ] Release for Unix like systems
- [ ] Support for more packages
- [ ] Support for bibliographies
- [ ] Add scroll area to each window
- [ ] Using templates for different types of documents