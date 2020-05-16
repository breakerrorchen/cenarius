#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CURL::libcurl" for configuration "MinSizeRel"
set_property(TARGET CURL::libcurl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(CURL::libcurl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/libcurl.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS CURL::libcurl )
list(APPEND _IMPORT_CHECK_FILES_FOR_CURL::libcurl "${_IMPORT_PREFIX}/lib/libcurl.a" )

# Import target "CURL::curl" for configuration "MinSizeRel"
set_property(TARGET CURL::curl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(CURL::curl PROPERTIES
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/curl.app/Contents/MacOS/curl"
  )

list(APPEND _IMPORT_CHECK_TARGETS CURL::curl )
list(APPEND _IMPORT_CHECK_FILES_FOR_CURL::curl "${_IMPORT_PREFIX}/bin/curl.app/Contents/MacOS/curl" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
