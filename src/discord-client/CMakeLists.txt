
# Source Files
file(GLOB discord_client_sources *.cpp)
file(GLOB discord_client_headers ../../include/discord-client/*.hpp)

### Project Settings
add_library(discord-client STATIC ${discord_client_sources} ${discord_client_headers})

assign_source_group(${discord_client_sources})
assign_source_group(${discord_client_headers})
