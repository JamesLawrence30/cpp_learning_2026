FROM gcc:12-bookworm AS builder
WORKDIR /app

COPY include/ include/
COPY src/ src/

RUN g++ -std=c++20 -O2 -Wall \
    -I include src/*.cpp \
    -o /usr/local/bin/grow_array

FROM debian:bookworm-slim AS runtime

RUN apt-get update \
    && apt-get install -y --no-install-recommends libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /usr/local/bin/grow_array /usr/local/bin/grow_array

ENTRYPOINT ["/usr/local/bin/grow_array"]