#pragma once

#if defined ( _WIN32 ) || defined ( __WIN32__ )
#	ifdef CRAWLER_COMPILING
#		define CRAWLER_API __declspec ( dllexport )
#	else
#		define CRAWLER_API __declspec ( dllimport )
#	endif
#	ifdef _MSC_VER
#		pragma warning(disable : 4251)
#	endif
#else
#	if __GNUC__ >= 4
#		define CRAWLER_API __attribute__ ((__visibility__ ("default")))
#	else
#		define CRAWLER_API
#	endif
#endif
