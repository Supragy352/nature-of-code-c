FROM gcc:latest AS builder

RUN apt-get update && \
	apt-get install -y cmake git \
	libg11-mesa-dev libx11-dev libxcursor-dev libxrandr-dev libxi-dev

WORKDIR /app

COPY . .

RUN cmake -S . -B build && \
	cmake --build build

FROM debian:bookworm-slim

