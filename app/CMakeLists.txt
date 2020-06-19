add_library( native-lib SHARED src/main/cpp/native-lib.cpp src/main/cpp/sha1.cpp)

target_link_libraries(native-lib
                      android
                      log)