# adapted from
# http://www.mail-archive.com/cmake@cmake.org/msg18139.html

if (NOT WIN32)
    # use pkg-config to get the directories and then use these values
    # in the FIND_PATH() and FIND_LIBRARY() calls
    find_package( PkgConfig REQUIRED )
    pkg_check_modules( _sigx2  REQUIRED sigx-2.0 )
endif (NOT WIN32)

# find sigx/
find_path( LibSigX2_sigx_h_DIR sigx/sigx.h
    PATHS ${_sigx2_INCLUDE_DIRS}
    PATH_SUFFIXES sigx-2.0
    DOC "Include directory for sigc++ extension header sigx.h"
)

# find sigc++config.h
find_path( LibSigX2_sigxconfig_h_DIR sigxconfig.h
    PATHS ${_sigx2_INCLUDE_DIRS}
    DOC "Include directory for sigc++ extension config sigxconfig.h"
)


# combine the two paths
set( LibSigX2_INCLUDE_DIRS 
    ${LibSigX2_sigx_h_DIR} 
    ${LibSigX2_sigxconfig_h_DIR} 
)

# find the sigx-2.0 library
find_library( LibSigX2_LIBRARIES
  NAMES sigx-2.0 ${_sigx2_LIBRARIES}
  PATHS ${_sigx2_LIBRARY_DIRS}
  DOC "Libraries for libsigc++ extensions sigx-2.0"
  )

# let find_package_handle_standard_args handle all the boilerplate stuff
include( FindPackageHandleStandardArgs )
find_package_handle_standard_args(
    LibSigX2 LibSigX2_LIBRARIES 
    LibSigX2_sigx_h_DIR LibSigX2_sigxconfig_h_DIR
)

# mark these cache entries as advanced
mark_as_advanced( 
    LibSigX2_LIBRARIES LibSigX2_sigx_h_DIR
    LibSigX2_sigxconfig_h_DIR LibSigX2_INCLUDE_DIR
)

