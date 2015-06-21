cmake_minimum_required ( VERSION 2.8 )
project ( Crawler )

add_definitions ( -std=c++11 )

include_directories ( ${CMAKE_CURRENT_LIST_DIR}/../Source )

file ( GLOB_RECURSE CRAWLER_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Crawler/*" )
add_library ( crawler ${CRAWLER_SOURCE} )
target_link_libraries ( crawler sfml-system sfml-network uriparser )

file ( GLOB_RECURSE EXAMPLE_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Example/*" )
add_executable ( example ${EXAMPLE_SOURCE} )
target_link_libraries ( example crawler )

file ( GLOB_RECURSE LOCAL_LINK_DIRECTORY_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/LocalLinkDirectory/*" )
add_executable ( locallinkdirectory ${LOCAL_LINK_DIRECTORY_SOURCE} )
target_link_libraries ( locallinkdirectory crawler )

file ( GLOB_RECURSE GLOBAL_LINK_DIRECTORY_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/GlobalLinkDirectory/*" )
add_executable ( globallinkdirectory ${GLOBAL_LINK_DIRECTORY_SOURCE} )
target_link_libraries ( globallinkdirectory crawler )

file ( GLOB_RECURSE EMAIL_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Email/*" )
add_executable ( email ${EMAIL_SOURCE} )
target_link_libraries ( email crawler )
