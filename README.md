# Crawler
### About
Crawler is a library which simplifies the process of writing web-crawlers.  
It provides a modern application programming interface  
using classes and event-based callbacks. It can be used to write  
applications which populate databases for search engines like Google Search or Microsoft Bing.  

### Supported Protocols
*	HTTP 1.0  
*	HTTP 1.1  
*	any other protocol can be easily integrated  

### Future
*	Protocol Support
	* HTTP 2.0
	* HTTPS
	* FTP
*	Event System
	* More events
	* More flexible
	* More extendable
*	Worker
	* Better synchronization
	* More perfomance

### Tested Operating Systems
*	Debian (Stretch and Jessie)
*	Ubuntu (15.04 LTS and 14.04.2 LTS)
*	Fedora (22, 21 and 20)
*	CentOS 7
*	Arch Linux
*	Mac OSX
  
### Directories
*   CMake - cmake script  
*   Documentation - documentation files  
	* Documentation/html - html documentation  
	* Documentation/man - man documentation  
	* Documentation/latex - latex documentation  
	* Documentation/rtf - rtf documentation  
*   Documents - important documents  
    * Documents/Templates - document templates provided by the instructor  
    * Documents/Presentations - presentations  
    * Documents/Charts - charts used to design the library  
*   Source - source code files  
	*   Source/Crawler - library  
	*   Source/Example - example crawler without any funtionality  
	*   Source/Email - email crawler which fetches all email addresses from a website  
	*   Source/GlobalLinkDirectory - example crawler which creates a directory of all used links from a website  
	*   Source/LocalLinkDirectory - example crawler which creates a directory of only local links from a website  
*   Tests - simple unit tests  

### CMake
*	Console  
	* cd $ROOT  
	* mkdir Build  
	* cd Build  
	* cmake ../CMake  
*	GUI  
	* Where is the source code: "$ROOT/CMake"  
	* Where to build the binaries: "$ROOT/Build"  
	* Configure  
	* Generate  

### Dependencies
[SFML](http://sfml-dev.org/ "SFML")  
[pugixml](http://pugixml.org/ "pugixml")  
[uriparser](http://uriparser.sourceforge.net/ "uriparser")  

### Installing Dependencies
* Mac OSX  
	* brew install sfml  
	* brew install uriparser  
* Debian and Ubuntu  
	* apt-get install libsfml-dev  
	* apt-get install liburiparser-dev  
* Fedora and CentOS  
	* yum install SFML-devel  
	* yum install uriparser-devel  
* Arch Linux  
	* pacman -S sfml  
	* pacman -S uriparser  
  
### Team
Josephine Lipkin  
Justus Flerlage  
