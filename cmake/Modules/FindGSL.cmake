# - Try to find GSL 
# Once done, this will define
#
#  GSL_FOUND        - system has GSL
#  GSL_INCLUDE_DIRS - the GSL include directories
#  GSL_LIBRARIES    - link these to use GSL

include(LibFindMacros)

# Dependencies
# gsl has none as far as I know, but this is how you'd do it if it needed
# Glib
# libfind_package(GSL Glib)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(GSL_PKGCONF gsl)

# Main include dir
find_path(GSL_INCLUDE_DIR
  NAMES gsl/gsl_blas.h
  PATHS ${GSL_PKGCONF_INCLUDE_DIRS}
  PATH_SUFFIXES 
)

# Find the library
find_library(GSL_LIBRARY
  NAMES gsl
  PATHS ${GSL_PKGCONF_LIBRARY_DIRS}
)

find_library(GSL_CBLAS_LIBRARY
  NAMES gslcblas
  PATHS ${GSL_PKGCONF_LIBRARY_DIRS}
)

find_library(GSL_M_LIBRARY NAMES m)



# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(GSL_PROCESS_INCLUDES GSL_INCLUDE_DIR)
set(GSL_PROCESS_LIBS GSL_LIBRARY GSL_CBLAS_LIBRARY GSL_M_LIBRARY)
libfind_process(GSL)

