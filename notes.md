## Docker: Images and Linux distros
    gcc:12-bookworm
        base image with Debian 12 bookworm distro
        has GCC 12 already installed
        use for compilation in multi-stage build
    
    debian:bookworm-slim
        lightweight base image with Debian 12 bookworm distro
        must install libstdc++6 to link against
        use for runtime in multi-stage build

    debian
        more standard linux distro
        uses glibc libc and GNU
    alpine
        very lightweight linux distro
        uses musl libc and BusyBox
            not compatible with glbic builds

## Docker: commands
    docker build -t grow-array:dev .

    docker run grow-array:dev
    docker run --rm grow-array:dev