find_package(LibRSVG)
find_package(Cairo)

if( LibRSVG_FOUND AND Cairo_FOUND )
    message( "found librsvg and cairo, configuring for build" )
    include_directories( 
        ${LibRSVG_INCLUDE_DIRS} 
        ${Cairo_INCLUDE_DIRS} )
    
    set(LIBS ${LIBS} 
        ${LibRSVG_LIBRARIES} 
        ${Cairo_LIBRARIES} )
    
    add_executable(svg2pdf svg2pdf.c)
    target_link_libraries(svg2pdf ${LIBS})
    
    add_executable(svg2eps svg2eps.c)
    target_link_libraries(svg2eps ${LIBS})
    
    install(TARGETS svg2pdf svg2eps
        RUNTIME DESTINATION bin )
else( LibRSVG_FOUND AND Cairo_FOUND )
    message( "failed to find librsvg or cairo, configring for doxygen only" )
endif( LibRSVG_FOUND AND Cairo_FOUND )