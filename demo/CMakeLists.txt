set(Main
    Main.cpp
)

add_executable(MailSender
    ${Main}
)

target_link_libraries(MailSender
    SimpleMail${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Core
)
