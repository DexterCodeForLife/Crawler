cmake_minimum_required ( VERSION 2.8 )
project ( Crawler )

add_definitions ( -std=c++11 )

include_directories ( ${CMAKE_CURRENT_LIST_DIR}/../Source )

#find_library ( SFML_LIBRARY NAMES sfml-system sfml-network )
#find_library ( URIPARSER_LIBRARY NAMES uriparser )

file ( GLOB_RECURSE CRAWLER_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Crawler/*" )
file ( GLOB_RECURSE EXAMPLE_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Example/*" )

add_library ( crawler ${CRAWLER_SOURCE} )
target_link_libraries ( crawler sfml-system sfml-network uriparser )

add_executable ( example ${EXAMPLE_SOURCE} )
target_link_libraries ( example crawler )
