	add_library(catalog catalog.cc catalog.h)
	target_link_libraries(catalog PUBLIC persons)
	target_include_directories(catalog PUBLIC ${CMAKE_CURRENT_LIST_DIR})
	add_executable(catalog-main catalog-main.cc)
	target_link_libraries(catalog-main PUBLIC catalog persons)
	
	
	
